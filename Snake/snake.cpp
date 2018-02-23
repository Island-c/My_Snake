#include "snake.h"
#include<conio.h>
#include"tools.h"
#include<iostream>
#include<memory>

void Snake::InitSnake() {
	for (auto& point : snake)
	{
		point.PrintCircular();  ///����ӡ��
	}
}

void Snake::Move()  ///�ߵ�β������һ�顣 �����ߵ��ƶ�����ȷ�����ꣻ
					///����ʽ�ƶ�
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

}

void Snake::NormalMove()  ///����β����һ���� �ٸ�ͷ����һ����
{
	Move(); //���յ�ǰ�������deque�е���һ��λ�ã���ʼ����
	snake.back().PrintCircular(); //��������ĵ㣬����׸��㣬��Ϊ����λ�ò��䣬����û�б�Ҫ��ȫ��printһ�Ρ�
	snake.front().Clear(); 
	snake.pop_front();
}
bool Snake::OverEdge() //�����ж���Ϊ������
{
	return snake.back().GetX() < 30 &&
		snake.back().GetY() < 30 &&
		snake.back().GetX() > 1 &&
		snake.back().GetY() > 1;
}


bool Snake::HitItself()
{
	std::deque<Point> ::size_type cnt = 1;
	//Point *head = new Point(snake.back().GetX(), snake.back().GetY()); ///�ߵ�ͷ�����ꡣ
	//std::shared_ptr<Point> head(new Point(snake.back().GetX(), snake.back().GetY() )); //ʹ������ָ����Ը��õĿ�����Դ��
	std::shared_ptr<Point> head = std::make_shared<Point>(snake.back().GetX(), snake.back().GetY()); //����ָ��ʹ��make_shared������new
	//Point head = Point(snake.back().GetX(), snake.back().GetY()); //Ҳ���Բ�ʹ��ָ�룬�����ִ�����Ҳ���ͷ�headռ�õĿռ䡣����������쳣����OVER
	
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
	if (_kbhit()) //��������
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();  //�������ASCII��Ҫ�����Ρ�
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
		case 27:		///esc �����˵� Menu()
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
		for (int i = 42; i >= 0; --i) {  /// ����������
			std::cout << "\b\b ";
		}

		SetCursorPosition(1, 0);
		std::cout << " ";
		return true;
	}
	else
		return false;

}
