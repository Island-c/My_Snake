#include <iostream>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"controller.h"
#include"tools.h"
#include"startinterface.h"
#include"map.h"
#include"snake.h"
#include"food.h"

void Controller::Start()  //��ʼ����
{
	SetWindowSize(41, 32); /// ���ڴ�С
	SetColor(2);///������ɫ
	StartInterface *start = new StartInterface(); ///ΪʲôҪ�ö�̬�����ڴ棿
	start->Action(); /// k��ʼ����
	delete start; 

	//���ù��λ�ã������ʾ��
	SetCursorPosition(13, 26);
	std::cout << "Press any key to start...";
	SetCursorPosition(13, 27);
	system("pause");

}

void Controller::Select()
{
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "��ѡ����Ϸ�Ѷ�";
	SetCursorPosition(6, 22);
	std::cout << "�����¼�ѡ�񣬻س���ȷ�ϣ�";
	SetCursorPosition(27, 22);
	SetBackColor();  ///���ñ���ɫ����ʾ��ǰѡ��
	std::cout << "��ģʽ";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "��ͨģʽ";
	SetCursorPosition(27, 26);
	std::cout << "����ģʽ";
	SetCursorPosition(27, 28);
	std::cout << "����ģʽ";
	SetCursorPosition(0, 31);
	score = 0;

	///���·����ѡ�� ʵ�����£�
	int ch; // ��¼����
	key = 1; ///��¼ѡ����
	bool flag = false; ///��¼�Ƿ����enter
	while ((ch = _getch()))
	{
		switch(ch)
		{
		case 72: //up ��
			if (key > 1)
			{
				switch (key)
				{

				case 2:
					SetCursorPosition(27, 22);
					SetBackColor();
					std::cout << "��ģʽ";

					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "��ͨģʽ";

					--key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨģʽ";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "����ģʽ";

					--key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����ģʽ";

					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "����ģʽ";

					--key;
					break;

				}
			}
			break;

		case 80:///�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨģʽ";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "��ģʽ";
					++key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����ģʽ";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "��ͨģʽ";
					++key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "����ģʽ";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "����ģʽ";
					++key;
					break;
				}
			}
			break;

		case 13:  ///�س���
			flag = true;
			break;
		default:
			break;

		}
		if (flag) break;
		SetCursorPosition(0, 31);  ///����������½ǣ�������Ϊ�����˸Ӱ����Ϸ���顣


	}
	switch (key) ///speed��ֵԽС �ߵ��ƶ��ٶ�Խ��
	{
	case 1:
		speed = 240;
		break;
	case 2:
		speed = 120;
		break;
	case 3:
		speed = 60;
		break;
	case 4:
		speed = 30;
		break;
	default:
		break;
	}
}


void Controller::DrawGame()
{
	system("cls"); ///����

	///���Ƶ�ͼ
	SetColor(3);
	Map *init_map = new Map();
	init_map->PrintInitmap();
	delete init_map;

	///���Ʋ����
	SetColor(3);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "̰����";
	SetCursorPosition(31, 4);
	std::cout << "�Ѷ�:";
	SetCursorPosition(36, 5);

	switch (key)
	{
	case 1 :
		std::cout << "��ģʽ";
		break;
	case 2:
		std::cout << "��ͨģʽ";
		break;
	case 3:
		std::cout << "����ģʽ";
		break;
	case 4:
		std::cout << "����ģʽ";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "�÷�:";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << "������ƶ�";
	SetCursorPosition(33, 15);
	std::cout << "ESC����ͣ";
}


void Controller::UpdateScore(const int& tmp)
{
	score += key * 10 * tmp;
}

void Controller::RewriteScore()
{
	///Ϊ�˱�֤����β�����롣����������Ϊ6λ�����㵱ǰ����λ������ʣ��λ���ÿո�ȫ�����������
	SetCursorPosition(37, 8);
	SetColor(11);
	int bit = 0;
	int tmp = score;
	while (tmp != 0)
	{
		++bit;
		tmp /= 10;

	}

	for (int i = 0; i < (6 - bit); ++i)
	{
		std::cout << " ";
	}
	std::cout << score;
}

int Controller::Menu() ///ѡ��˵�
{
	///���ƽ���
	SetColor(11);
	SetCursorPosition(32, 19);
	std::cout << "�˵�:";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackColor();
	std::cout << "������Ϸ";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(11);
	std::cout << "���¿�ʼ";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "�˳���Ϸ";
	SetCursorPosition(0, 31);

	///ѡ���ڲ�ʵ�ֲ���
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 72 :  ///up
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					SetCursorPosition(34, 21);
					SetBackColor();
					std::cout << "������Ϸ";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "���¿�ʼ";
					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "�˳���Ϸ";
					--tmp_key;
					break;
				}
			}
			break;
		case 80: ////DOWM
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 21);
					SetColor(11);
					std::cout << "������Ϸ";
					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "�˳���Ϸ";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "���¿�ʼ";
					++tmp_key;
					break;
				}
			}
			break;
		case 13:  ///enter
			flag = true;
			break;
		default:
			break;
		}

		if (flag)  break;

		SetCursorPosition(0, 31);
	}
	return tmp_key; ///������ָ��Ŀ���õ������ĺ�����������
}

