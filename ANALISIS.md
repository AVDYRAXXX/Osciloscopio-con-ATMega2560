# Análisis de adquisición, almacenamiento y procesamiento (ATmega2560 + SSD1306)

## 📁 Ideas clave
- **Ventana fija de 108 muestras** para dibujar 1:1 en el área gráfica (108×47).  
- **Conversión ADC a 8 bits** (o 9–10 bits con compresión) para minimizar RAM sin perder detalle visual.  
- **Escalado vertical con saturación y mapeo entero** para 0–47 px, evitando `float`.  
- **Cálculo incremental** (min, max, suma y suma de cuadrados) para reducir CPU y RAM.  
- **RMS y dB en fixed‑point**, usando aproximaciones o LUT para `log10` si se requiere.  
- **Buffer lineal** simple cuando el objetivo es mostrar una sola ventana; **buffer circular** si se desea “rolling” continuo.  
- **Separar la capa de adquisición de la de render** para simplificar y aislar la temporización.  

## 📄 Resumen de análisis
La estrategia más eficiente para un ATmega2560 con pantalla SSD1306 es capturar **108 muestras en un arreglo lineal**, almacenar cada muestra en **`uint8_t` o `uint16_t` comprimido**, y calcular estadísticas con **procesamiento incremental** (min, max, suma, suma de cuadrados). Luego se escala a 0–47 para graficar y se trazan líneas entre puntos. Esta solución minimiza RAM, evita `float` en el ciclo crítico y mantiene el código simple. Se recomienda usar **fixed‑point** para RMS/dB y reservar `float` solo si la precisión requerida lo justifica, dado el costo en CPU y flash.  

## 🧠 Razonamiento y comparación detallada

### 1) Lluvia de ideas técnica (estructuras posibles)
- **Array fijo de 108 muestras** (`uint8_t`/`uint16_t`).
- **Buffer circular** con índice de escritura y lectura para “scroll” continuo.
- **Struct de señal** que agrupe muestras + metadatos (min, max, suma, etc.).
- **Procesamiento incremental** (acumuladores) sin almacenar todo (si solo se requiere estadísticas, no forma de onda).
- **Compresión de muestras** (mapear 10 bits a 8 bits para gráfico).
- **Doble buffer** (uno para adquisición, otro para render) para evitar tearing.

### 2) Comparación detallada

#### Arrays clásicos
**Ventajas**:
- Acceso directo, mínimo overhead.
- Sencillo para trazar puntos 1:1 en pantalla.
- Fácil de depurar.

**Desventajas**:
- Para flujo continuo hay que hacer corrimientos o reinicios.

**Cuándo usar**: capturar una ventana de 108 muestras y dibujarla completa.

#### Buffers circulares
**Ventajas**:
- Permite adquisición continua sin copiar datos.
- Útil si se quiere scroll o trigger continuo.

**Desventajas**:
- Más lógica (índices modulo, sincronización con render).
- Orden de lectura requiere convertir índice circular a lineal.

**Cuándo usar**: visualización en tiempo real con desplazamiento horizontal.

#### Structs de señales
**Ventajas**:
- Encapsula datos + métricas en una sola entidad.
- Hace explícito el estado de la señal.

**Desventajas**:
- Ligera sobrecarga de complejidad.

**Cuándo usar**: cuando se requiere extensibilidad o varias señales.

#### Procesamiento incremental
**Ventajas**:
- Reduce memoria y CPU en post‑proceso.
- Facilita calcular min, max, promedio, RMS en una sola pasada.

**Desventajas**:
- Si no se guardan muestras, no se puede dibujar la forma de onda.

**Cuándo usar**: siempre como complemento; imprescindible para estadísticas rápidas.

#### Fixed‑point vs float
**Fixed‑point**:
- Más rápido y predecible en AVR (sin FPU).
- Menor consumo de flash y CPU.

**Float**:
- Más simple para cálculos complejos (RMS, dB).
- Alto costo de CPU, posible jitter en tiempo real.

**Recomendación**: usar fixed‑point en adquisición y escalado; usar float **solo** fuera del loop crítico si la precisión de dB lo requiere.

### 3) Recomendación final justificada
- **Estructura principal**: arreglo lineal de 108 muestras (`uint8_t` o `uint16_t` si se necesita resolución extra).
- **Cálculos**: min, max, suma, suma de cuadrados en una pasada (incremental).
- **Escalado**: mapeo entero a 0–47 para graficar (rápido y estable).
- **RMS/dB**: fixed‑point con un factor de escala; `log10` aproximado con LUT o, si se permite, calculado en float **después** de adquirir la ventana.
- **Justificación**: logra baja RAM, CPU estable y código simple. El array lineal es suficiente para 108 muestras y la conversión a gráfico es directa.

## 💻 Ejemplos en C/C++ (Arduino)

### Estructuras de datos
```cpp
#define N_SAMPLES 108
#define Y_MAX 47

struct SignalWindow {
  uint16_t samples[N_SAMPLES]; // 10-bit ADC sin comprimir
  uint16_t minVal;
  uint16_t maxVal;
  uint32_t sum;
  uint32_t sumSq; // sumatoria de cuadrados
};
```

### Adquisición y procesamiento incremental
```cpp
void acquireWindow(SignalWindow &w) {
  w.minVal = 1023;
  w.maxVal = 0;
  w.sum = 0;
  w.sumSq = 0;

  for (uint8_t i = 0; i < N_SAMPLES; i++) {
    uint16_t v = analogRead(A0); // 10 bits
    w.samples[i] = v;
    if (v < w.minVal) w.minVal = v;
    if (v > w.maxVal) w.maxVal = v;
    w.sum += v;
    w.sumSq += (uint32_t)v * v;
  }
}
```

### Escalado a 0–47 para graficar
```cpp
uint8_t scaleToY(uint16_t v, uint16_t minV, uint16_t maxV) {
  if (maxV == minV) return Y_MAX / 2;
  // Escala entero: (v - min) * Y_MAX / (max - min)
  uint32_t num = (uint32_t)(v - minV) * Y_MAX;
  uint32_t den = (maxV - minV);
  return (uint8_t)(num / den);
}
```

### Cálculo de promedio, RMS y dB (fixed‑point simple)
```cpp
uint16_t meanQ0(const SignalWindow &w) {
  return (uint16_t)(w.sum / N_SAMPLES);
}

uint16_t rmsQ0(const SignalWindow &w) {
  // RMS entero aproximado
  uint32_t meanSq = w.sumSq / N_SAMPLES;
  // sqrt entero (ej. función rápida o aproximación)
  return (uint16_t)sqrt((double)meanSq); // reemplazar por sqrt entero si se desea
}
```

### Ejemplo de graficado (pseudocódigo con SSD1306)
```cpp
for (uint8_t x = 0; x < N_SAMPLES - 1; x++) {
  uint8_t y1 = Y_MAX - scaleToY(w.samples[x], w.minVal, w.maxVal);
  uint8_t y2 = Y_MAX - scaleToY(w.samples[x+1], w.minVal, w.maxVal);
  display.drawLine(x, y1, x+1, y2, SSD1306_WHITE);
}
```

---

Si necesitas incluir optimización con LUT de `log10`, o trigger y sincronización con timer/ADC en modo free‑running, puedo extender el diseño.
