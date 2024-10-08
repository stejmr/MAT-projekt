#define SOIL A0
//#define SOIL2 A4
#define VALVE 2

void setup()
{
  Serial.begin(9600);
  pinMode(VALVE, OUTPUT);
  pinMode(SOIL, INPUT);
  
}

void loop()
{ 
  //Serial.println(analogRead(SOIL));
  if (analogRead(SOIL) <= 600)
  {
    Serial.println("ON");
  	digitalWrite(VALVE, LOW);
    delay(1);
  }
  
  if (analogRead(SOIL) > 600)
  {
    Serial.println("OFF");
  	digitalWrite(VALVE, HIGH);
    delay(1);
  }
}