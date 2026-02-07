





void setup() {
  initOled();
  initRtc();
  initIRREMOTE();
}






uint16_t val = 0;
uint8_t x0=55;
uint8_t y0=31;
uint8_t x1=39;
uint8_t y1=47;
uint8_t x2=63;
uint8_t y2=55;
uint8_t x3=79;
uint8_t y3=39;
uint8_t w1=0;
uint8_t z1=8;
uint8_t w2=127;
uint8_t z2=63;
void piramide(){
  
  x0=random(w1, w2);
  x1=random(w1, w2);
  x2=random(w1, w2);
  x3=random(w1, w2);
  y0=random(z1, z2);
  y1=random(z1, z2);
  y2=random(z1, z2);
  y3=random(z1, z2);

  display.drawLine(x0, y0, 63, 15, WHITE);
  display.drawLine(x1, y1, 63, 15, WHITE);
  display.drawLine(x2, y2, 63, 15, WHITE);
  display.drawLine(x3, y3, 63, 15, WHITE);
  
  display.drawLine(x0, y0, x1, y1, WHITE);
  display.drawLine(x1, y1, x2, y2, WHITE);
  display.drawLine(x2, y2, x3, y3, WHITE);
  display.drawLine(x3, y3, x0, y0, WHITE);
}


void loop() {
  display.clearDisplay();

  
}
