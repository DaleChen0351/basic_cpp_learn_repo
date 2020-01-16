// LeetcodeTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>




class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		for (int i = 0; i < nums.size(); i++)
		{
			if (hash.count(target - nums[i]))
				return { hash[target - nums[i]], i };
			hash[nums[i]] = i;// 原始vector数组的index 是 value，原因在于我们要返回index
		}
		return { -1, -1 };
	}
};

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int>hash;
	for (int i = 0; i < nums.size(); i++)
	{
		if (hash.count(target - nums[i]))
		{
			return { hash[target - nums[i]], i };
		}
		hash[nums[i]] = i;
	}
	return { -1, -1 };
}


int main()
{
	std::cout << "Hello World!\n";
	// # 1
	int a[] = { 1,2,3,5,8 };
	vector<int> twoSum_vec(a, a + 5);
	vector<int> ret = twoSum(twoSum_vec, 10);


	// # 2
	int i = 0;

}
