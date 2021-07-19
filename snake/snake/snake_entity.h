#pragma once
//#include "board.h"
#include "windows.h"
#include <vector>

enum class ActionStatus{
  IDLE,
  RUNNING,
  PAUSE,
  COLLIDED,
};

class Snake
{
private:
  COORD pos;
  std::vector<COORD> body;
  int len, vel;
  char direction;
  int score;
  ActionStatus status;
  //void addSnake();
public:
  Snake(COORD &pos,int vel);
  ~Snake();
  void changeDirection(char direction);
  void move();
  COORD getPos();
  bool eaten(COORD &pos);
  int getScore();
  void grow();
  int getLen();
  void pause();
  bool isPaused();
  void resume();
  bool collided(COORD &pos); //碰撞
  bool isOccupy(COORD &pos);
  char getShape();
  std::vector<COORD> getBody();
};


