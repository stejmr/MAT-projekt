int CLK = 6;
int LAT = 5;          
int DATA = 4;       


void setup() {
  pinMode(LAT, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  shiftOut(DATA, CLK, LSBFIRST, 0xFF);
  //shiftOut(DATA, CLK, LSBFIRST, 0xFF);
  //shiftOut(DATA, CLK, LSBFIRST, 0xFF);
  digitalWrite(LAT, HIGH);
  printf("start");
}


void loop() {
  //digitalWrite(LAT, LOW);
  //shiftOut(DATA, CLK, LSBFIRST, 0xFF);        //Shift registr 3
  //shiftOut(DATA, CLK, LSBFIRST, 0XAA);        //Shift registr 2
  //shiftOut(DATA, CLK, LSBFIRST, 0xAA);        //Shift registr 1
  //digitalWrite(LAT, HIGH);

// //delay(1000);
//   for (long i = 0; i<10000; i++){
//   digitalWrite(LAT, LOW);
// // shiftOut(DATA, CLK, LSBFIRST, 0XFE);        //Shift registr 8
// // shiftOut(DATA, CLK, LSBFIRST, 0xAA);        //Shift registr 7
// // shiftOut(DATA, CLK, LSBFIRST, 0xAA);        //Shift registr 6
// // shiftOut(DATA, CLK, LSBFIRST, 0XFE);        //Shift registr 5
// // shiftOut(DATA, CLK, LSBFIRST, 0xAA);        //Shift registr 4
//   shiftOut(DATA, CLK, LSBFIRST, 0x00);        //Shift registr 3
//   shiftOut(DATA, CLK, LSBFIRST, 0X00);        //Shift registr 2
//   shiftOut(DATA, CLK, LSBFIRST, 0x00);        //Shift registr 1
//   digitalWrite(LAT, HIGH);
//   }

//   digitalWrite(LAT, LOW);
//   shiftOut(DATA, CLK, LSBFIRST, 0xFF);        //Shift registr 3
//   shiftOut(DATA, CLK, LSBFIRST, 0XFF);        //Shift registr 2
//   shiftOut(DATA, CLK, LSBFIRST, 0xFF);        //Shift registr 1
//   digitalWrite(LAT, HIGH);

//   delay(1000);
 }

