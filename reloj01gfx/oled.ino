String line0;
String line1;
String line2;
String line3;
String line4;
String line5;
String line6;
String line7;

int num = 0;

void initOled() {
  Wire.begin();
  Wire.setClock(800000);
  Serial.begin(115200);
  display.setTextColor(INVERSE); 


  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) {
    while (1)
      ;  // si falla, se queda aquí
  }


  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Hola OLED!");

  display.display();  // ENVÍA el buffer
}

void terminaln(String s){
  line7=line6;
  line6=line5;
  line5=line4;
  line4=line3;
  line3=line2;
  line2=line1;
  line1=line0;
  line0=String(String(num++, DEC) + String(" ") + String(s));

  display.clearDisplay();
  display.setCursor(0,0);
  display.println(String(line0));
  display.println(String(line1));
  display.println(String(line2));
  display.println(String(line3));
  display.println(String(line4));
  display.println(String(line5));
  display.println(String(line6));
  display.println(String(line7));
  display.display();
}

//static const unsigned char PROGMEM MarcoReloj[]{ 0, 0, 0, 0, 0, 127, 255, 0, 1, 255, 127, 192, 3, 128, 0, 224, 15, 65, 192, 120, 10, 96, 131, 168, 28, 64, 1, 28, 56, 0, 0, 14, 48, 0, 0, 22, 110, 0, 0, 51, 100, 0, 0, 19, 96, 0, 0, 3, 96, 0, 0, 3, 96, 0, 0, 3, 96, 1, 192, 3, 104, 3, 96, 11, 76, 2, 160, 25, 104, 3, 96, 11, 96, 1, 192, 3, 96, 0, 0, 3, 96, 0, 0, 3, 96, 0, 0, 3, 100, 0, 0, 19, 110, 0, 0, 51, 48, 0, 0, 22, 56, 0, 0, 14, 28, 64, 1, 28, 10, 96, 131, 168, 15, 65, 192, 120, 3, 128, 0, 224, 1, 255, 127, 192, 0, 127, 255, 0 };
void _MarcoReloj(uint8_t x, uint8_t y) {
  //display.drawBitmap(x, y, MarcoReloj, 32, 31, WHITE, BLACK);
  display.setCursor(x, y);
  display.drawCircle(x + 15, y + 15, 15, WHITE);

  display.setCursor(x, y);
  display.drawCircle(x + 15, y + 15, 14, WHITE);
}

static const unsigned char PROGMEM hr00[]{ 32, 80, 112, 112, 112, 112, 112, 112, 216, 168, 216, 112 };
void _hr00(uint8_t x, uint8_t y) {
  x += 13;
  y += 6;
  display.drawBitmap(x, y, hr00, 8, 12, WHITE);
}

static const unsigned char PROGMEM hr06[]{ 112, 216, 168, 216, 112, 112, 112, 112, 112, 112, 80, 32 };
void _hr06(uint8_t x, uint8_t y) {
  x += 13;
  y += 13;
  display.drawBitmap(x, y, hr06, 8, 12, WHITE);
}

static const unsigned char PROGMEM hr01[]{ 7, 5, 14, 14, 28, 28, 120, 216, 168, 216, 112 };
void _hr01(uint8_t x, uint8_t y) {
  x += 13;
  y += 7;
  display.drawBitmap(x, y, hr01, 8, 11, WHITE);
}

static const unsigned char PROGMEM hr07[]{ 14, 27, 21, 27, 30, 56, 56, 112, 112, 160, 224 };
void _hr07(uint8_t x, uint8_t y) {
  x += 10;
  y += 13;
  display.drawBitmap(x, y, hr07, 8, 11, WHITE);
}








