// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include"string"
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
string add(string a, string b) {
	int len = max(a.size(), b.size());
	string output;
	int pre = 0;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for (int i = 0; i < len; i++) {
		int result = 0;
		if (i < a.size())
			result += (a[i] - '0');
		if (i < b.size())
			result += (b[i] - '0');
		result += pre;
		output.insert(output.end(), result % 10 + '0');
		pre = result / 10;
	}

	if (pre > 0)
		output.insert(output.end(), pre + '0');

	reverse(output.begin(), output.end());

	return output;
}

string mult(string a, char c) {
	int pre = 0;
	int result = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		result = (a[i] - '0')*(c - '0') + pre;
		pre = result / 10;
		a[i] = result % 10 + '0';
	}
	if (pre > 0)
		a.insert(a.begin(), pre + '0');

	return a;
}


pair<string, int> multiply(pair<string, int> a, pair<string, int> b) {
	string output;
	for (int i = 0; i < b.first.size(); i++) {
		string temp = mult(a.first, b.first[i]);
		for (int j = i; j < b.first.size() - 1; j++)
			temp.insert(temp.end(), '0');
		output = add(output, temp);
	}

	return make_pair(output, a.second + b.second);

}

int main()
{
	vector<string>a;
	vector<int>b;
	string temps;
	int tempi;
	while (cin >> temps) {
		a.push_back(temps);
		cin >> tempi;
		b.push_back(tempi);
		if (getchar() == '\n')
			break;
	}
	vector<pair<string, int>>input;
	for (int i = 0; i < a.size(); i++) {
		string temp;
		int t = 0;
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] != '.')
				temp.insert(temp.end(), a[i][j]);
			else
				t = a[i].size() - j-1;
		}
		input.push_back(make_pair(temp, t));
	}

	vector<pair<string, int>>output;
	for (int i = 0; i < input.size(); i++) {
		pair<string, int> c = input[i];
		for (int j = 0; j < b[i] - 1; j++) {
			c = multiply(c, input[i]);
		}
		output.push_back(c);
	}

	for (int k = 0; k < output.size(); k++) {
		for (int i = 0; i < output[k].first.size()-output[k].second; i++)
			cout << output[k].first[i];
		cout << '.';
		for (int i = output[k].first.size() - output[k].second; i < output[k].first.size(); i++) {
			cout << output[k].first[i];
		}
	}
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
