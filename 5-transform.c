// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "vector"
#include "string"
#include "algorithm"
#include "map"
#include "iostream"

using namespace std;
#define Bnd(X,bnd) (sizeof(X)+(bnd)&~(bnd))

class test
{


public:
	test()
	{
		str1 = new char[20];
		strcpy_s(str1, 13, "We are happy");
	}

	void show()
	{

		printf("%d\t%s\n", sizeof(str1),str1);
	}
	void transform()
	{
		int size = 0;
		while (str1[size] != '\0')
		{
			size++;
		}
		int cnt = 0;
		for (int i = 0; i < size; i++)
			if (str1[i] == ' ')
				cnt++;
		for (int i = size + 2 * cnt; i > 0; i--,size--)
		{
			if (str1[size] == ' ')
			{
				str1[i] = '0';
				str1[i - 1] = '2';
				str1[i - 2] = '%';
				i -= 2;
			}
			else
			{
				str1[i] = str1[size];
			}

		}
	
	}



private:
	string str;
	char* str1;
};



int main()
{

	test test1, test2;

	test1.show();
	test1.transform();
	test1.show();

	system("pause");
	return 0;
}