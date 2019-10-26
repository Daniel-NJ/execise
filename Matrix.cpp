// Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	
	int n = 5, m = 3;
	vector<vector<int>> matrix = {
	{14,14,4},
	{76,5,76},
	{78,23,23},
	{45,75,53},
	{52,43,71},
	};
	/*
	int n = 2, m = 3;
	vector<vector<int>> matrix = {
		{1,2,3},
		{1,0,2},
	};*/
	vector<vector<int>> f(n, vector<int>(m, 0));
	int temp = 0;
	for (int i = 0; i < m; i++) {
		temp += matrix[0][i];
		f[0][i] = temp;
	}
	temp = 0;
	for (int j = 0; j < n; j++) {
		temp += matrix[j][0];
		f[j][0] = temp;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			f[i][j] = max(f[i - 1][j], f[i][j - 1]) + matrix[i][j];
		}
	}
	cout << f[n-1][m-1] << endl;
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
