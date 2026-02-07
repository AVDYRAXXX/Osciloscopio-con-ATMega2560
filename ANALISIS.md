# Análisis de adquisición, almacenamiento y procesamiento (ATmega2560 + SSD1306)

## 📁 Ideas clave
- **Ventana fija de 108 muestras = ancho útil del gráfico** (108×47), sin re-muestreo adicional.
- **Estrategia “adquirir → procesar → renderizar”** para desacoplar timing del ADC y del OLED.
- **Preferir enteros**: el AVR no tiene FPU, así que el fixed‑point ahorra CPU y jitter.
- **Acumuladores incrementales** (min, max, suma, suma de cuadrados) en una sola pasada.
- **Compresión a 8 bits** para la traza (si el objetivo es visual), manteniendo 10 bits para métricas si hace falta.
- **Buffer lineal** para ventana estática; **buffer circular** para modo “rolling”.
- **RMS/dB**: calcular fuera del loop crítico, con LUT o aproximación si se requiere velocidad.

## 📄 Resumen de análisis
La opción más eficiente y simple es usar **un arreglo lineal de 108 muestras**, calcular min/max/suma/suma de cuadrados en la misma adquisición y luego escalar a 0–47 px para dibujar. Para el ATmega2560, el **fixed‑point** es ideal: mantiene CPU estable, consume menos flash y evita latencias impredecibles. Solo se recomienda usar `float` para dB si la precisión requerida lo justifica y se hace **después** de capturar la ventana. Esta estrategia minimiza RAM, mantiene el ciclo de muestreo limpio y permite una forma de onda nítida conectando puntos.

## 🧠 Razonamiento y comparación detallada

### 1) Lluvia de ideas técnica (estructuras posibles)
- **Array fijo de 108 muestras** (`uint8_t`/`uint16_t`).
- **Buffer circular** con índice de escritura y lectura para desplazamiento continuo.
- **Struct de señal** que agrupe muestras + métricas.
- **Procesamiento incremental** (sin buffer) cuando solo importan las estadísticas.
- **Doble buffer** para evitar tearing entre adquisición y render.
- **Compresión** de 10 → 8 bits para gráficos, manteniendo métricas con 10 bits.

### 2) Comparación detallada (con foco en RAM/CPU)

#### Arrays clásicos
**Ventajas**:
- Acceso directo y mínimo overhead.
- Render inmediato (x = índice) y depuración simple.
- RAM predecible: 108×1 B (8 bits) o 108×2 B (10 bits en `uint16_t`).

**Desventajas**:
- Para modo continuo, hay que reiniciar o copiar si se quiere “scroll”.

**Mejor uso**: ventana estática o adquisiciones periódicas.

#### Buffers circulares
**Ventajas**:
- Adquisición continua sin copiar datos.
- Ideal para modo “rolling” o trigger repetitivo.

**Desventajas**:
- Lógica adicional para ordenar la lectura.
- Render requiere conversión de índices circulares a lineales.

**Mejor uso**: osciloscopio con desplazamiento horizontal continuo.

#### Structs de señales
**Ventajas**:
- Encapsula datos + métricas (min, max, RMS, etc.).
- Escalable a múltiples canales.

**Desventajas**:
- Leve complejidad extra si solo hay un canal.

**Mejor uso**: arquitectura limpia y extensible.

#### Procesamiento incremental
**Ventajas**:
- Estadísticas en una sola pasada.
- Baja RAM y coste fijo por muestra.

**Desventajas**:
- Sin buffer no hay forma de onda.

**Mejor uso**: siempre como complemento al buffer de dibujo.

#### Fixed‑point vs float
**Fixed‑point**:
- Más rápido en AVR, menor flash y consumo estable.
- Fácil de mantener un tiempo de muestreo regular.

**Float**:
- Más simple para dB y RMS “directos”.
- Costoso en CPU y flash, puede introducir jitter.

**Recomendación**: fixed‑point para todo el camino crítico; `float` solo si se calcula dB fuera del ciclo de adquisición y es imprescindible.

## ✅ Recomendación final (justificada)
1. **Arreglo lineal de 108 muestras** (ventana fija): simple y perfecto para 108 px de ancho.
2. **Métricas incrementales** (min, max, suma, suma de cuadrados) durante la adquisición.
3. **Escalado entero** a 0–47 px con saturación.
4. **RMS y dB** en fixed‑point o LUT; si se usa `float`, hacerlo posterior a la captura.

**Por qué**: este flujo usa poca RAM, evita cálculos caros dentro del muestreo y mantiene el código comprensible.

## 💻 Ejemplos en C/C++ (Arduino)

### Estructuras de datos (con métricas integradas)
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

### Adquisición + métricas incrementales
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

### Escalado entero a 0–47 px
```cpp
uint8_t scaleToY(uint16_t v, uint16_t minV, uint16_t maxV) {
  if (maxV == minV) return Y_MAX / 2;
  uint32_t num = (uint32_t)(v - minV) * Y_MAX;
  uint32_t den = (maxV - minV);
  return (uint8_t)(num / den);
}
```

### Promedio y RMS (enteros)
```cpp
uint16_t meanQ0(const SignalWindow &w) {
  return (uint16_t)(w.sum / N_SAMPLES);
}

uint16_t rmsQ0(const SignalWindow &w) {
  uint32_t meanSq = w.sumSq / N_SAMPLES;
  // sqrt entero; reemplazar por implementación rápida si se desea
  return (uint16_t)sqrt((double)meanSq);
}
```

### dB con fixed‑point (ejemplo simple)
```cpp
// dB = 20 * log10(rms / ref). Usar LUT si se requiere velocidad.
// Aquí se deja la API preparada para reemplazar el log10.
int16_t dbQ8(uint16_t rms, uint16_t ref) {
  if (rms == 0 || ref == 0) return -32768; // -inf
  // Placeholder: convertir a float fuera del loop crítico
  float db = 20.0f * log10f((float)rms / (float)ref);
  return (int16_t)(db * 256.0f); // Q8
}
```

### Graficado (conexión de puntos)
```cpp
for (uint8_t x = 0; x < N_SAMPLES - 1; x++) {
  uint8_t y1 = Y_MAX - scaleToY(w.samples[x], w.minVal, w.maxVal);
  uint8_t y2 = Y_MAX - scaleToY(w.samples[x + 1], w.minVal, w.maxVal);
  display.drawLine(x, y1, x + 1, y2, SSD1306_WHITE);
}
```

## 🧩 Mejoras propuestas sobre lo subido
- **Separar adquisición y render** en funciones explícitas para controlar timing.
- **Mantener 10 bits para métricas y 8 bits para render** si se quiere ahorrar RAM en el buffer de gráfico.
- **Introducir LUT para log10** si el dB debe calcularse en tiempo real.
- **Opcional**: usar ADC en modo free‑running con interrupción para muestreo más uniforme.

---

Si quieres, puedo ajustar el documento con un pipeline de muestreo basado en Timer + ADC free‑running o incluir una LUT real para `log10`.
