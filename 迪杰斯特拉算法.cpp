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
#include <assert.h>
using namespace std;


struct Node {
	int nodeNum;
	vector<int> neighbours;
};


int selectMinIndex(vector<int>& distance,vector<int>& flag) {
	int tempmin = INT_MAX;
	int ret;
	for (int i = 1; i < distance.size(); i++) {
		if (flag[i] == 1)
			continue;
		if (tempmin > distance[i])
			ret = i;
	}
	return ret;
}


int main() {
	map<pair<int, int>, int> distance;
	int nodeNum, distanceNum;

	cin >> nodeNum >> distanceNum;

	vector<struct Node> node(nodeNum+1);
	for (int i = 0; i < distanceNum; i++) {
		int nodea, nodeb, distancec;
		cin >> nodea >> nodeb >> distancec;
		distance[make_pair(nodea, nodeb)] = distancec;
		node[nodea].neighbours.push_back(nodeb);
	}

	vector<int> flag(nodeNum + 1, 0);
	vector<vector<int>> matrix(nodeNum+1, vector<int>(nodeNum+1,INT_MAX));
	for (int temp : node[1].neighbours) {
		matrix[1][temp] = distance[make_pair(1, temp)];
	}
	matrix[1][1] = 0;

	for (int i = 1; i <= nodeNum; i++) {
		int next = selectMinIndex(matrix[1],flag);

		for (int j:node[next].neighbours) {
			matrix[1][j] = min(matrix[1][j], matrix[1][next] + distance[make_pair(next, j)]);
		}
		flag[next] = 1;
	}

	for (int i = 1; i <= nodeNum; i++)
		cout << "from 1 to " << i << "  min cost is:" << matrix[1][i]<<endl;

	return 0;
}


