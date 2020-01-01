#include "pch.h"
#include <string>
#include <iostream>
#include "test_sil.h"

namespace test_common
{
	std::string get_a_target_string()
	{
		long target = 0;
		char buf[10];
		std::cout << "target (0 - " << RAND_MAX << "):";
		std::cin >> target;
		snprintf(buf, 10, "%d", target);// C std lib;
		return  std::string(buf);
	}
	int compareStrings(const void* a, const void* b)
	{
		if (*(std::string*)a > *(std::string*)b)
		{
			return 1; // qsort ��������
		}
		else if (*(std::string*)a < *(std::string*)b)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}

	long get_a_target_long()
	{
		long target = 0;
		std::cout << "target (0 - " << RAND_MAX << "):";
		std::cin >> target;
		return target;
	}

	int compareLongs(const void* a, const void*  b)
	{
		return (*(long*)a - *(long*)b);
	}

	void print(std::string str, const void* value)// �������� const void�����ã�
	{
		std::cout << str << value << std::endl;
	}



}