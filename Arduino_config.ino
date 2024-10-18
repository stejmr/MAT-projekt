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

String RAWxml;

//char* type_wind_speed;
char* direction;

void setup() {

  Serial.begin(9600);

  while (!Serial)
    ;

  Connect_WiFi();

  //Serial.println(doc.ErrorStr());

  //Serial.println("Serial complete");

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
  delay(1000);
  if (WiFi.status() == WL_CONNECTED) {
    //Serial.printf("Connected \n");
    HTTPClient http;
    http.begin("http://46.13.10.244:8005/xml.xml");
    int statusCode = http.GET();

    if (statusCode > 0) {
      String RAWxml = http.getString();
      Serial.println("\nStatus:" + String(statusCode));
      //Serial.println(RAWxml);

      doc.Parse(RAWxml.c_str());
      //Serial.println("1");
      XMLElement* SensorList = doc.FirstChildElement("wario")->FirstChildElement("input");
      //Serial.println("2");
      for (tinyxml2::XMLElement* child = SensorList->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) 
      {
        String type = child->FirstChildElement("type")->GetText();
        if(type == "wind_direction" || type == "wind_speed")
        {
          Serial.println(child->FirstChildElement("value")->GetText());
        }

      }
      
      //const char* wind_speed = SensorList->GetText();

      //XMLElement* titleElement2 = doc.FirstChildElement( "value" );
      //char* direction = titleElement2->GetText();

      //Serial.println(wind_speed);
      //Serial.println(direction);

      Matrix.begin(DATA_PIN, LAT_PIN, CLK_PIN);
    } 
    else {
      Serial.println("Http error");
    }

  } 
  else {
    Serial.println("Connection lost");
    Connect_WiFi();
  }
  //Matrix.display();
}

void Connect_WiFi() {
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.print("\nConnected to: ");
  Serial.print(ssid);
  Serial.print("\nIP adress: ");
  Serial.print(WiFi.localIP());
}