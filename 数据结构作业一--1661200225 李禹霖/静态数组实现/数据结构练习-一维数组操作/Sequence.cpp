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
	std::cout << "请输入数列差值" << std::endl;
	std::cin >> x;
	value = x;
}

void List::set_maxvalue()
{
	int x;
	std::cout << "请输入数列最大值值" << std::endl;
	std::cin >> x;
	maxvalue = x;
}

//生成差值为n，最大值为m的有序递增数列
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
			std::cout << "数组长度超过最大值，请重新输入差值和最大值" << std::endl;
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
	std::cout << "数组数据为：" << std::endl;
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
			std::cout << "数组已达到最大长度，无法插入" << std::endl;
			break;
		}
		else
		{
			while (true)
			{
				std::cout << "输入要插入的数据：";
				std::cin >> x;
				if (x < 0)
				{
					std::cout << "输入不合法，请重新输入" << std::endl;
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
		std::cout << "继续插入请输入Y/y：" ;
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
			std::cout << "输入要删除的数据：";
			std::cin >> x;
			if (query_data(x) == 0)
			{
				std::cout << "要删除的数据不存在，请重新输入：" << std::endl;
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
		std::cout << "继续删除请输入Y/y ：";
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
	std::cout << "------菜单------" << std::endl;
	std::cout << "----1.生成数据----" << std::endl;
	std::cout << "----2.插入数据----" << std::endl;
	std::cout << "----3.删除数据----" << std::endl;
	std::cout << "----0.退出程序----" << std::endl;
	std::cout << "--------------" << std::endl;
}

void List::menu()
{
	char cr;
	showmenu();
	while (1)
	{
		std::cout << "输入选择（0~3）:";
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
			std::cout << "程序已停止运行" << std::endl;
			break;
		}
	}
}

