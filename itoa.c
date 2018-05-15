#include "stdafx.h"
#include "stdio.h"

#include "string"
using namespace std;

char* int2char(int nums)
{
	int temp = 1;
	int len = 0;
	char *gchar = NULL;
	while (nums>temp)
	{
		temp = temp * 10;
		len++;
	}
	gchar = (char*)malloc(sizeof(char)*(len + 1));
	temp = 10;
	gchar[len] = '\0';
	while (len--)
	{
		gchar[len] = nums % temp+'0';
		nums = nums / 10;
	}
	return gchar;
}


int main()
{
	
	int c[1] = { 0 };
	int test = 39990;
	char *temp = NULL;
	temp = int2char(test);
	test = 34520;
	sprintf_s(temp,6, "%d",test);
	

	return 0;
}