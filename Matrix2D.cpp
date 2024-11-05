#include "Matrix2D.h"
#include <Arduino.h>

char znaky[] = {

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         //space
    0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x18, 0x00,         //!
    0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00,         //"
    0x66, 0x66, 0xFF, 0x66, 0xFF, 0x66, 0x66, 0x00,         //#
    0x18, 0x3E, 0x60, 0x3C, 0x06, 0x7C, 0x18, 0x00,         //$
    0x62, 0x66, 0x0C, 0x18, 0x30, 0x66, 0x46, 0x00,         //%
    0x3C, 0x66, 0x3C, 0x38, 0x67, 0x66, 0x3F, 0x00,         //&
    0x06, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,         //'
    0x0C, 0x18, 0x30, 0x30, 0x30, 0x18, 0x0C, 0x00,         //(
    0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x18, 0x30, 0x00,         //)
    0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00,         //*
    0x00, 0x18, 0x18, 0x7E, 0x18, 0x18, 0x00, 0x00,         //+
    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x30,         //,
    0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00,         //-
    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00,         //.
    0x00, 0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x00,         ///

    0x3C, 0x66, 0x6E, 0x76, 0x66, 0x66, 0x3C, 0x00,         //0
    0x18, 0x18, 0x38, 0x18, 0x18, 0x18, 0x7E, 0x00,         //1
    0x3C, 0x66, 0x06, 0x0C, 0x30, 0x60, 0x7E, 0x00,         //2
    0x3C, 0x66, 0x06, 0x1C, 0x06, 0x66, 0x3C, 0x00,         //3
    0x06, 0x0E, 0x1E, 0x66, 0x7F, 0x06, 0x06, 0x00,         //4
    0x7E, 0x60, 0x7C, 0x06, 0x06, 0x66, 0x3C, 0x00,         //5
    0x3C, 0x66, 0x60, 0x7C, 0x66, 0x66, 0x3C, 0x00,         //6
    0x7E, 0x66, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x00,         //7
    0x3C, 0x66, 0x66, 0x3C, 0x66, 0x66, 0x3C, 0x00,         //8
    0x3C, 0x66, 0x66, 0x3E, 0x06, 0x66, 0x3C, 0x00,			    //9

    0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00,         //:
    0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x18, 0x30,         //;
    0x0E, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0E, 0x00,         //<
    0x00, 0x00, 0x7E, 0x00, 0x7E, 0x00, 0x00, 0x00,         //=
    0x70, 0x18, 0x0C, 0x06, 0x0C, 0x18, 0x70, 0x00,         //> 
    0x3C, 0x66, 0x06, 0x0C, 0x18, 0x00, 0x18, 0x00,         //?
    0x3C, 0x66, 0x6E, 0x6E, 0x60, 0x62, 0x3C, 0x00,         //@

    0x18, 0x3C, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x00,         //A
    0x7C, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x7C, 0x00,         //B
    0x3C, 0x66, 0x60, 0x60, 0x60, 0x66, 0x3C, 0x00,         //C
    0x78, 0x6C, 0x66, 0x66, 0x66, 0x6C, 0x78, 0x00,         //D
    0x7E, 0x60, 0x60, 0x78, 0x60, 0x60, 0x7E, 0x00,         //E
    0x7E, 0x60, 0x60, 0x78, 0x60, 0x60, 0x60, 0x00,         //F
    0x3C, 0x66, 0x60, 0x6E, 0x66, 0x66, 0x3C, 0x00,         //G
    0x66, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x00,         //H
    0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00,         //I
    0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x6C, 0x38, 0x00,         //J
    0x66, 0x6C, 0x78, 0x70, 0x78, 0x6C, 0x66, 0x00,         //K
    0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7E, 0x00,         //L
    0x63, 0x77, 0x7F, 0x6B, 0x63, 0x63, 0x63, 0x00,         //M
    0x66, 0x76, 0x7E, 0x7E, 0x6E, 0x66, 0x66, 0x00,         //N
    0x3C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00,         //O
    0x7C, 0x66, 0x66, 0x7C, 0x60, 0x60, 0x60, 0x00,         //P
    0x3C, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x0E, 0x00,         //Q
    0x7C, 0x66, 0x66, 0x7C, 0x78, 0x6C, 0x66, 0x00,         //R
    0x3C, 0x66, 0x60, 0x3C, 0x06, 0x66, 0x3C, 0x00,         //S
    0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00,         //T
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00,         //U
    0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x00,         //V
    0x63, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x00,         //W
    0x66, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0x66, 0x00,         //X
    0x66, 0x66, 0x66, 0x3C, 0x18, 0x18, 0x18, 0x00,         //Y
    0x7E, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x7E, 0x00,         //Z

    0x3C, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3C, 0x00,         //[
    0x00, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x00,       /*  \     */
    0x3C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x3C, 0x00,         //]
    0x18, 0x3C, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00,         //^
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,         //_
    0x60, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,         //`

    0x00, 0x00, 0x3C, 0x06, 0x3E, 0x66, 0x3E, 0x00,         //a
    0x60, 0x60, 0x7C, 0x66, 0x66, 0x66, 0x7C, 0x00,         //b
    0x00, 0x00, 0x3C, 0x66, 0x60, 0x66, 0x3C, 0x00,         //c
    0x06, 0x06, 0x3E, 0x66, 0x66, 0x66, 0x3E, 0x00,         //d
    0x00, 0x00, 0x3C, 0x66, 0x7E, 0x60, 0x3E, 0x00,         //e
    0x1C, 0x36, 0x30, 0x78, 0x30, 0x30, 0x30, 0x00,         //f
    0x00, 0x00, 0x3E, 0x66, 0x66, 0x3E, 0x06, 0x7C,         //g
    0x60, 0x60, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x00,         //h
    0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00,         //i
    0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x66, 0x3C,         //j
    0x60, 0x60, 0x66, 0x6C, 0x78, 0x7C, 0x66, 0x00,         //k
    0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00,         //l
    0x00, 0x00, 0x63, 0x77, 0x7F, 0x6B, 0x63, 0x00,         //m
    0x00, 0x00, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x00,         //n
    0x00, 0x00, 0x3C, 0x66, 0x66, 0x66, 0x3C, 0x00,         //o
    0x00, 0x00, 0x7C, 0x66, 0x66, 0x7C, 0x60, 0x60,         //p
    0x00, 0x00, 0x3E, 0x66, 0x66, 0x3E, 0x06, 0x06,         //q
    0x00, 0x00, 0x7C, 0x66, 0x60, 0x60, 0x60, 0x00,         //r
    0x00, 0x00, 0x3C, 0x60, 0x3C, 0x06, 0x7C, 0x00,         //s
    0x30, 0x30, 0xFC, 0x30, 0x30, 0x36, 0x1C, 0x00,         //t
    0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00,         //u
    0x00, 0x00, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x00,         //v
    0x00, 0x00, 0x63, 0x6B, 0x7F, 0x36, 0x22, 0x00,         //w
    0x00, 0x00, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0x00,         //x
    0x00, 0x00, 0x66, 0x66, 0x66, 0x3E, 0x06, 0x7C,         //y
    0x00, 0x00, 0x7E, 0x0C, 0x18, 0x30, 0x7E, 0x00,          //z
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 		    //debug
  };

