#include <tinyxml2.h>
#include "Matrix2D.h"

using namespace tinyxml2;

Matrix2D Matrix;
XMLDocument doc;

#define CLK_PIN 13
#define LAT_PIN 12          
#define DATA_PIN 11

//char* xml =;

void setup() {

  Serial.begin(115200);
  while(!Serial);

  Serial.println(doc.ErrorStr());

  //Serial.println("Serial complete");

  //doc.Parse( xml );

  XMLElement* titleElement = doc.FirstChildElement( "SPEED" );
  //char* speed = titleElement->GetText();

  XMLElement* titleElement2 = doc.FirstChildElement( "DIRECTION" );
  //char* direction = titleElement2->GetText();

  //Serial.println(speed);
  //Serial.println(direction);

  Matrix.begin(DATA_PIN, LAT_PIN, CLK_PIN);

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

  //Matrix.display();

}