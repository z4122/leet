
#include "stdafx.h"
#include "stdio.h"
#include "string.h"

using namespace std;



void shellsort(int* input, int length)
{
	int temp = 0;
	int group_num = length;
	while (group_num != 0)
	{
		group_num = group_num / 2;
		for (int i = 0; i < group_num; i++)//分成几个组
		{
			for (int j = 0; j < length-group_num; j+=group_num)//对组内变量遍历
			{
				for (int k = 0; k < length - group_num-j; k++)
				{
					if (input[k] > input[k + group_num])
					{
						temp = input[k + group_num];
						input[k + group_num] = input[k];
						input[k] = temp;
					}
				}
				
			}
			
		}

	}
}

int main()
{
	int temp[] = { 8,9,1,7,2,3,5,4,6,0,11 };
	shellsort(temp, 11);
	return 0;
}