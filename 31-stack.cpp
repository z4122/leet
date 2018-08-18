// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

#include "vector"
#include "stack"
#include "iostream"

using namespace std;
#define Bnd(X,bnd) (sizeof(X)+(bnd)&~(bnd))

int compare(vector<int>pushline, vector<int>popline)
{
	stack<int> assistStack;
	int i = 0, j = 0;
	while (i<pushline.size() || j<popline.size())
	{
		if (assistStack.empty() || assistStack.top() != popline[j])
		{
			if (i < pushline.size())
			{
				assistStack.push(pushline[i]);
				i++;
			}
			else
				break;
		}
		else
		{
			if (j < popline.size())
			{
				assistStack.pop();
				j++;
			}
			else
				break;
		}
	}
	if (i == pushline.size() && j == popline.size())
		return 1;
	else
		return 0;
}


int main()
{
	vector<int> a = { 1,2,3,4,5 };
	vector<int> b = { 4,3,5,1,2 };
	int c = compare(a, b);
	
	system("pause");
	return 0;
}