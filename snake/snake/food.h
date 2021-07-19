#pragma once
#include "windows.h"
#include "board.h"
class Food
{
private:
  COORD pos;
  char shape;
public:
  Food(COORD &pos,char shape);
  ~Food();
  COORD getPos();
  char getShape();
  void redisplay();
};