Matrix2D::Matrix2D(){};

void Matrix2D::begin(int DISPLAY_NUM, int DATA_PIN, int CLK_PIN, int LAT_PIN)
{
  Matrix2D::DATAPIN = DATA_PIN;
  Matrix2D::CLKPIN = CLK_PIN;
  Matrix2D::LATPIN = LAT_PIN;
  Matrix2D::DISPLAYNUM = DISPLAY_NUM;


  pinMode(DATAPIN, OUTPUT);
  pinMode(CLKPIN, OUTPUT);
  pinMode(LATPIN, OUTPUT);


  //Serial.println("Setup complete");
}

void Matrix2D::displayChar(char znak) {
  if (znak == 0) return;
	znak = znak - 32;
	//Serial.print(znak, DEC);
    
	for(int i = 7; i >= 0; i--)
  	{
   		shiftOut(DATAPIN,CLKPIN,LSBFIRST, znaky[i + znak*8]);
   		//Serial.println(znaky[i+ znak*8], BIN);
  	}
}

void Matrix2D::display(String value_dir, String value_speed){

  Matrix2D::VALUE_DIR = value_dir;
  Matrix2D::VALUE_SPEED = value_speed;
  
  char buffer[10];
  // clear buffer
  for (int i=0; i<DISPLAYNUM; i++) {
  	buffer[i] = 32;
  }
  
  // read data to display
  int index = 0;
  while (Serial.available() > 0 && index < DISPLAYNUM) {          //change this!!!
    buffer[index++] = Serial.read();                              //and this
  }
  
  // display data
  for (int i=5; i >=0; i--)
  {
    displayChar(buffer[i]);
  }
  digitalWrite(LATPIN, HIGH);
  digitalWrite(LATPIN, LOW);
}