void testDisco(uint16_t x = 1) {

  display.clearDisplay();
  display.drawPixel(64, 32, WHITE);
  display.drawPixel(65, 32, WHITE);
  display.drawPixel(65, 33, WHITE);
  display.drawPixel(64, 33, WHITE);
  display.drawLine(64, 32, 0, 31, WHITE);
  delay(x);
  display.drawLine(64, 33, 0, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 32, 0, 16, WHITE);
  delay(x);
  display.drawLine(64, 33, 0, 48, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 32, 0, 15, WHITE);
  delay(x);
  display.drawLine(64, 33, 0, 47, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 32, 0, 0, WHITE);
  delay(x);
  display.drawLine(64, 33, 0, 32, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 32, 15, 0, WHITE);
  delay(x);
  display.drawLine(64, 32, 0, 31, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 32, 16, 0, WHITE);
  delay(x);
  display.drawLine(64, 32, 0, 16, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 32, 31, 0, WHITE);
  delay(x);
  display.drawLine(64, 32, 0, 15, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 32, 32, 0, WHITE);
  delay(x);
  display.drawLine(64, 32, 0, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 32, 47, 0, WHITE);
  delay(x);
  display.drawLine(64, 32, 15, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 32, 48, 0, WHITE);
  delay(x);
  display.drawLine(64, 32, 16, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 32, 63, 0, WHITE);
  delay(x);
  display.drawLine(64, 32, 31, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 32, 64, 0, WHITE);
  delay(x);
  display.drawLine(64, 32, 32, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 32, 79, 0, WHITE);
  delay(x);
  display.drawLine(64, 32, 47, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 32, 80, 0, WHITE);
  delay(x);
  display.drawLine(64, 32, 48, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 32, 95, 0, WHITE);
  delay(x);
  display.drawLine(64, 32, 63, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 32, 96, 0, WHITE);
  delay(x);
  display.drawLine(65, 32, 64, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 32, 111, 0, WHITE);
  delay(x);
  display.drawLine(65, 32, 79, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 32, 112, 0, WHITE);
  delay(x);
  display.drawLine(65, 32, 80, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 32, 127, 0, WHITE);
  delay(x);
  display.drawLine(65, 32, 95, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 32, 127, 15, WHITE);
  delay(x);
  display.drawLine(65, 32, 96, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 32, 127, 16, WHITE);
  delay(x);
  display.drawLine(65, 32, 111, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 32, 127, 31, WHITE);
  delay(x);
  display.drawLine(65, 32, 112, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 33, 127, 32, WHITE);
  delay(x);
  display.drawLine(65, 32, 127, 0, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 33, 127, 47, WHITE);
  delay(x);
  display.drawLine(65, 32, 127, 15, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 33, 127, 48, WHITE);
  delay(x);
  display.drawLine(65, 32, 127, 16, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 33, 127, 63, WHITE);
  delay(x);
  display.drawLine(65, 32, 127, 31, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 33, 112, 63, WHITE);
  delay(x);
  display.drawLine(65, 33, 127, 32, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 33, 111, 63, WHITE);
  delay(x);
  display.drawLine(65, 33, 127, 47, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 33, 96, 63, WHITE);
  delay(x);
  display.drawLine(65, 33, 127, 48, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 33, 95, 63, WHITE);
  delay(x);
  display.drawLine(65, 33, 127, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 33, 80, 63, WHITE);
  delay(x);
  display.drawLine(65, 33, 112, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 33, 79, 63, WHITE);
  delay(x);
  display.drawLine(65, 33, 111, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(65, 33, 64, 63, WHITE);
  delay(x);
  display.drawLine(65, 33, 96, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 33, 63, 63, WHITE);
  delay(x);
  display.drawLine(65, 33, 95, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 33, 48, 63, WHITE);
  delay(x);
  display.drawLine(65, 33, 80, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 33, 47, 63, WHITE);
  delay(x);
  display.drawLine(65, 33, 79, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 33, 32, 63, WHITE);
  delay(x);
  display.drawLine(65, 33, 64, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 33, 31, 63, WHITE);
  delay(x);
  display.drawLine(64, 33, 63, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 33, 16, 63, WHITE);
  delay(x);
  display.drawLine(64, 33, 48, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 33, 15, 63, WHITE);
  delay(x);
  display.drawLine(64, 33, 47, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 33, 0, 63, WHITE);
  delay(x);
  display.drawLine(64, 33, 32, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 33, 0, 48, WHITE);
  delay(x);
  display.drawLine(64, 33, 31, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 33, 0, 47, WHITE);
  delay(x);
  display.drawLine(64, 33, 16, 63, BLACK);
  delay(x);
  display.display();
  display.drawLine(64, 33, 0, 32, WHITE);
  delay(x);
  display.drawLine(64, 33, 15, 63, BLACK);
  delay(x);
  display.display();



  display.display();
}
void testDisco(void) {
  testDisco(1);
}

void testGrid() {

  display.clearDisplay();


  display.drawPixel(0, 0, WHITE);
  display.drawPixel(15, 0, WHITE);
  display.drawPixel(16, 0, WHITE);
  display.drawPixel(31, 0, WHITE);
  display.drawPixel(32, 0, WHITE);
  display.drawPixel(47, 0, WHITE);
  display.drawPixel(48, 0, WHITE);
  display.drawPixel(63, 0, WHITE);
  display.drawPixel(64, 0, WHITE);
  display.drawPixel(79, 0, WHITE);
  display.drawPixel(80, 0, WHITE);
  display.drawPixel(95, 0, WHITE);
  display.drawPixel(96, 0, WHITE);
  display.drawPixel(111, 0, WHITE);
  display.drawPixel(112, 0, WHITE);
  display.drawPixel(127, 0, WHITE);
  display.drawPixel(0, 15, WHITE);
  display.drawPixel(16, 15, WHITE);
  display.drawPixel(32, 15, WHITE);
  display.drawPixel(48, 15, WHITE);
  display.drawPixel(79, 15, WHITE);
  display.drawPixel(95, 15, WHITE);
  display.drawPixel(111, 15, WHITE);
  display.drawPixel(127, 15, WHITE);
  display.drawPixel(0, 16, WHITE);
  display.drawPixel(15, 16, WHITE);
  display.drawPixel(16, 16, WHITE);
  display.drawPixel(31, 16, WHITE);
  display.drawPixel(32, 16, WHITE);
  display.drawPixel(47, 16, WHITE);
  display.drawPixel(48, 16, WHITE);
  display.drawPixel(63, 16, WHITE);
  display.drawPixel(64, 16, WHITE);
  display.drawPixel(79, 16, WHITE);
  display.drawPixel(80, 16, WHITE);
  display.drawPixel(95, 16, WHITE);
  display.drawPixel(96, 16, WHITE);
  display.drawPixel(111, 16, WHITE);
  display.drawPixel(112, 16, WHITE);
  display.drawPixel(127, 16, WHITE);
  display.drawPixel(0, 31, WHITE);
  display.drawPixel(15, 31, WHITE);
  display.drawPixel(31, 31, WHITE);
  display.drawPixel(47, 31, WHITE);
  display.drawPixel(63, 31, WHITE);
  display.drawPixel(64, 31, WHITE);
  display.drawPixel(80, 31, WHITE);
  display.drawPixel(96, 31, WHITE);
  display.drawPixel(111, 31, WHITE);
  display.drawPixel(127, 31, WHITE);
  display.drawPixel(0, 32, WHITE);
  display.drawPixel(15, 32, WHITE);
  display.drawPixel(31, 32, WHITE);
  display.drawPixel(47, 32, WHITE);
  display.drawPixel(63, 32, WHITE);
  display.drawPixel(64, 32, WHITE);
  display.drawPixel(80, 32, WHITE);
  display.drawPixel(96, 32, WHITE);
  display.drawPixel(111, 32, WHITE);
  display.drawPixel(127, 32, WHITE);
  display.drawPixel(0, 47, WHITE);
  display.drawPixel(15, 47, WHITE);
  display.drawPixel(16, 47, WHITE);
  display.drawPixel(31, 47, WHITE);
  display.drawPixel(32, 47, WHITE);
  display.drawPixel(47, 47, WHITE);
  display.drawPixel(48, 47, WHITE);
  display.drawPixel(63, 47, WHITE);
  display.drawPixel(64, 47, WHITE);
  display.drawPixel(79, 47, WHITE);
  display.drawPixel(80, 47, WHITE);
  display.drawPixel(95, 47, WHITE);
  display.drawPixel(96, 47, WHITE);
  display.drawPixel(111, 47, WHITE);
  display.drawPixel(112, 47, WHITE);
  display.drawPixel(127, 47, WHITE);
  display.drawPixel(0, 48, WHITE);
  display.drawPixel(16, 48, WHITE);
  display.drawPixel(32, 48, WHITE);
  display.drawPixel(48, 48, WHITE);
  display.drawPixel(79, 48, WHITE);
  display.drawPixel(95, 48, WHITE);
  display.drawPixel(111, 48, WHITE);
  display.drawPixel(127, 48, WHITE);
  display.drawPixel(0, 63, WHITE);
  display.drawPixel(15, 63, WHITE);
  display.drawPixel(16, 63, WHITE);
  display.drawPixel(31, 63, WHITE);
  display.drawPixel(32, 63, WHITE);
  display.drawPixel(47, 63, WHITE);
  display.drawPixel(48, 63, WHITE);
  display.drawPixel(63, 63, WHITE);
  display.drawPixel(64, 63, WHITE);
  display.drawPixel(79, 63, WHITE);
  display.drawPixel(80, 63, WHITE);
  display.drawPixel(95, 63, WHITE);
  display.drawPixel(96, 63, WHITE);
  display.drawPixel(111, 63, WHITE);
  display.drawPixel(112, 63, WHITE);
  display.drawPixel(127, 63, WHITE);
}
void testPerspectiva() {
  display.clearDisplay();
  display.drawLine(0, 0, 64, 32, WHITE);
  display.display();
  display.drawLine(16, 0, 64, 32, WHITE);
  display.display();
  display.drawLine(32, 0, 64, 32, WHITE);
  display.display();
  display.drawLine(48, 0, 64, 32, WHITE);
  display.display();
  display.drawLine(64, 0, 65, 32, WHITE);
  display.display();
  display.drawLine(80, 0, 65, 32, WHITE);
  display.display();
  display.drawLine(96, 0, 65, 32, WHITE);
  display.display();
  display.drawLine(112, 0, 65, 32, WHITE);
  display.display();
  display.drawLine(127, 0, 65, 32, WHITE);
  display.display();
  display.drawLine(0, 15, 64, 32, WHITE);
  display.display();
  display.drawLine(127, 16, 65, 32, WHITE);
  display.display();
  display.drawLine(0, 31, 64, 32, WHITE);
  display.display();
  display.drawLine(127, 32, 65, 33, WHITE);
  display.display();
  display.drawLine(0, 47, 64, 33, WHITE);
  display.display();
  display.drawLine(127, 48, 65, 33, WHITE);
  display.display();
  display.drawLine(0, 63, 64, 33, WHITE);
  display.display();
  display.drawLine(15, 63, 64, 33, WHITE);
  display.display();
  display.drawLine(31, 63, 64, 33, WHITE);
  display.display();
  display.drawLine(47, 63, 64, 33, WHITE);
  display.display();
  display.drawLine(63, 63, 64, 33, WHITE);
  display.display();
  display.drawLine(79, 63, 65, 33, WHITE);
  display.display();
  display.drawLine(95, 63, 65, 33, WHITE);
  display.display();
  display.drawLine(111, 63, 65, 33, WHITE);
  display.display();
  display.drawLine(127, 63, 65, 33, WHITE);
  display.display();
  //display.drawEllipse(64,32,30, 15, WHITE );
  display.fillEllipse(64, 32, 30, 15, WHITE);
  display.display();
}



static const unsigned char PROGMEM cero40[] = { 0b00001111, 0b11110000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b11001111, 0b11110011, 0b11001111, 0b11110011, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11001111, 0b11110011, 0b11001111, 0b11110011, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11110000 };
void _cero40(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, cero40, 16, 40, WHITE, BLACK);
}
static const unsigned char PROGMEM uno40[] = { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000011, 0b00000000, 0b00000011, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00000011, 0b00000000, 0b00000011, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000011, 0b00000000, 0b00000011, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00000011, 0b00000000, 0b00000011, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 };
void _uno40(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, uno40, 16, 40, WHITE, BLACK);
}
static const unsigned char PROGMEM dos40[] = { 0b00001111, 0b11110000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11111100, 0b00001111, 0b11110011, 0b00001111, 0b11110011, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00001111, 0b11110011, 0b00001111, 0b11110011, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b11001111, 0b11110000, 0b11001111, 0b11110000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11001111, 0b11110000, 0b11001111, 0b11110000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11110000 };
void _dos40(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, dos40, 16, 40, WHITE, BLACK);
}
static const unsigned char PROGMEM tres40[] = { 0b00001111, 0b11110000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11110011, 0b00001111, 0b11110011, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00001111, 0b11110011, 0b00001111, 0b11110011, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11110011, 0b00001111, 0b11110011, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00001111, 0b11110011, 0b00001111, 0b11110011, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11110000 };
void _tres40(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, tres40, 16, 40, WHITE, BLACK);
}
static const unsigned char PROGMEM cuatro40[] = { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11001111, 0b11110011, 0b11001111, 0b11110011, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11110011, 0b00001111, 0b11110011, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00000011, 0b00000000, 0b00000011, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 };
void _cuatro40(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, cuatro40, 16, 40, WHITE, BLACK);
}
static const unsigned char PROGMEM cinco40[] = { 0b00001111, 0b11110000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b11001111, 0b11110000, 0b11001111, 0b11110000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11001111, 0b11110000, 0b11001111, 0b11110000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11110011, 0b00001111, 0b11110011, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00001111, 0b11110011, 0b00001111, 0b11110011, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11110000 };
void _cinco40(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, cinco40, 16, 40, WHITE, BLACK);
}
static const unsigned char PROGMEM seis40[] = { 0b00001111, 0b11110000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b11001111, 0b11110000, 0b11001111, 0b11110000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11001111, 0b11110000, 0b11001111, 0b11110000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b11001111, 0b11110011, 0b11001111, 0b11110011, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11001111, 0b11110011, 0b11001111, 0b11110011, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11110000 };
void _seis40(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, seis40, 16, 40, WHITE, BLACK);
}
static const unsigned char PROGMEM siete40[] = { 0b00001111, 0b11110000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11110011, 0b00001111, 0b11110011, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00000011, 0b00000000, 0b00000011, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000011, 0b00000000, 0b00000011, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00000011, 0b00000000, 0b00000011, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 };
void _siete40(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, siete40, 16, 40, WHITE, BLACK);
}
static const unsigned char PROGMEM ocho40[] = { 0b00001111, 0b11110000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b11001111, 0b11110011, 0b11001111, 0b11110011, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11001111, 0b11110011, 0b11001111, 0b11110011, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b11001111, 0b11110011, 0b11001111, 0b11110011, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11001111, 0b11110011, 0b11001111, 0b11110011, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11110000 };
void _ocho40(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, ocho40, 16, 40, WHITE, BLACK);
}
static const unsigned char PROGMEM nueve40[] = { 0b00001111, 0b11110000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b11001111, 0b11110011, 0b11001111, 0b11110011, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11110000, 0b00001111, 0b11001111, 0b11110011, 0b11001111, 0b11110011, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00001111, 0b11110011, 0b00001111, 0b11110011, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00000000, 0b00001111, 0b00001111, 0b11110011, 0b00001111, 0b11110011, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b0001111, 0b11110000 };
void _nueve40(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, nueve40, 16, 40, WHITE, BLACK);
}
static const unsigned char PROGMEM cero24[] = { 0b00000011, 0b11000000, 0b00001111, 0b11110000, 0b00011110, 0b01111000, 0b00011100, 0b00111000, 0b00111100, 0b00111100, 0b00111100, 0b00111100, 0b00111100, 0b00111110, 0b01111100, 0b00111110, 0b01111100, 0b00111110, 0b01111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b01111100, 0b00111110, 0b01111100, 0b00111110, 0b00111100, 0b00111110, 0b00111100, 0b00111110, 0b00111100, 0b00111100, 0b00111100, 0b00111100, 0b00011110, 0b01111000, 0b00001111, 0b11110000, 0b00000111, 0b11100000 };
void _cero24(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, cero24, 16, 24, WHITE, BLACK);
}
static const unsigned char PROGMEM uno24[] = { 0b00000000, 0b00000000, 0b00000000, 0b11000000, 0b00000001, 0b11000000, 0b00000001, 0b11000000, 0b00000011, 0b11000000, 0b00000111, 0b11000000, 0b00001111, 0b11000000, 0b00011011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000111, 0b11100000, 0b00011111, 0b11111000 };
void _uno24(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, uno24, 16, 24, WHITE, BLACK);
}
static const unsigned char PROGMEM dos24[] = { 0b00000111, 0b11110000, 0b00001111, 0b11111000, 0b00011111, 0b11111100, 0b00111111, 0b11111110, 0b00111000, 0b01111110, 0b00110000, 0b00111110, 0b01100000, 0b00111110, 0b01100000, 0b00111110, 0b00000000, 0b00111110, 0b00000000, 0b00111110, 0b00000000, 0b00111100, 0b00000000, 0b01111100, 0b00000000, 0b01111000, 0b00000000, 0b11110000, 0b00000001, 0b11100000, 0b00000011, 0b11000000, 0b00000011, 0b10000010, 0b00000111, 0b00000010, 0b00001110, 0b00000010, 0b00011111, 0b11111110, 0b00011111, 0b11111110, 0b00111111, 0b11111110, 0b00111111, 0b11111110, 0b01111111, 0b11111100 };
void _dos24(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, dos24, 16, 24, WHITE, BLACK);
}
static const unsigned char PROGMEM tres24[] = { 0b00000111, 0b11100000, 0b00001111, 0b11110000, 0b00111111, 0b11111000, 0b00110000, 0b01111100, 0b01100000, 0b00111100, 0b00000000, 0b00111100, 0b00000000, 0b00111100, 0b00000000, 0b00111100, 0b00000000, 0b01111000, 0b00000000, 0b01100000, 0b00000011, 0b11111000, 0b00000111, 0b11111100, 0b00000111, 0b11111110, 0b00000000, 0b01111110, 0b00000000, 0b00011110, 0b00000000, 0b00011111, 0b00000000, 0b00011111, 0b01110000, 0b00011111, 0b11111000, 0b00011111, 0b11111000, 0b00011110, 0b01111000, 0b00011100, 0b01111000, 0b00111000, 0b00111111, 0b11110000, 0b00001111, 0b11100000 };
void _tres24(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, tres24, 16, 24, WHITE, BLACK);
}
static const unsigned char PROGMEM cuatro24[] = { 0b00000000, 0b00110000, 0b00000000, 0b01110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000001, 0b11110000, 0b00000011, 0b01110000, 0b00000111, 0b01110000, 0b00000110, 0b01110000, 0b00001100, 0b01110000, 0b00011100, 0b01110000, 0b00011000, 0b01110000, 0b00110000, 0b01110000, 0b00110000, 0b01110000, 0b01100000, 0b01110000, 0b01111111, 0b11111111, 0b01111111, 0b11111111, 0b01111111, 0b11111111, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11110000, 0b00000000, 0b11111000, 0b00000001, 0b11111100, 0b00000111, 0b11111110, 0b00000011, 0b11111110 };
void _cuatro24(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, cuatro24, 16, 24, WHITE, BLACK);
}
static const unsigned char PROGMEM cinco24[] = { 0b00011000, 0b00001100, 0b00011111, 0b11111000, 0b00011111, 0b11111000, 0b00011111, 0b11110000, 0b00011111, 0b11000000, 0b00011000, 0b00000000, 0b00110000, 0b00000000, 0b00110000, 0b00000000, 0b00111111, 0b11100000, 0b00111111, 0b11111000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00110000, 0b00111110, 0b00100000, 0b00011110, 0b00000000, 0b00011111, 0b00000000, 0b00011111, 0b00000000, 0b00011111, 0b01110000, 0b00011110, 0b01111000, 0b00011110, 0b11111000, 0b00011110, 0b01111000, 0b00011100, 0b01111100, 0b00111000, 0b00111110, 0b11110000, 0b00011111, 0b11100000 };
void _cinco24(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, cinco24, 16, 24, WHITE, BLACK);
}
static const unsigned char PROGMEM seis24[] = { 0b00000011, 0b11110000, 0b00000111, 0b11111100, 0b00001110, 0b00111100, 0b00011110, 0b00111110, 0b00011100, 0b00111110, 0b00111100, 0b00111110, 0b00111100, 0b00001100, 0b01111100, 0b00000000, 0b01111100, 0b11110000, 0b01111101, 0b11111000, 0b11111111, 0b11111100, 0b11111110, 0b00111110, 0b11111110, 0b00111110, 0b11111100, 0b00011111, 0b11111100, 0b00011111, 0b01111100, 0b00011111, 0b01111100, 0b00011111, 0b01111100, 0b00011111, 0b00111100, 0b00011110, 0b00111100, 0b00011110, 0b00111100, 0b00011100, 0b00011110, 0b00111000, 0b00001111, 0b11110000, 0b00000111, 0b11100000 };
void _seis24(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, seis24, 16, 24, WHITE, BLACK);
}
static const unsigned char PROGMEM siete24[] = { 0b00011111, 0b11111110, 0b00111111, 0b11111110, 0b00111111, 0b11111110, 0b00111111, 0b11111100, 0b00110000, 0b00001100, 0b01100000, 0b00001100, 0b01100000, 0b00011100, 0b00000000, 0b00011000, 0b00000000, 0b00111000, 0b00000000, 0b00111000, 0b00000000, 0b01110000, 0b00000000, 0b01110000, 0b00000000, 0b01110000, 0b00000000, 0b11100000, 0b00000001, 0b11100000, 0b00000001, 0b11100000, 0b00000011, 0b11000000, 0b00000011, 0b11000000, 0b00000111, 0b11000000, 0b00000111, 0b10000000, 0b00001111, 0b10000000, 0b00001111, 0b10000000, 0b00011111, 0b00000000, 0b00011111, 0b00000000 };
void _siete24(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, siete24, 16, 24, WHITE, BLACK);
}
static const unsigned char PROGMEM ocho24[] = { 0b00000111, 0b10110000, 0b00001110, 0b01111000, 0b00111100, 0b00011100, 0b00111000, 0b00001100, 0b01111000, 0b00001110, 0b01111000, 0b00001110, 0b01111100, 0b00001110, 0b01111110, 0b00011100, 0b00111111, 0b10111000, 0b00111111, 0b11110000, 0b00011111, 0b11110000, 0b00000111, 0b11111000, 0b00011111, 0b11111100, 0b00111001, 0b11111100, 0b01110000, 0b01111110, 0b01110000, 0b00111111, 0b11110000, 0b00011111, 0b11110000, 0b00001110, 0b11110000, 0b00001110, 0b01110000, 0b00001110, 0b01110000, 0b00011110, 0b00111000, 0b00011100, 0b00011110, 0b11111000, 0b00001111, 0b11110000 };
void _ocho24(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, ocho24, 16, 24, WHITE, BLACK);
}
static const unsigned char PROGMEM nueve24[] = { 0b00000111, 0b11100000, 0b00011111, 0b11110000, 0b00011100, 0b01111000, 0b00111100, 0b00111100, 0b01111100, 0b00111100, 0b01111000, 0b00111110, 0b11111000, 0b00111110, 0b11111000, 0b00111110, 0b11111000, 0b00111111, 0b11111000, 0b00111111, 0b11111100, 0b00111111, 0b11111100, 0b00111111, 0b01111100, 0b01111111, 0b00111101, 0b11111111, 0b00011111, 0b11111110, 0b00001111, 0b10111110, 0b00000000, 0b00111110, 0b01110000, 0b00111100, 0b01111000, 0b00111100, 0b11111100, 0b00111100, 0b01111100, 0b00111000, 0b00111100, 0b01111000, 0b00111110, 0b01110000, 0b00001111, 0b11100000 };
void _nueve24(uint8_t x, uint8_t y) {
  display.drawBitmap(x, y, nueve24, 16, 24, WHITE, BLACK);
}






