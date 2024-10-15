#include "Matrix2D.h"

#define CLK_PIN 13
#define LAT_PIN 12          
#define DATA_PIN 11

Matrix2D Matrix;

void setup() {

  Serial.begin(115200);
  while(!Serial);

  Matrix.begin(DATA_PIN, LAT_PIN, CLK_PIN);
  Serial.println("hello world");

  // pinMode(LAT, OUTPUT);
  // pinMode(CLK, OUTPUT);
  // pinMode(DATA, OUTPUT);
  //shiftOut(DATA,CLK,LSBFIRST, cisla[7]);
  //shiftOut(DATA,CLK,LSBFIRST, cisla[6]);
  //shiftOut(DATA,CLK,LSBFIRST, cisla[5]);
  //shiftOut(DATA,CLK,LSBFIRST, cisla[4]);
  //shiftOut(DATA,CLK,LSBFIRST, cisla[3]);
  //shiftOut(DATA,CLK,LSBFIRST, cisla[2]);
  //shiftOut(DATA,CLK,LSBFIRST, cisla[1]);
  //shiftOut(DATA,CLK,LSBFIRST, cisla[0]);
  
}


void loop() {

  Matrix.display();

  //Serial.println("hello world");
  //delay(1000);

}