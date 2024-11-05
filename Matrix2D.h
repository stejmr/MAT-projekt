#ifndef Matrix2D_h
#define Matrix2D_h
#include <Arduino.h>

class Matrix2D {
  public:

    Matrix2D();

    void begin(int DISPLAY_NUM, int DATA_PIN, int CLK_PIN, int LAT_PIN);

    void display(String value_dir, String value_speed);

  private: 
  
    void displayChar(char znak);

    int DATAPIN;
    int CLKPIN;
    int LATPIN;

    String VALUE_DIR;
    String VALUE_SPEED;

    int DISPLAYNUM;
};
#endif