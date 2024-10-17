#include <tinyxml2.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "Matrix2D.h"

const char* ssid = "Ondys-iPhone";
const char* password = "12345678";

using namespace tinyxml2;

Matrix2D Matrix;
XMLDocument doc;

#define CLK_PIN 13
#define LAT_PIN 12          
#define DATA_PIN 11

//char* xml =;

void setup() {

  Serial.begin(9600);

  while(!Serial);

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.print("\nConnected to: ");
  Serial.print(ssid);
  Serial.print("\nIP adress: ");
  Serial.print(WiFi.localIP());

  //Serial.println(doc.ErrorStr());

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
  if(WiFi.status() == WL_CONNECTED)
  {

  }
  else
  {

    Serial.println("Connection lost");
    // WiFi.begin(ssid, password);
    // if(WiFi.status() == WL_CONNECTED)
    // {
    //   Serial.println("Reconnected");
    // }
    // delay(1000);
  }
  //Matrix.display();

}