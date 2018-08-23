#include "stdafx.h"
#include<stdio.h>
#include"string"
#include "vector"
#include "iostream"
#include<algorithm>
using namespace std;


#include <stdio.h>
#include <vector>
#include <string>
#include <queue>


struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class BinaryTree
{
public:
	BinaryTree(vector<string>);
	~BinaryTree() {};

	void printPreorder();
	void printInorder();
	void printPostorder();

	void printIntire();

private:
	TreeNode * head;

};


BinaryTree::BinaryTree(vector<string>input)
{
	if (input.size() < 1)
		return;

	TreeNode** nodes = new TreeNode*[input.size()];

	
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i][0] == ' ')
			nodes[i] = NULL;
		else
			nodes[i] = new TreeNode(atoi(input[i].c_str()));
	}

	int i = 0;
	while (i<input.size())
	{
		if(i*2+1<input.size())
			nodes[i]->left = nodes[i * 2+1];
		if(i*2+2<input.size())
			nodes[i]->right = nodes[i * 2 + 2];
		i++;
	}

	head = nodes[0];
}


int main()
{
	vector<string> a = { "1", "2", "3", "4", "5", "6","7" };
	BinaryTree* test = new BinaryTree(a);






	system("pause");
	return 0;
}

