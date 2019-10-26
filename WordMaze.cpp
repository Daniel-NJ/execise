// WordMaze.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void Step(int n, int m, int x, int y, queue<vector<int>>& que, vector<vector<int>>& vist) {
	if (x + 1 < n ) { 
		que.push(vector<int>{x + 1, y});
	}

	if (x - 1 >= 0 ) {
		que.push(vector<int>{x - 1, y});
	}

	if (y - 1 >= 0 ) {
		que.push(vector<int>{x, y - 1});
	}

	if (y + 1 < m ) {
		que.push(vector<int>{x, y + 1});
	}

}

int main()
{
	/*
	int n;
	int m;
	string target;
	cin >> n >> m;
	vector<string> map(n);
	getline(cin, target);
	getline(cin, target);
	for (int i = 0; i < n; i++) {
		getline(cin, map[i]);
	}
	*/
	string target = "YHLOVPRGPECECPUC";
	int n = 5, m = 5;
	vector<string> map = {"CPUCY",
						  "EKLQH",
						  "CRSOL",
						  "EKLQO",
						  "PGRPV" };

	vector<vector<int>> vist(n, vector<int>(m, 0));
	queue<vector<int>> que;
	for (int i = 0; i < n; i++) {
		auto y = map[i].find_first_of(target[0]);
		while (y != string::npos) {
			if (vist[i][y]==0) {
				vist[i][y] = 1;
				Step(n, m, i, y, que, vist);
				int k = 0;
				while (!que.empty()) {
					int count = que.size();
					if (k == target.size() - 1) {
						cout << "YES" << endl;
						return 0;
					}
					char cha = target[++k];
					for (int j = 0; j < count; j++) {
						auto pos = que.front(); que.pop();
						//vist[pos[0]][pos[1]] = 1;
						//如果是要找的字符，则接着选择下一步，push到队列里
						if (map[pos[0]][pos[1]] == cha) {
							Step(n, m, pos[0], pos[1], que, vist);
						}
					}
				}
			}
			y = map[i].find_first_of(target[0], y+1);
		}
	}
	
	std::cout << "NO" << endl;
	return 0;
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
