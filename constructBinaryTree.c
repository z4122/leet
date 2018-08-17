//

#include "stdafx.h"
#include "stdio.h"

#include "iostream"

using namespace std;
#define Bnd(X,bnd) (sizeof(X)+(bnd)&~(bnd))

struct BinaryTreeNode
{
	int val;
	BinaryTreeNode* leftNode;
	BinaryTreeNode* rightNode;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,
	int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,
	int* startInorder, int* endInorder)
{
	int val = *startPreorder;
	BinaryTreeNode* root = new BinaryTreeNode;
	root->val = val;
	root->leftNode = nullptr;
	root->rightNode = nullptr;

	if (startInorder == endInorder)
		return root;

	int leftLength = 0;
	while (startInorder+leftLength < endInorder&&*(startInorder+leftLength) != val)
		leftLength++;
	if (startInorder+leftLength == endInorder && *(startInorder+leftLength) != val)
		throw exception("Invalid input");

	if(leftLength>0)
		root->leftNode = ConstructCore(startPreorder + 1, startPreorder + leftLength, startInorder, startInorder + leftLength);
	if(leftLength<endPreorder-startPreorder)
		root->rightNode = ConstructCore(startPreorder + leftLength + 1, endPreorder, startInorder + leftLength + 1, endInorder);
	return root;
}


int main()
{
	int preorder[] = { 1,2,4,7,3,5,6,8 };
	int inorder[] = { 4,7,2,1,5,3,8,6 };
	BinaryTreeNode* root = Construct(preorder, inorder, 8);
	system("pause");
	return 0;
}