// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

#include "vector"
#include "stack"
#include "iostream"

using namespace std;
#define Bnd(X,bnd) (sizeof(X)+(bnd)&~(bnd))

struct BinaryTreeNode
{
	int val;
	BinaryTreeNode* leftNode;
	BinaryTreeNode* rightNode;
	BinaryTreeNode(int x) :val(x),leftNode(nullptr),rightNode(nullptr){};
};


void recursion(BinaryTreeNode *root, int value, vector<int>& temp)
{
	temp.push_back(root->val);
	if (value == root->val)
	{
		for (int val : temp)
			printf("%d", val);
	}
	else if (value < root->val)
	{

	}
	else
	{
		if (root->leftNode != nullptr)
			recursion(root->leftNode, value - root->val, temp);
		if (root->rightNode != nullptr)
			recursion(root->rightNode, value - root->val, temp);
	}
	temp.pop_back();
}


void pathAll(BinaryTreeNode* root, int value)
{
	if (root == nullptr)
		return ;

	vector<int> temp;
	recursion(root, value, temp);
}


int main()
{

	BinaryTreeNode* a = new BinaryTreeNode(10);
	BinaryTreeNode* b = new BinaryTreeNode(5);
	BinaryTreeNode* c = new BinaryTreeNode(12);
	BinaryTreeNode* d = new BinaryTreeNode(4);
	BinaryTreeNode* e = new BinaryTreeNode(7);

	a->leftNode = b;
	a->rightNode = c;
	b->leftNode = d;
	b->rightNode = e;
	pathAll(a, 22);
	
	system("pause");
	return 0;
}