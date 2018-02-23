#ifndef SNAKE_H
#define SNAKE_H

#include<deque>
#include"point.h"
#include"food.h"

class Food;
class Snake 
{
public:
	enum Direction{UP, DOWN, LEFT, RIGHT}; //ö���ĸ��ƶ�����
	Snake() {
		snake.emplace_back(14, 8);
		snake.emplace_back(15, 8);
		snake.emplace_back(16, 8);
		direction = Direction::DOWN;
	} //��ʼλ������Ļ���У���������
	void InitSnake();
	void Move();
	void NormalMove();
	bool OverEdge(); //ײǽ
	bool HitItself(); //ײ�Լ�
	bool ChangeDirection(); //�ı䷽��
	bool GetFood(const Food&); //�Ե�ʳ��
	bool GetBigFood(Food&); //�Ե���ʳ��
private:
	std::deque<Point> snake;
	Direction direction;
	friend class Food;

};

#endif