void printNum24(uint8_t num, uint8_t x, uint8_t y) {
  if (num == 0) { _cero24(x, y); }
  if (num == 1) { _uno24(x, y); }
  if (num == 2) { _dos24(x, y); }
  if (num == 3) { _tres24(x, y); }
  if (num == 4) { _cuatro24(x, y); }
  if (num == 5) { _cinco24(x, y); }
  if (num == 6) { _seis24(x, y); }
  if (num == 7) { _siete24(x, y); }
  if (num == 8) { _ocho24(x, y); }
  if (num == 9) { _nueve24(x, y); }
}

void printNum40(uint8_t num, uint8_t x, uint8_t y) {
  if (num == 0) { _cero40(x, y); }
  if (num == 1) { _uno40(x, y); }
  if (num == 2) { _dos40(x, y); }
  if (num == 3) { _tres40(x, y); }
  if (num == 4) { _cuatro40(x, y); }
  if (num == 5) { _cinco40(x, y); }
  if (num == 6) { _seis40(x, y); }
  if (num == 7) { _siete40(x, y); }
  if (num == 8) { _ocho40(x, y); }
  if (num == 9) { _nueve40(x, y); }
}

void digNum40(uint16_t num, uint8_t digitos, uint8_t x, uint8_t y) {
  uint16_t numx = num;
  uint8_t digito1 = 0;
  uint8_t digito2 = 0;
  uint8_t digito3 = 0;
  uint8_t digito4 = 0;
  uint8_t digito5 = 0;

  digito1 = numx % 10;
  numx /= 10;
  digito2 = numx % 10;
  numx /= 10;
  digito3 = numx % 10;
  numx /= 10;
  digito4 = numx % 10;
  digito5 = numx / 10;

  if (digitos == 5) {
    printNum40(digito5, x, y);
    x += 18;
  }
  if (digitos >= 4) {
    printNum40(digito4, x, y);
    x += 18;
  }
  if (digitos >= 3) {
    printNum40(digito3, x, y);
    x += 18;
  }
  if (digitos >= 2) {
    printNum40(digito2, x, y);
    x += 18;
  }
  if (digitos >= 1) { printNum40(digito1, x, y); }
  //display.display();
}

