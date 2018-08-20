#include "stdafx.h"
#include<stdio.h>
#include"string"
#include "vector"
#include<algorithm>
using namespace std;

#include "stdafx.h"
#include<stdio.h>
#include"string"
#include "vector"
#include<algorithm>
using namespace std;


int times(vector<int> input,int target)
{
	int index = input.size()/2, left = 0, right = 0;
	int i = 0, j = input.size()-1;
	while (input[index] != target)
	{
		if (input[index] < target)
			index = (index + input.size()) / 2;
		else
			index = index / 2;
	}
	
	left = right = index;

	if (input[i] == target)
		left = i;
	if (input[j] == target)
		right = j;

	while (input[i]!=target&&input[left] == target )
	{
		if (input[(i + left) / 2] == target)
			left = (i + left) / 2;
		else
			i = (i + left) / 2;

		if (i + 1 == left)
			break;
	}

	while (input[j] != target && input[right] == target)
	{
		if (input[(j + right) / 2] == target)
			right = (j + right) / 2;
		else
			j = (j + right) / 2;

		if (right + 1 == j)
			break;
	}

	return right - left + 1;

}

int main()
{
	vector<int> a = { 1,2,3,3,3,3,4,5 };
	int b = 3;
	times(a,b);
	return 0;
}

