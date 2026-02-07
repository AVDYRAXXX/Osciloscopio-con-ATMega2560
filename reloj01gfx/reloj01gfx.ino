#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <Arduino.h>
#include <IRremote.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#include <DS3232.h>

//{
  int X0 = 0;
  int X1 = 0;
  int X2 = 0;
  int X3 = 0;
  int X4 = 0;
  int X5 = 0;
  int X6 = 0;
  int X7 = 0;
  int X8 = 0;
  int X9 = 0;
  int X10 = 0;
  int X11 = 0;
  int X12 = 0;
  int X13 = 0;
  int X14 = 0;
  int X15 = 0;
  int X16 = 0;
  int X17 = 0;
  int X18 = 0;
  int X19 = 0;
  int X20 = 0;
  int X21 = 0;
  int X22 = 0;
  int X23 = 0;
  int X24 = 0;
  int X25 = 0;
  int X26 = 0;
  int X27 = 0;
  int X28 = 0;
  int X29 = 0;
  int X30 = 0;
  int X31 = 0;
  int X32 = 0;
  int X33 = 0;
  int X34 = 0;
  int X35 = 0;
  int X36 = 0;
  int X37 = 0;
  int X38 = 0;
  int X39 = 0;
  int X40 = 0;
  int X41 = 0;
  int X42 = 0;
  int X43 = 0;
  int X44 = 0;
  int X45 = 0;
  int X46 = 0;
  int X47 = 0;
  int X48 = 0;
  int X49 = 0;
  int X50 = 0;
  int X51 = 0;
  int X52 = 0;
  int X53 = 0;
  int X54 = 0;
  int X55 = 0;
  int X56 = 0;
  int X57 = 0;
  int X58 = 0;
  int X59 = 0;
  int X60 = 0;
  int X61 = 0;
  int X62 = 0;
  int X63 = 0;
  int X64 = 0;
  int X65 = 0;
  int X66 = 0;
  int X67 = 0;
  int X68 = 0;
  int X69 = 0;
  int X70 = 0;
  int X71 = 0;
  int X72 = 0;
  int X73 = 0;
  int X74 = 0;
  int X75 = 0;
  int X76 = 0;
  int X77 = 0;
  int X78 = 0;
  int X79 = 0;
  int X80 = 0;
  int X81 = 0;
  int X82 = 0;
  int X83 = 0;
  int X84 = 0;
  int X85 = 0;
  int X86 = 0;
  int X87 = 0;
  int X88 = 0;
  int X89 = 0;
  int X90 = 0;
  int X91 = 0;
  int X92 = 0;
  int X93 = 0;
  int X94 = 0;
  int X95 = 0;
  int X96 = 0;
  int X97 = 0;
  int X98 = 0;
  int X99 = 0;
  int X100 = 0;
  int X101 = 0;
  int X102 = 0;
  int X103 = 0;
  int X104 = 0;
  int X105 = 0;
  int X106 = 0;
  int X107 = 0;
  int X108 = 0;
  int X109 = 0;
  int X110 = 0;
  int X111 = 0;
  int X112 = 0;
  int X113 = 0;
  int X114 = 0;
  int X115 = 0;
  int X116 = 0;
  int X117 = 0;
  int X118 = 0;
  int X119 = 0;
  int X120 = 0;
  int X121 = 0;
  int X122 = 0;
  int X123 = 0;
  int X124 = 0;
  int X125 = 0;
  int X126 = 0;
  int X127 = 0;
  int wave[] = { X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16, X17, X18, X19, X20, X21, X22, X23, X24, X25, X26, X27, X28, X29, X30, X31, X32, X33, X34, X35, X36, X37, X38, X39, X40, X41, X42, X43, X44, X45, X46, X47, X48, X49, X50, X51, X52, X53, X54, X55, X56, X57, X58, X59, X60, X61, X62, X63, X64, X65, X66, X67, X68, X69, X70, X71, X72, X73, X74, X75, X76, X77, X78, X79, X80, X81, X82, X83, X84, X85, X86, X87, X88, X89, X90, X91, X92, X93, X94, X95, X96, X97, X98, X99, X100, X101, X102, X103, X104, X105, X106, X107 };
  int AIN = 0;
  int ainx = analogRead(AIN);
  int SIZE = 0;
//}

DS3232 rtc;



void initRtc() {
  while (!Serial)
    ;
}

void setTimeRtc(uint8_t hr, uint8_t min, uint8_t sec, uint8_t diaSem, uint8_t dia, uint8_t mes, uint8_t anio) {

  rtc.setSeconds(sec);
  rtc.setMinutes(min);
  rtc.setHours(hr);
  rtc.setWeekDay(diaSem);
  rtc.setDay(dia);
  rtc.setMonth(mes);
  rtc.setYear(anio);
  rtc.write();
}

void printDate()
{
  char buffer[16];
  sprintf(buffer, "%04d-%02d-%02d",
        2000 + rtc.year(), rtc.month(), rtc.day());
  display.print(buffer);
}

void printTime()
{
  char buffer[16];
  sprintf(buffer, "  %02d:%02d:%02d",
        rtc.hours(), rtc.minutes(), rtc.seconds());
  display.print(buffer);
}
