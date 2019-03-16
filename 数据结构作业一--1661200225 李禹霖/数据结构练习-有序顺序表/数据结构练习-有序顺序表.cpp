#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>  

const int MAXNUM = 10;

namespace test
{
	class TestList
	{
	public:
		TestList();
		void add(int &);
		void del(int &);
		void prin();
	private:
		std::vector<int>num;
		std::vector<int>::iterator value;
	};
}

test::TestList::TestList()
{
	for (int i = 0; i < MAXNUM; i++)
	{
		if (i == 0)
		{
			num.push_back(i);
		}
		for (int j = 0; j < i; j++)
		{
			num.push_back(i);
		}
	}
}

void test::TestList::add(int &a)
{
	if (a >= 0 && a < 10)
	{
		value = std::find(num.begin(), num.end(), a);
		num.insert(value, a);
	}
	else
	{
		std::cout << "输入的值不合法。" << std::endl;
	}
}

void test::TestList::del(int &a)
{
	value = std::find(num.begin(), num.end(), a);
	if (value != num.end())
	{
		num.erase(std::remove(num.begin(), num.end(), a), num.end());
	}
	else
	{
		std::cout << "输入的值不合法。" << std::endl;
	}
}

void test::TestList::prin()
{
	for (value = num.begin(); value != num.end(); value++)
	{
		std::cout << *value << std::endl;
	}
}

using namespace test;

int main()
{
	int a = 1;
	int b = 2;
	TestList tl;
	tl.add(a);
	tl.del(b);
	tl.prin();
}

