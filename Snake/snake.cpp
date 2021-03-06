#include "snake.h"
#include<conio.h>
#include"tools.h"
#include<iostream>
#include<memory>

void Snake::InitSnake() {
	for (auto& point : snake)
	{
		point.PrintCircular();  ///逐点打印。
	}
}

void Snake::Move()  ///蛇的尾部增加一块。 根据蛇的移动方向确定坐标；
					///增长式移动
{
	switch (direction)
	{
	case Direction::UP :
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1));
		break;
	case Direction::DOWN :
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1));
		break;
	case Direction::LEFT :
		snake.emplace_back(Point(snake.back().GetX() - 1, snake.back().GetY() ));
		break;
	case Direction::RIGHT :
		snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY()));
		break;
	default:
		break;

	}
	SetColor(14);
	snake.back().PrintCircular(); //输出新增的点，清除首个点，因为其他位置不变，所以没有必要再全部print一次。
	// 吃到食物之后长度要+1，就不用再删除队首的点了。,
}

void Snake::NormalMove()  ///先在尾部加一个。 再给头部减一个。
{
	Move(); //按照当前方向更改deque中的下一个位置，初始化。
	
	snake.front().Clear(); 
	snake.pop_front();
}
bool Snake::OverEdge() //反向判断最为致命！
{
	return snake.back().GetX() < 30 &&
		snake.back().GetY() < 30 &&
		snake.back().GetX() > 1 &&
		snake.back().GetY() > 1;
}


bool Snake::HitItself()
{
	std::deque<Point> ::size_type cnt = 1;
	//Point *head = new Point(snake.back().GetX(), snake.back().GetY()); ///蛇的头部坐标。
	//std::shared_ptr<Point> head(new Point(snake.back().GetX(), snake.back().GetY() )); //使用智能指针可以更好的控制资源。
	std::shared_ptr<Point> head = std::make_shared<Point>(snake.back().GetX(), snake.back().GetY()); //智能指针使用make_shared而不是new
	//Point head = Point(snake.back().GetX(), snake.back().GetY()); //也可以不使用指针，代码块执行完后，也会释放head占用的空间。但如果遇到异常，则OVER
	
	for (auto& point : snake)
	{
		if (!(point == *head))	++cnt;
		//if (!(point == head))	++cnt;
			else break;
	}
	//delete head;
	if (cnt == snake.size())
		return true;
	else return false;

}


bool Snake::ChangeDirection()
{
	char ch;
	if (_kbhit()) //按键按下
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();  //方向键的ASCII码要读两次。
			switch (ch) 
			{
			case 72:
				if (direction != Direction::DOWN)
					direction = Direction::UP;
				break;
			case 80:
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75:
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77:
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;
		case 27:		///esc 呼出菜单 Menu()
			return false;
			
		default:	
			return true;
		}
	}
	return true;
}

bool Snake::GetFood(const Food& cfood)
{
	if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y)
		return true;
	else
		return false;

}

bool Snake::GetBigFood(Food& cfood)
{
	if (snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)
	{
		cfood.big_flag = false;
		cfood.big_x = 0;
		cfood.big_y = 0;

		SetCursorPosition(27, 0);
		SetColor(11);
		for (int i = 42; i >= 0; --i) {  /// 进度条缩短
			std::cout << "\b\b ";
		}

		SetCursorPosition(1, 0);
		std::cout << " ";
		return true;
	}
	else
		return false;

}
