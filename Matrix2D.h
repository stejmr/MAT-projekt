#ifndef Matrix2D_h
#define Matrix2D_h
#include <Arduino.h>

class Matrix2D {
  public:

    Matrix2D();

    void begin(int DISPLAY_NUM, int DATA_PIN, int CLK_PIN, int LAT_PIN);

    void display();

  private: 
  
    void displayChar(char znak);

    int DATAPIN;
    int CLKPIN;
    int LATPIN;

    int DISPLAYNUM;
};
#endif