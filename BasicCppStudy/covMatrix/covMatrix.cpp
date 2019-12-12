// covMatrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int My_CalcCovarMatrix(const vector<vector<float>>& mat, vector<vector<float>>& covar, vector<float>& mean)
{
	const int rows = mat.size();
	const int cols = mat[0].size();

	for (int i = 0; i < cols; i++)   // 计算均值
	{
		for (int j = 0; j < rows; j++)
		{
			mean[i] += mat[j][i];
		}
		mean[i] = 1.0 / (rows)* mean[i];
	}

	vector<vector<float>> mat_mean;
	mat_mean = mat;
	for (int i = 0; i < rows; i++)	//
	{
		for (int j = 0; j < cols; j++)
		{
			mat_mean[i][j] = mat[i][j] - mean[j];
		}
	}

	for (int i = 0; i < cols; i++)  //矩阵计算
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = 0; k < rows; k++)
			{
				covar[i][j] += mat_mean[k][i] * mat_mean[k][j];
			}
		}
	}
	return 0;
}

int main()
{
	vector<vector<float>> temp;
	vector<float> t;
	t.push_back(1.2f);
	t.push_back(-3.6f);
	t.push_back(4.3f);
	temp.push_back(t);
	t.clear();
	t.push_back(2.5f);
	t.push_back(9.2f);
	t.push_back(1.3f);
	temp.push_back(t);
	t.clear();
	t.push_back(5.6f);
	t.push_back(0.5f);
	t.push_back(9.4f);
	temp.push_back(t);
	t.clear();
	t.push_back(-2.5f);
	t.push_back(7.2f);
	t.push_back(-3.4f);
	temp.push_back(t);
	t.clear();
	const int rows = temp.size();
	const int cols = temp[0].size();
	vector<std::vector<float>> covar;
	t.push_back(0.0f);
	t.push_back(0.0f);
	t.push_back(0.0f);
	covar.push_back(t);
	t.clear();
	t.push_back(0.0f);
	t.push_back(0.0f);
	t.push_back(0.0f);
	covar.push_back(t);
	t.clear();
	t.push_back(0.0f);
	t.push_back(0.0f);
	t.push_back(0.0f);
	covar.push_back(t);
	t.clear();

	vector<float> mean;
	mean.resize(3, (float)0);
	My_CalcCovarMatrix(temp, covar, mean);
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << covar[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}



