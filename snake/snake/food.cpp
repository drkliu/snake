#include "food.h"
#include <time.h>
 
Food::Food(COORD& pos, char shape)
{
  this->pos = pos;
  this->shape = shape;
}

Food::~Food()
{
}

COORD Food::getPos()
{
  return pos;
}
char Food::getShape()
{
  return shape;
}

void Food::redisplay()
{
 
  int x= (rand() % width-3)+1;
  int y = (rand() % height-3)+1;
  while (x <= 0 || x >= width)
  {
    x= (rand() % width - 3) + 1;
  } 
  while (y <= 0 || y >= height)
  {
    y = (rand() % height - 3) + 1;
  }
  pos.X = x;
  pos.Y = y;
}
