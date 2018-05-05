
#include "stdafx.h"
#include "stdio.h"
#include "string.h"



void quicksort(int* input, int left, int right)
{
	int key = input[left];
	int i = left, j = right;
	if (left >= right)
		return;
	while (i<j)
	{
		while ((i<j) && (key>=input[j]))
			j--;
		input[i] = input[j];
		while ((i<j) && (key<=input[i]))
			i++;
		input[j] = input[i];
	}
	input[j] = key;

	quicksort(input, left, i - 1);
	quicksort(input, j + 1, right);

}

int hIndex(int* citations, int citationsSize) {
	int temp = 0;
	quicksort(citations, 0, citationsSize - 1);
	for (int i = 0; i<citationsSize; i++)
	{
		if (citations[i] >= (i + 1))
			temp = i + 1;
	}

	return temp;
}
int main()
{
	int test[2] = { 0,0 };
	int a = hIndex(test, 2);
	printf("%d\n", a);
	return 0;
}