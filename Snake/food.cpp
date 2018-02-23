#include"food.h"
#include"tools.h"
#include<cstdlib>
#include<iostream>

void Food::DrawFood(Snake& csnake)
{
	//��rand����������ֵ ������2-29֮�䣬 ����õ�����������ص��������»�ȡ
	// ÿ���ʳ����־ͻ��һ����ʱʳ��
	while (true) {
		int tem_x = rand() % 30;
		int tem_y = rand() % 30;
		if (tem_x <= 2) tem_x += 3; //�����ߵ�����������ʽ�� ��ʳ�������ǽ���Աߣ���ֱ��over
		if (tem_y <= 2) tem_y += 3;

		bool flag = false; //�ж��غ�
		for (auto& point : csnake.snake)  //�ж�ʳ���Ƿ������غϡ�
		{
			if (  (point.GetX() == tem_x &&point.GetY() == tem_y) 
				|| (tem_x == big_x && tem_y == big_y )  ) {
				flag = true;
				break;
			}

		}
		if (flag) continue; //����غ��� ���»�����x��y

		x = tem_x;
		y = tem_y;
		SetCursorPosition(x, y);
		SetColor(13);
		std::cout << "*";

		++cnt;
		cnt %= 5;
		if (cnt == 0) {
			DrawBigFood(csnake);
		}
		break;

	}
}

void Food::DrawBigFood(Snake & csnake)

{
	SetCursorPosition(5, 0);
	SetColor(11);
	std::cout << "------------------------------------------"; ///������������
	progress_bar = 42;
	while (true)
	{
		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;
		if (tmp_x <= 2) tmp_x += 3;  //������ǽ����һ����롣
		if (tmp_y <= 2) tmp_y += 3;
		bool flag = false;
		for (auto& point : csnake.snake)  //���ص�
		{
			if ((point.GetX() == tmp_x &&point.GetY() == tmp_y) || (tmp_x == x &&tmp_y == y)) //�κ�һ���ص�������
			{
				flag = true;			
				break;
			} 
		}
		if (flag)  continue; ///���غϣ� ��������

		big_x = tmp_x;
		big_y = tmp_y;
		SetCursorPosition(big_x, big_y);
		SetColor(18);
		std::cout << "��";
		big_flag = true;
		flash_flag = true;
		break;
	}
}

int Food::GetCnt()
{
	return cnt;
}

void Food::FlashBigFood() ///��������ʱʳ��
{
	SetCursorPosition(big_x, big_y);
	SetColor(18);
	if (flash_flag)
	{

		std::cout << " ";
		flash_flag = false;

	}
	else {
		std::cout << "��";
		flash_flag = true;
	}
	SetCursorPosition( 27 , 0 );
	SetColor(11);
	for (int i = 42; i >= progress_bar; --i) {  // ����������
		std::cout << "\b\b ";
	}	
	--progress_bar;
	if (progress_bar == 0) {
		SetCursorPosition(big_x, big_y);
		std::cout << "  ";  //���big food
		big_flag = false;
		big_x = 0;
		big_y = 0;
	}

}

bool Food::GetBigFlag()
{
	return big_flag;
}

int Food::GetProgressBar()
{
	return progress_bar;
}