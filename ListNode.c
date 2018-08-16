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

class ListNode
{
public:
	ListNode(int x) :val(x), next(nullptr) {};
	ListNode* addNode(ListNode **input, int val);
	ListNode* cListNode(vector<int>input);
	void printListNode();

public:
	int val;
	ListNode* next;
	
};

ListNode* ListNode::addNode(ListNode **input,int val)
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

ListNode* ListNode::cListNode(vector<int>input)
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

void ListNode::printListNode()
{
	ListNode*head = this;
	vector<int> tmp;
	while (head != NULL)
	{
		tmp.push_back(head->val);
		head = head->next;
	}
	for (auto i = tmp.rbegin(); i != tmp.rend(); i++)
	{
		printf("%d\n", *i);
	}

}

int main()
{
	vector<int> tmp = { 1,2,3,4,5 };
	ListNode *head = NULL;
	head = head->cListNode(tmp);
	head->printListNode();
	system("pause");
	return 0;
}