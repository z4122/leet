

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
	int findMaxDepth(TreeNode* temp);

public:
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
	/*//还有一种fangfa
	TreeNode* node;
	int index = 0;
	while(index<input.size())
	{
		node = queue.front();
		queue.pop();
		queue.push(node[index++]);
		node.left = queue.back();
		queue.push(node[index++]);
		node.right = queue.back();
	}

	*/
	head = nodes[0];
}

/**
*	@param:层次遍历

*/
void BinaryTree::printIntire()
{
	queue<TreeNode*> nodeQueue;
	TreeNode* tempNode;
	nodeQueue.push(head);
	while (nodeQueue.empty() == 0)
	{
		tempNode = nodeQueue.front();
		nodeQueue.pop();
		printf("%d\t", tempNode->val);
		if(tempNode->left!=NULL)
			nodeQueue.push(tempNode->left);
		if(tempNode->right!=NULL)
			nodeQueue.push(tempNode->right);
	}
}

/**
*	@param:寻找最大的深度

*/
int BinaryTree :: findMaxDepth(TreeNode* temp)
{
	static int depth = 0;
	static int maxDepth = 0;
	depth++;
	if(temp->left!=NULL)
		findMaxDepth(temp->left);
	if(temp->right!=NULL)
		findMaxDepth(temp->right);
	maxDepth = max(maxDepth, depth);
	depth--;
	return maxDepth;
}
int main()
{
	vector<string> a = { "1", "2", "3", "4", "5", "6","7" };
	BinaryTree* test = new BinaryTree(a);
	test->printIntire();
	printf("%d", test->findMaxDepth(test->head));




	system("pause");
	return 0;
}

