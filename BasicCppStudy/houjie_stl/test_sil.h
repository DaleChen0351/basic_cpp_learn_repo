#pragma once

namespace test_array
{
	extern void test_array();
}

namespace test_vector
{
	extern void test_vector(long value);// ÔªËØ¸öÊý
}

namespace test_common
{

	extern std::string get_a_target_string();
	extern int compareStrings(const void* a, const void* b);
	extern long get_a_target_long();
	extern 	int compareLongs(const void* a, const void*  b);
	extern void print(std::string str, const void* value);
}

namespace test_list
{
	extern void test_list(long value);
}

namespace test_basic
{
	extern void test_max();
}
