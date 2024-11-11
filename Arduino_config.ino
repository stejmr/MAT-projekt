#include <tinyxml2.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "Matrix2D.h"

#define DATA_PIN 2
#define CLK_PIN 4
#define LAT_PIN 3
#define RST_PIN 5

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

  Matrix.begin(5, DATA_PIN, LAT_PIN, CLK_PIN, RST_PIN);

  //Serial.println(doc.ErrorStr());
}


void loop() {
  delay(1000);

  if (WiFi.status() == WL_CONNECTED) {                                //checks if WIFI is connected

  http.begin("http://46.13.10.244:8005/xml.xml");                   //connects to meteostation
  int statusCode = http.GET(); 

    if (statusCode > 0) 
    {                                                                 //checks if HTTP is comunicating
      Serial.println("\nStatus:" + String(statusCode));             //prints status code 
      String wind_info = Parse_doc();
      Matrix.display(wind_info);
    }
    else {
      Serial.println("Http error");                 //HTTP connection lost
      Serial.println(String(statusCode));
      Matrix.display("ERR2");
    }
  } 
  else {
    Serial.println("Connection lost");
    Matrix.display("ERR1");
    delay(1000);
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

String  Parse_doc(){
  String RAWxml;
  String value_dir_buffer;
  String value_speed_buffer;
  String value_dir;
  String value_speed;

  RAWxml = http.getString();                                      //gets XML data to string

  doc.Parse(RAWxml.c_str());                                      //parses XML data converted to a char pointer
  //Serial.println("1");
  XMLElement* SensorList = doc.FirstChildElement("wario")->FirstChildElement("input");    //navigates in XML document
  //Serial.println("2");
  for (tinyxml2::XMLElement* child = SensorList->FirstChildElement(); child != NULL; child = child->NextSiblingElement())     // reads every sensor element of XML
  {
    String type = child->FirstChildElement("type")->GetText();             //navigates to type in every sensor and saves their data
    if(type == "wind_direction")                   //filters by type
    {
      value_dir_buffer = child->FirstChildElement("value")->GetText();  //gets value from sensors and prints them
      //Serial.println(value_dir_buffer.toInt());                                //converts data to Int
    }
    if(type == "wind_speed")                   //filters by type
    {
      value_speed_buffer = child->FirstChildElement("value")->GetText();  //gets value from sensors and prints them
      //Serial.println(value_speed_buffer.toInt());                                //converts data to Int

      value_dir = String(value_dir_buffer.toInt());
      value_speed = String(value_speed_buffer.toInt());

      if (value_dir.length() == 1)
      {
        value_dir = "00" + value_dir;
      }
      if (value_dir.length() == 2)
      {
        value_dir = "0" + value_dir;
      }
      if (value_speed.length() == 1)
      {
        value_speed = "0" + value_speed;
      }
          
      String value = value_dir + value_speed;
      Serial.println(value);
      return(value);
    }
  }
}