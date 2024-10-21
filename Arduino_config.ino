#include <tinyxml2.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "Matrix2D.h"

#define CLK_PIN 13
#define LAT_PIN 12
#define DATA_PIN 11

using namespace tinyxml2;

const char* ssid = "Ondys-iPhone";
const char* password = "12345678";

Matrix2D Matrix;
XMLDocument doc;
HTTPClient http;

void setup() {

  Serial.begin(9600);
  while (!Serial);

  Connect_WiFi();

  Matrix.begin(DATA_PIN, LAT_PIN, CLK_PIN);

  //Serial.println(doc.ErrorStr());
}


void loop() {
  
  String RAWxml;
  String value_dir;
  String value_speed;

  delay(1000);

  if (WiFi.status() == WL_CONNECTED) {                                //checks if WIFI is connected
    http.begin("http://46.13.10.244:8005/xml.xml");                   //connects to meteostation
    int statusCode = http.GET();                                      //gets status code from meteostation

    if (statusCode > 0) 
    {                                             //checks if HTTP is comunicating
      //String type;
      RAWxml = http.getString();                                      //gets XML data to string
      Serial.println("\nStatus:" + String(statusCode));               //prints status code 
      //Serial.println(RAWxml);

      doc.Parse(RAWxml.c_str());                                      //parses XML data converted to a char pointer
      //Serial.println("1");
      XMLElement* SensorList = doc.FirstChildElement("wario")->FirstChildElement("input");    //navigates in XML document
      //Serial.println("2");
      for (tinyxml2::XMLElement* child = SensorList->FirstChildElement(); child != NULL; child = child->NextSiblingElement())     // reads every sensor element of XML
      {
        String type = child->FirstChildElement("type")->GetText();             //navigates to type in every sensor and saves their data
        if(type == "wind_direction")                   //filters by type
        {
          value_dir = child->FirstChildElement("value")->GetText();  //gets value from sensors and prints them
          Serial.println(value_dir.toInt());                                //converts data to Int
        }
        if(type == "wind_speed")                   //filters by type
        {
          value_speed = child->FirstChildElement("value")->GetText();  //gets value from sensors and prints them
          Serial.println(value_speed.toInt());                                //converts data to Int
        }
      }
    } 
    else {
      Serial.println("Http error");                 //HTTP connection lost
    }
  } 
  else {
    Serial.println("Connection lost");
    Connect_WiFi();                                 //reconects to wifi
  }
  //Matrix.display();
}

void Connect_WiFi() {
  WiFi.begin(ssid, password);                      //connects to WIFI
  Serial.println("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {          //waiting for connection
    Serial.print(".");
    delay(500);
  }

  Serial.print("\nConnected to: ");
  Serial.print(ssid);                              //prints which WIFI it conected to
  Serial.print("\nIP adress: ");
  Serial.print(WiFi.localIP());                    //prints its IP
}