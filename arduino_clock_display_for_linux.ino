
#include <Arduino.h>
#include "TM1637Display.h"

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

char str[5];
int i=0;
uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // 0 -- lowest, 7 -- brightest
  display.setBrightness(1);

  // light-up everything
  display.setSegments(data);

}

void loop() {

  if (Serial.available() > 0) {
   str[i]= Serial.read();
   //Serial.print(str[i]);
   
   if( i==3 ) {
    // that's in case we want to print str[]
    str[4]='\0';

    // reset the counter
    i= 0;
 
    // Selectively set different digits
    data[0] = display.encodeDigit(str[0]);

    // This is to display the silly dots
    data[1] = 0x80 | display.encodeDigit(str[1]);
    
    data[2] = display.encodeDigit(str[2]);
    data[3] = display.encodeDigit(str[3]);
    
    display.setSegments(data);
    

    // a silly hack to flush whatever remains in the input buffer
    Serial.read();
    Serial.read();
    Serial.read();
   } else {
    i++;
   }
  }

}
