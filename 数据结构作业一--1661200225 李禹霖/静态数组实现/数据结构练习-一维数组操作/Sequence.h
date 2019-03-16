#pragma once

namespace seq
{
	const int MAXIMUM = 1000;
	class List
	{
	private:
		int value;
		int maxvalue;
		int length;
		int num;
		int list [MAXIMUM];
	public:
		List();
		void set_value();
		void set_maxvalue();
		void generate_list();
		void output_list();
		void insert_data();
		void delete_data();
		int num_data(int &);
		bool query_data(int &);
		void showmenu();
		void menu();
	};
}