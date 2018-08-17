// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

#include "iostream"

using namespace std;
#define Bnd(X,bnd) (sizeof(X)+(bnd)&~(bnd))


int Increment(string &input)
{
	int n = input.size()-1;
	if (input[n] == '9')
	{
		while (input[n] == '9')
			input[n--] = '0';
	}
	input[n]++;

	if (input[0] == '1')
		return 1;
	else
		return 0;
}

void print_num(string tmp)
{
	int n = 0;
	while (tmp[n] == '0')
		n++;
	for(int i = n;i<tmp.size();i++)
			printf("%c", tmp[i]);
	printf("\n");
	
}

void Print(int n)
{
	if (n < 0)
		return;
	string tmp(n+1, '0');

	while (!Increment(tmp))
	{
		print_num(tmp);
	}

}

int main()
{
	Print(3);
	system("pause");
	return 0;
}