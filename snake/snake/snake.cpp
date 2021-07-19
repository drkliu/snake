// snake.cpp: 定义应用程序的入口点。
//

#include "snake.h"

 
#include "snake_entity.h"
#include "food.h"
#include "conio.h"
 

void padding_space(int n)
{
  while (--n > 0)
  {
    std::cout << " ";
  }
}
void padding_line(int n)
{
  while (--n > 0)
  {
    std::cout << std::endl;
  }
}
int game_status = 1;
void board(Snake &snake,Food &food)
{
  COORD snake_pos = snake.getPos();
  COORD food_pos = food.getPos();
  COORD pos = { 0,0 };
  for (int i = 0; i < height; i++)
  {
    //padding_space(left_padding);
    pos.Y = i;
    std::cout << "#";
    for (int j = 0; j < width-2; j++)
    {
      pos.X = j;
      if (i == 0 || i == (height - 1))
      {
        std::cout << "#";
      }
      else if (i == food_pos.Y && j == food_pos.X)
      {
        std::cout << food.getShape();
      }
      else if (snake.isOccupy(pos))
      {
        
          std::cout << "*";
      }
      else
      {
        std::cout << " ";
      }
    }
    std::cout << "#\n";
  }
}

int main()
{
  //padding_line(top_padding);
 
  auto snake = Snake(COORD{ width / 2,height / 2 }, 1);
  auto food = Food(COORD{ 1,3 }, '0');
  auto board_coord = COORD{ width,height };
  food.redisplay();
  bool game_over = false;
 
 

  while (true)
  {
    srand(time(NULL));
    if (snake.collided(board_coord)) {
      std::cout << "Game is over";
      break;
    }
    
    //padding_line(top_padding);
    board(snake,food);
 
    //coord.X++;
    //system("cls");
    bool start = false;
    if (kbhit()) {
      switch (getch()) {
      case 'w':
        snake.changeDirection('u');
        snake.resume();
        break;
      case 's':
        snake.changeDirection('d');
        snake.resume();
        break;
      case 'a':
        snake.changeDirection('l');
        snake.resume();
        break;
      case 'd':
        snake.changeDirection('r');
        snake.resume();
        break;
      case 'p':
        snake.pause();
        break;
      case 'r':
        snake.resume();
        break;
      }
      start = true;
    }
    if(start && !snake.isPaused())
    {
      snake.move();
    }
    
    if (snake.eaten(food.getPos()))
    {
      food.redisplay();
      snake.grow();
    }
    std::cout << "snake pos X:" << snake.getPos().X << ",Y:" << snake.getPos().Y<<std::endl;
    
    std::cout << "food pos X:" << food.getPos().X << ",Y:" << food.getPos().Y << std::endl;
    std::cout << "score:" << snake.getScore() << std::endl;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
  
  }
  
  //std::cout << "hello world \rrrrssss";
  
	 
	return 0;
}
