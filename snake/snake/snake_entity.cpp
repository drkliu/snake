#include "snake_entity.h"
#include <iostream>

//void Snake::addSnake()
//{
//  COORD pos = { 0,0 };
//  COORD max = {0,0};
//  COORD min = { 0,0 };
//  for (auto& position : positions)
//  {
//    if ((position.X + position.Y) > (max.X + max.Y))
//    {
//      max.X = position.X;
//      max.Y = position.Y;
//      continue;
//    }
//
//    if ((position.X + position.Y) < (min.X + min.Y))
//    {
//      min.X = position.X;
//      min.Y = position.Y;
//    }
//  }
//  switch (direction)
//  {
//  case 'u':
//    
//    pos.X = max.X;
//    if(max.Y>=(height-1))
//    {
//      pos.Y = max.Y;
//      pos.X++;
//    }
//    else
//    {
//      pos.Y++;
//    }
//    pos.Y = positions.back().Y - 1;
//    break;
//  case 'd':
//    pos.X = positions.back().X;
//    pos.Y = positions.back().Y + 1;
//    break;
//  case 'l':
//    pos.X = positions.back().X + 1;
//    pos.Y = positions.back().Y;
//    break;
//  case 'r':
//    pos.X = positions.back().X - 1;
//    pos.Y = positions.back().Y;
//    break;
//  }
//  positions.push_back(pos);
//}

Snake::Snake(COORD &pos, int vel)
{
  
  this->vel = vel;
  this->len = 1;
  this->direction = 'n';
  this->score = 0;
  status = ActionStatus::IDLE;
  this->pos = pos;
  body.push_back(this->pos);
 
}

Snake::~Snake()
{
}
void Snake::changeDirection(char direction) {
  this->direction = direction;
}
void Snake::move()
{
  switch (direction)
  {
  case 'u': pos.Y -= vel; break;
  case 'd': pos.Y += vel; break;
  case 'l': pos.X -= vel; break;
  case 'r': pos.X += vel; break;
  }

  body.push_back(pos);
  //std::cout << &pos << std::endl;
  if (body.size() > len) {
    body.erase(body.begin());
  }
}

 

bool Snake::eaten(COORD &pos)
{
   auto headPos = this->pos;
  
  if (headPos.X == pos.X && headPos.Y == pos.Y) {
    score++;
    return true;
  }
   
  return false;
}

int Snake::getScore()
{
  return score;
}

void Snake::grow()
{
  len++;
 // addSnake();
}

int Snake::getLen()
{
  return len;
}

void Snake::pause()
{
  status = ActionStatus::PAUSE;
}

bool Snake::isPaused()
{
  return status== ActionStatus::PAUSE;
}

void Snake::resume()
{
  status = ActionStatus::RUNNING;
}

bool Snake::collided(COORD &pos)
{
  auto headPos = this->pos;
 
  if ( headPos.X <= 0 || headPos.X >= pos.X || headPos.Y <= 0 || headPos.Y >= pos.Y)
  {
    status = ActionStatus::COLLIDED;
    return true;
  }
   
  return false;
  
}

bool Snake::isOccupy(COORD &pos)
{
  for (auto& position : body)
  {
    if (position.X == pos.X && position.Y == pos.Y)
    {
      return true;
    }
  }
  return false;
}
COORD Snake::getPos()
{
  return pos;
}
char Snake::getShape()
{

  return '*';
}

std::vector<COORD> Snake::getBody()
{
  return body;
}