void Controller::Game()
{
	Start();  ///��ʼ����
	while (true)  ///һ��ѭ����
	{
		Select();
		DrawGame();
		int tmp = PlayGame();
		if (tmp == 1)
		{
			system("cls");
			continue;
		}

		else if (tmp == 2)
			break;
		else
			break;

	}

}

int Controller::GameOver()
{
	/////������Ϸ��������
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "��������������������������������������������";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ��               Game Over !!!              ��";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ��              ���ź��������              ��";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << " ��             ��ķ���Ϊ��                 ��";
	SetCursorPosition(24, 13);
	std::cout << score;
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << " ��   �Ƿ�����һ�֣�                         ��";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ��    �ţ��õ�        ���ˣ�����ѧϰ����˼  ��";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "��������������������������������������������";
	Sleep(100);
	SetCursorPosition(12, 18);
	SetBackColor();
	std::cout << "�ţ��õ�";
	SetCursorPosition(0, 31);


	///����ʵ��
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 75: ///left
			if (tmp_key > 1)
			{
				SetCursorPosition(12, 18);
				SetBackColor();
				std::cout << "�ţ��õ�";
				SetCursorPosition(20, 18);
				SetColor(11);
				std::cout << "���ˣ�����ѧϰ����˼";
				--tmp_key;
			}
			break;
		case 77: ///right
			if (tmp_key < 2)
			{
				SetCursorPosition(20, 18);
				SetBackColor();
				std::cout << "���ˣ�����ѧϰ����˼";
				SetCursorPosition(12, 18);
				SetColor(11);
				std::cout << "�ţ��õ�";
				++tmp_key;
			}
			break;
		case 13:///enter
			flag = true;
			break;
		default :
			break;
		}

		if (flag)  break;
		SetCursorPosition(0, 31);  ////�����ߵ�λ�� ����������ֵ��¡�����
	}

	SetColor(11);
	switch (tmp_key)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	default: return 1;
	}


}



int Controller::PlayGame()  ///��Ϸ����ѭ����(�ڲ�ѭ��)
{
	////��ʼ���ߺ�ʳ��
	Snake *csnake = new Snake();
	Food *cfood = new Food();
	SetColor(6);
	csnake->InitSnake();
	srand((unsigned)time(NULL)); ///��������ӡ��� �������ã�ʳ����ֵ�λ��will�̶�..
	cfood->DrawFood(*csnake);

	///��Ϸѭ��
	while (csnake->OverEdge() && csnake->HitItself()) ///�Ƿ�ײǽ ����ײ���Լ�
	{
		///��Ϸ�е�ѡ��˵�
		if (!csnake->ChangeDirection())
		{
			int tmp = Menu();  ///���Ʋ˵�
			switch (tmp)
			{
			case 1:  ///������Ϸ
				SetCursorPosition(32, 19);
				std::cout << "        ";
				SetCursorPosition(34, 21);
				std::cout << "        ";
				SetCursorPosition(34, 23);
				std::cout << "        ";
				SetCursorPosition(34, 25);
				std::cout << "        ";
				break;
			case 2:  ///���¿�ʼ
				delete csnake;
				delete cfood;
				return 1;  ///����1 ��ʾ���¿�ʼ
			case 3:
				delete csnake;
				delete cfood;
				return 2; //����2 ��ʾ�˳���Ϸ
			default:
				break;

			}
		}

		if (csnake->GetFood(*cfood)) ///�Ե�ʳ��
		{
			csnake->Move();
			UpdateScore(1);
			RewriteScore();
			cfood->DrawFood(*csnake);
		}
		else {
			csnake->NormalMove();
		}

		if (csnake->GetBigFood(*cfood))
		{
			csnake->Move();
			UpdateScore(cfood->GetProgressBar() / 5); ///��������ʱʳ��Ľ���������
			RewriteScore();
		}
		if (cfood->GetBigFlag()) ////��˸big food
		{
			cfood->FlashBigFood();
		}
		Sleep(speed); //�ߵ��ƶ�Ч��

	}

	///������
	delete csnake;
	delete cfood;
	int tmp = GameOver();
	switch (tmp)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	default:
		return 2;
	}

}