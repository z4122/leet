把一个数组分成M部分，找出怎样分得到的和最大

#include<stdio.h>
#include"string"
#include "vector"
#include "limits.h"
#include "iostream"
#include "algorithm"
#include<unordered_map>
#include<map>
#include <stack>
#include <set>
#include <time.h>
#include <sstream>
#include <queue>
#include<functional>
#include <unordered_set>
using std::string;
using std::map;
using std::vector;
using std::pair;
using namespace std;


int main()
{
	int premaxnum = INT_MIN;
	int m = 0, n = 0;
	cin >> n;
	cin >> m;
	vector<vector<int>> dp(2, vector<int>(n, 0));
	vector<int>value(n, 0);
	for (int i = 0; i<n; i++) {
		cin >> value[i];
	}

	dp[1][0] = value[0];
	int output = INT_MIN;
	for (int i = 1; i<=m; i++) {
		premaxnum = INT_MIN;
		for (int j = i; j<n-(m-i); j++) {
			premaxnum = max(dp[(i - 1)&1][j - 1], premaxnum);
			dp[i&1][j] = max(premaxnum, dp[i&1][j - 1]) + value[j];
			output = max(output, dp[i&1][j]);	
		}
	}
	cout << output;
	return 0;
}