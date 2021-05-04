#include "JoyStickBoard.h"

JoyStickBoard::JoyStickBoard(int up, int down, int left, int right, int X, int Y, int S, int B)
    : upPin(up), downPin(down), leftPin(left), rightPin(right), joyStickXPin(X), joyStickYPin(Y), joyStickSWPin(S), joyStickBTPin(B) {}

inline bool JoyStickBoard::upButton() {
  return digitalRead(upPin);
}
inline bool JoyStickBoard::downButton() {
    return digitalRead(downPin);
}
inline bool JoyStickBoard::leftButton() {
    return digitalRead(leftPin);
}
inline bool JoyStickBoard::rightButton() {
    return digitalRead(rightPin);
}
inline int JoyStickBoard::XVal() {
    return analogRead(joyStickXPin);
}
inline int JoyStickBoard::YVal() {
    return analogRead(joyStickYPin);
}
inline bool JoyStickBoard::SWIsPressed() {
    return digitalRead(joyStickSWPin);
}
inline bool JoyStickBoard::BTIsPressed() {
    return digitalRead(joyStickBTPin);
}
void JoyStickBoard::getData(int* data) {
  data[0] = upButton();
  data[1] = downButton();
  data[2] = leftButton();
  data[3] = rightButton();
  data[4] = XVal();
  data[5] = YVal();
  data[6] = SWIsPressed();
  data[7] = BTIsPressed();
}
