#include "stdafx.h"
#include "BinaryTreeTest.h"

#include <stdio.h>
#include "BinaryTree.h"
#include "IntData.h"

using namespace learn_data_structure;
bool BinaryTreeTest::Test()
{
	BinaryTree binaryTree;
	BinaryNode* root = binaryTree.CreatRoot(new IntData(0));
	if (NULL == root)
	{
		printf("Create root failed!");
	}
	BinaryNode* lChild = binaryTree.AddLeft(root, new IntData(1));
	if (NULL == lChild)
	{
		printf("Add left child failed!");
	}
	BinaryNode* rChild = binaryTree.AddRight(root, new IntData(2));
	if (NULL == rChild)
	{
		printf("Add right child failed!");
	}
	binaryTree.PrintLeft();
	binaryTree.PrintMiddle();
	binaryTree.PrintRight();
	return true;
}