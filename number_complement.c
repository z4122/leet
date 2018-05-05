
#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int findComplement(int num) {
	int temp = num;
	int j = 1;
	while (temp = temp >> 1)
	{
		j++;//总共有K位
	}
	
	temp = (1 << j)-num-1;

	return temp;
}


int findComplement_2(int num) {
	unsigned long mask = 0xffffffff;
	while (num&mask)
		mask = mask << 1;


	return (num^ ~mask);
}

int main()
{
	int a = findComplement_2(5);
	//printf("%d\n", test);
	return 0;
}