#include "stdafx.h"
#include<stdio.h>
#include"string"
#include "vector"
#include<algorithm>
using namespace std;

int longestSubstringWithoutDuplication(const std::string& str)
{
	if (str.size() <= 0)
		return 0;

	int len = str.size();
	int output = 0;
	vector<int> vDuplication(len, 1);

	for (int i = 1; i<len; i++)
	{
		for (int j = 1; j<=vDuplication[i-1]; j++)
			if (str[i - j] == str[i])
			{
				vDuplication[i] = j;
				break;
			}			
			else
			{
				vDuplication[i]++;
				continue;
			}
	}

	for (auto val : vDuplication)
	{
		output = max(output, val);
	}
	return output;
}


int main()
{
	string temp("arabcacfr");
	longestSubstringWithoutDuplication(temp);
	return 0;
}