void digNum24(uint16_t num, uint8_t digitos, uint8_t x, uint8_t y) {
  uint16_t numx = num;
  uint8_t digito1 = 0;
  uint8_t digito2 = 0;
  uint8_t digito3 = 0;
  uint8_t digito4 = 0;
  uint8_t digito5 = 0;

  digito1 = numx % 10;
  numx /= 10;
  digito2 = numx % 10;
  numx /= 10;
  digito3 = numx % 10;
  numx /= 10;
  digito4 = numx % 10;
  digito5 = numx / 10;

  if (digitos == 5) {
    printNum24(digito5, x, y);
    x += 18;
  }
  if (digitos >= 4) {
    printNum24(digito4, x, y);
    x += 18;
  }
  if (digitos >= 3) {
    printNum24(digito3, x, y);
    x += 18;
  }
  if (digitos >= 2) {
    printNum24(digito2, x, y);
    x += 18;
  }
  if (digitos >= 1) { printNum24(digito1, x, y); }
  //display.display();
}

void screenClk40() {
  //display.clearDisplay();
  rtc.read();

  digNum40(rtc.hours(), 2, 0, 0);

  digNum40(rtc.minutes(), 2, 44, 0);

  digNum40(rtc.seconds(), 2, 88, 0);
}

void screenClk24() {
  //display.clearDisplay();
  rtc.read();

  digNum24(rtc.hours(), 2, 0, 40);

  digNum24(rtc.minutes(), 2, 44, 40);

  digNum24(rtc.seconds(), 2, 88, 40);
}

