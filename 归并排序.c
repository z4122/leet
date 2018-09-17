#include "stdafx.h"
#include "stdio.h"
#include "string.h"

using namespace std;



void mergesort(int* input, int* temp, int left, int right)
{

	int step = (right + 1 - left) / 2;//(5+1-0)/2 = 3;(4+1-0)/2 = 2;
	int i = left, j = step + left;
	int m = left;
	if (right == left)
		return;
	mergesort(input, temp, left, left + step - 1);
	mergesort(input, temp, left + step, right);
	while (i <= left + step - 1 && j <= right)
	{
		if (input[i] < input[j])
			temp[m++] = input[i++];
		else
			temp[m++] = input[j++];
	}
	while (i <= left + step - 1)
		temp[m++] = input[i++];
	while (j <= right)
		temp[m++] = input[j++];
	m = right - left+1;
	while (m--)
		input[left + m ] = temp[left + m];
}

int main()
{
	int input[] = { 8,9,1,7,2,3,5,4,6,0,11 };
	int temp[11] = { 0 };
	mergesort(input, temp,0,10);
	return 0;
}