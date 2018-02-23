#ifndef SNAKE_H
#define SNAKE_H

#include<deque>
#include"point.h"
#include"food.h"

class Food;
class Snake 
{
public:
	enum Direction{UP, DOWN, LEFT, RIGHT}; //枚举四个移动方向
	Snake() {
		snake.emplace_back(14, 8);
		snake.emplace_back(15, 8);
		snake.emplace_back(16, 8);
		direction = Direction::DOWN;
	} //初始位置在屏幕正中，方向向下
	void InitSnake();
	void Move();
	void NormalMove();
	bool OverEdge(); //撞墙
	bool HitItself(); //撞自己
	bool ChangeDirection(); //改变方向
	bool GetFood(const Food&); //吃到食物
	bool GetBigFood(Food&); //吃到大食物
private:
	std::deque<Point> snake;
	Direction direction;
	friend class Food;

};

#endif