void drawEsfera() {
  display.drawEllipse(63, 35, 24, 24, WHITE);
  display.drawEllipse(63, 35, 18, 24, WHITE);
  display.drawEllipse(63, 35, 12, 24, WHITE);
  display.drawEllipse(63, 35, 5, 24, WHITE);
  display.drawEllipse(63, 35, 0, 24, WHITE);

  display.drawEllipse(63, 35, 24, 18, WHITE);
  display.drawEllipse(63, 35, 24, 12, WHITE);
  display.drawEllipse(63, 35, 24, 5, WHITE);
  display.drawEllipse(63, 35, 24, 0, WHITE);
}

void drawEsfera(uint8_t x, uint8_t y) {
  display.drawEllipse(63, 35, 26, 26, WHITE);
  display.drawEllipse(63, 35, 18+x, 24, WHITE);
  display.drawEllipse(63, 35, 12+x, 24, WHITE);
  display.drawEllipse(63, 35, 5+x, 24, WHITE);
  display.drawEllipse(63, 35, 0+x, 24, WHITE);
  display.drawEllipse(63, 35, -21+x, 24, WHITE);
  display.drawEllipse(63, 35, -15+x, 24, WHITE);
  display.drawEllipse(63, 35, -7+x, 24, WHITE);
  display.drawEllipse(63, 35, -3+x, 24, WHITE);

  display.drawEllipse(63, 35, 24, 18+y, WHITE);
  display.drawEllipse(63, 35, 24, 12+y, WHITE);
  display.drawEllipse(63, 35, 24, 5+y, WHITE);
  display.drawEllipse(63, 35, 24, 0+y, WHITE);
}



