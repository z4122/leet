#include "stdafx.h"
#include "stdio.h"
#include "string.h"



void adjustHeap(int parm,int length,int* input)
{
	int temp = input[parm];
	for (int node = parm * 2 + 1; node < length; node = node * 2 + 1)
	{
		if (input[node] < input[node + 1])
			node++;
		if ((node < length) && (input[node] > temp))
		{
			input[parm] = input[node];
			parm = node;
		}
		else
			break;
	}
	input[parm] = temp;
}

//堆排序是一种选择排序，它的最坏，最好，平均时间复杂度均为O(nlogn)，它也是不稳定排序。
void HeapSort(int* input,int length)
{
	int temp = 0;
	for(int i = length/2-1;i>=0;i--)
		adjustHeap(i, length, input);
	for (int i = length - 1; i >= 0; i--)
	{
		temp = input[0];
		input[0] = input[i];
		input[i] = temp;

		adjustHeap(0, i, input);
	}
}


int main()
{
	int temp[9] = { 15,10,30,35,25,23,643,234,23 };
	HeapSort(temp, 9);
	for (int i = 0; i < 9; i++)
		printf("%d ", temp[i]);
	return 0;
}