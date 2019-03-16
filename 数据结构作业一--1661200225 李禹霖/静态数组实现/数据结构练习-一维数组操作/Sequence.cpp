#include "pch.h"
#include "Sequence.h"
#include <iostream>

using namespace seq;

List::List()
{
	value = 0;
	maxvalue = 0;
	length = 0;
	num = 0;
}

void List::set_value()
{
	int x;
	std::cout << "���������в�ֵ" << std::endl;
	std::cin >> x;
	value = x;
}

void List::set_maxvalue()
{
	int x;
	std::cout << "�������������ֵֵ" << std::endl;
	std::cin >> x;
	maxvalue = x;
}

//���ɲ�ֵΪn�����ֵΪm�������������
void List::generate_list()
{
	while (1)
	{
	    set_value();
		set_maxvalue();
		int a = 0;
		for (int n = 0; n < MAXIMUM; n = n + value)
		{
			if (n < maxvalue)
			{
				list[a] = n;
				length = length + list[a];
				a++;
			}
			else
			{
				length++;
				break;
			}
		}
		if (length > MAXIMUM)
		{
			std::cout << "���鳤�ȳ������ֵ�������������ֵ�����ֵ" << std::endl;
			continue;
		}
		int num = 1;
		for (int i = 0; i <= maxvalue; i = i + value)
		{
			if (i == 0)
			{
				list[i] = 0;
			}
			for (int j = 0; j < i; j++)
			{
				list[num] = i;
				num++;
			}
		}
		break;
	}
}

void List::output_list()
{
	std::cout << "��������Ϊ��" << std::endl;
	for (int i = 0; i < length; i++)
	{
		std::cout << list[i]<<" ";
	}
	std::cout << std::endl;
}

int List::num_data(int &x)
{
	for (int i = 0; i < length; i++)
	{
		if (x == list[i])
		{
			num++;
		}
		if (list[i] > x)
		{
			break;
		}
	}
	return num;
}

void List::insert_data()
{
	int x;
	int tab;
	char cr;
	while (true)
	{
		if (length == MAXIMUM)
		{
			std::cout << "�����Ѵﵽ��󳤶ȣ��޷�����" << std::endl;
			break;
		}
		else
		{
			while (true)
			{
				std::cout << "����Ҫ��������ݣ�";
				std::cin >> x;
				if (x < 0)
				{
					std::cout << "���벻�Ϸ�������������" << std::endl;
				}
				else
				{
					break;
				}
			}
			if (x == 0)
			{
				length++;
				tab = x;
				for (int i = length - 1; i > tab; i--)
				{
					list[i + 1] = list[i];
				}
				list[1] = 0;
			}
			else if (x > maxvalue)
			{
				list[length] = x;
				length++;
			}
			else
			{
				for (int i = 0; i < length; i++)
				{
					if (x < list[i])
					{
						tab = i;
						break;
					}
				}
				length++;
				for (int j = length-1; j > tab; j--)
				{
					list[j+1] = list[j];
				}
				list[tab] = x;
			}
		}
		std::cout << "��������������Y/y��" ;
		std::cin >> cr;
		if (cr != 'Y' || cr != 'y')
		{
			break;
		}
	}
}

void List::delete_data()
{
	int x;
	int y;
	int tab;
	int num;
	char cr;
	while (true)
	{
		while (true)
		{
			std::cout << "����Ҫɾ�������ݣ�";
			std::cin >> x;
			if (query_data(x) == 0)
			{
				std::cout << "Ҫɾ�������ݲ����ڣ����������룺" << std::endl;
			}
			else
			{
				break;
			}
		}
		if (x == maxvalue)
		{
			length - num_data(x);
		}
		else
		{
			for (int k = 0; k < length; k++)
			{
				if (x == list[k])
				{
					tab = k;
					break;
				}
			}
			y = num_data(x);
			length = length - y;
			for (int z = tab; z < length; z++)
			{
				list[z] = list[z + y];
			}
		}
		std::cout << "����ɾ��������Y/y ��";
		std::cin >> cr;
		if (cr != 'Y' || cr != 'y')
		{
			break;
		}
	}
}

bool List::query_data(int &x)
{
	bool bl = 0;
	for (int i = 0; i < length; i++)
	{
		if (x == list[i])
		{
			bl = 1;
			break;
		}
	}
	return bl;
}

void List::showmenu()
{
	std::cout << "------�˵�------" << std::endl;
	std::cout << "----1.��������----" << std::endl;
	std::cout << "----2.��������----" << std::endl;
	std::cout << "----3.ɾ������----" << std::endl;
	std::cout << "----0.�˳�����----" << std::endl;
	std::cout << "--------------" << std::endl;
}

void List::menu()
{
	char cr;
	showmenu();
	while (1)
	{
		std::cout << "����ѡ��0~3��:";
		std::cin >> cr;
		switch (cr)
		{
		case '1':
			generate_list();
			output_list();
			break;
		case '2':
			insert_data();
			output_list();
			break;
		case '3':
			delete_data();
			output_list();
			break;
		default:
			break;
		}
		showmenu();
		if (cr == '0')
		{
			std::cout << "������ֹͣ����" << std::endl;
			break;
		}
	}
}

