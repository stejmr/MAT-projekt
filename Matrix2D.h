#ifndef Matrix2D_h
#define Matrix2D_h
#include <Arduino.h>

class Matrix2D {
  public:

    Matrix2D();

    void begin(int DISPLAY_NUM, int DATA_PIN, int CLK_PIN, int LAT_PIN, int RST_PIN);

    void display(String value);

  private: 
  
    int DATAPIN;
    int CLKPIN;
    int LATPIN;
    int RSTPIN;

    String VALUE;

    int DISPLAYNUM;
    int WAIT_US = 100;

    void MYshiftOut(uint8_t DATAPIN, uint8_t CLKPIN, uint8_t bitOrder, uint8_t val);

    void pulsePin(uint8_t pin, bool negative);

    void displayChar(char znak);

};
#endif