
#include <U8g2lib.h>
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R1, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);  
 
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
String utc = "";
String latt = "hello";
String longt = "";
String satN = "";

String NMEA;

void setup() {
Serial.begin(9600);
u8g2.begin();
  u8g2.enableUTF8Print();
}

void loop(void) {
  u8g2.clearBuffer();  
 
  // clear the internal memory

  u8g2.setFontDirection(1);
  u8g2.setFont(u8g2_font_u8glib_4_tf);  // choose a suitable font
  //y , x 
  u8g2.drawStr(20,0,"GPS");  // write something to the internal memory
 u8g2.drawStr(15,0,"LAT:");
   u8g2.drawStr(10,0,"LON:");
      u8g2.drawStr(5,0,"SAT_NO:");

   u8g2.setDisplayRotation(U8G2_R1);
     
     u8g2.setFontDirection(0);  
     
u8g2.setCursor(0,60);
u8g2.print(latt);
u8g2.sendBuffer();  
if(Serial.available()>0){

GPSData();
 
 
//u8g2.setCursor(10,10);
//u8g2.print(longt);

Serial.print("Lat: ");
Serial.println(latt);
Serial.print("Lon: ");
Serial.println(longt);
Serial.print("UTC: ");
Serial.println(utc); 
/*
 * String
 */

}

  
}
void GPSData(){

if(Serial.find("$GNGGA,")){
  utc = Serial.readStringUntil(',');
    latt = Serial.readStringUntil(',');
    latt.concat(Serial.readStringUntil(','));
    longt = Serial.readStringUntil(',');
    longt.concat(Serial.readStringUntil(','));
}
}
void DisplayGps(){
  
}
