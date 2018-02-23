#include"startinterface.h"
#include <windows.h>

void StartInterface::PrintFirst()  //从左边屏幕边框到完全出现。
{
	for (auto& point : startsnake) {
		point.Print();
		Sleep(speed);
	}
}

void StartInterface::PrintSecond()  //从屏幕左边向右移动
{
	for (int i = 10; i != 40; ++i)
	{
		///计算蛇头的下一个位置， 并将其压入startsnake中，绘制出来。
		//int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		int j = startsnake.front().GetY(); //2.0 初始位置是对称的，所以直接取队首的点的Y坐标就是下一个位置的Y坐标。
		startsnake.emplace_back(Point(i, j)); //新位置入队列尾
		startsnake.back().Print(); //打印新位置
		startsnake.front().Clear();  //Point::Clear()， 清除首点
		startsnake.pop_front(); //出队列
		Sleep(speed);
	}
}

void StartInterface::PrintThird()
{
	while (!startsnake.empty() || textsnake.back().GetX() < 33) ///33为指定停止位置
	{
		if (!startsnake.empty())
		{
			startsnake.front().Clear();
			startsnake.pop_front();
		}
		ClearText(); //将清楚当前的text点，并将vector中的text点横坐标+1
		PrintText(); //重新print text
		Sleep(speed);//控制速度
	}
}

void StartInterface::PrintText()
{
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0) //只打印屏幕上看得到的点。
		{
			point.Print();
		}
	}
}

void StartInterface::ClearText()
{
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
			point.Clear();
		point.ChangePosition(point.GetX() + 1, point.GetY()); //清除文字，再向右一格 再输出
	}
}

void StartInterface::Action()
{
	PrintFirst();
	PrintSecond();
	PrintThird();
}
