
#include "stdafx.h"
#include "stdio.h"
#include "vector"
#include "string"
#include "algorithm"
#include "map"
#include "iostream"

using namespace std;
#define Bnd(X,bnd) (sizeof(X)+(bnd)&~(bnd))

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {};
};

ListNode* addNode(ListNode **input,int val)
{
	if (*input == NULL)
	{
		*input = new ListNode(val);
	}
	else
	{
		ListNode* tmpNode = *input;
		while (tmpNode->next != NULL)
			tmpNode = tmpNode->next;
		
		tmpNode->next = new ListNode(val);
	}
	return *input;
}

ListNode* cListNode(vector<int>input)
{
	ListNode* head = new ListNode(input[0]);
	ListNode* next = head;
	for(int i = 1;i<input.size();i++)
	{
		ListNode* tmp = new ListNode(input[i]);
		next->next = tmp;
		next = next->next;
	}
	return head;
}

int main()
{
	vector<int> tmp = { 1,2,3,4,5 };
	ListNode *head = cListNode(tmp);

	system("pause");
	return 0;
}