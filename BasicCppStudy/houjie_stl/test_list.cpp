#include "pch.h"
#include <list>
#include <iostream>
#include <forward_list>
#include <exception>

#include <algorithm>


namespace test_list
{
void test_list(long value)
{
	std::list<std::string> c;
	char buff[10];
	for (long i = 0; i < value; i++)
	{
		try {
			snprintf(buff, 10, "%d", rand());
			c.push_back(std::string(buff));
		}
		catch(std::exception& e){
		
			std::cout << e.what()<<std::endl;
		}
	}
	int t_size = c.size();
	test_common::print("list_size", &t_size);

	std::string target = test_common::get_a_target_string();
	auto pitem = std::find(c.begin(), c.end(), target);
	if (pitem!= c.end())
	{
		std::cout << "fould" << *pitem << std::endl;
	}
	c.sort();// list and forward-list ���Լ�������
	// std::sort(c.begin(), c.end());// ? ���벻���ԣ�δ�ҵ�ƥ��ĺ���
	

}
}