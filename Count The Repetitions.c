
#include "stdafx.h"
#include "stdio.h"
#include "string.h"

using namespace std;

int getMaxRepetitions(char* s1, int n1, char* s2, int n2) {
	int i = 0, j = 0;
	int num = 0;
	int num_s1 = strlen(s1);
	int num_s2 = strlen(s2);
	while (n1!=0)
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
			i++;
		if (i == num_s1)
		{
			i = 0;
			n1--;
		}
		if (j == num_s2)
		{
			j = 0;
			num++;
		}	
	}
	num = num / n2;
	return num;
}

int main()
{

	char a[] = "a";
	char b[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int temp = getMaxRepetitions(a, 1000000, b, 1000);	
	return 0;
}