const unsigned char osciloscopio [] PROGMEM = {
	// 'Sprite-0002, 128x64px
	0x00, 0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0xf0, 0x20, 0x00, 0x08, 0x00, 0x80, 0x02, 0x00, 0x00, 
	0x3c, 0xc8, 0xc6, 0x30, 0x65, 0x38, 0xb0, 0x85, 0x22, 0xdc, 0x0b, 0x81, 0x54, 0xe2, 0x31, 0x9c, 
	0x41, 0x29, 0x29, 0x4a, 0x96, 0x84, 0xc0, 0xe6, 0xb3, 0x02, 0x38, 0x42, 0x5a, 0x12, 0x4a, 0x42, 
	0x39, 0xe9, 0xe8, 0x42, 0x94, 0x9c, 0x80, 0x84, 0xa2, 0x0e, 0x49, 0xc3, 0xd2, 0x72, 0x4a, 0x4e, 
	0x05, 0x09, 0x09, 0x4a, 0x94, 0xa4, 0x80, 0x84, 0xa2, 0x12, 0x4a, 0x42, 0x52, 0x92, 0x4a, 0x52, 
	0x78, 0xe4, 0xe6, 0x32, 0x64, 0x9a, 0x80, 0x74, 0x9a, 0x0d, 0x31, 0xa2, 0x52, 0x69, 0x31, 0xcd, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 
	0x00, 0xc8, 0x80, 0x04, 0x82, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x40, 
	0x39, 0x2c, 0x80, 0x04, 0x81, 0x20, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 
	0x7d, 0x2a, 0x80, 0x04, 0x99, 0x21, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x2a, 0x80, 0x04, 0xa5, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x29, 0x80, 0x02, 0xa5, 0x21, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x38, 0xc8, 0x80, 0x03, 0x25, 0x20, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x18, 0x9b, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x10, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x7d, 0x31, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x7d, 0x13, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x7d, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x4b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x4b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x4b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x4b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7d, 0x4b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x39, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
};

void _oscilos(){
  display.drawBitmap(0,0,osciloscopio,128,64,WHITE,BLACK);
  display.display();
}

