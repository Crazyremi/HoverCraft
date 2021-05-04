#ifndef JOYSTCIK_BOARD_H
#define JOYSTCIK_BOARD_H

#include <Arduino.h>

class JoyStickBoard {
  private:
    int upPin, downPin, leftPin, rightPin;
    int joyStickXPin, joyStickYPin, joyStickSWPin;
    int joyStickBTPin;

   public:
    JoyStickBoard(int up, int down, int left, int right, int X, int Y, int S,int B);
    bool upButton();
    bool downButton();
    bool leftButton();
    bool rightButton();
    int XVal();
    int YVal();
    bool SWIsPressed();
    bool BTIsPressed();
    void getData(int* data);
};

#endif
