// DataStructure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include "BinaryTree.h"
#include "IntData.h"
#include "HoffmanTree.h"

using namespace learn_data_structure;

int _tmain(int argc, _TCHAR* argv[])
{
#if 0
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
#endif
	HoffmanTree hoffmanTree;
	HoffmanData hoffmanData[10];
	hoffmanData[0].SetCode('a');
	hoffmanData[0].SetWeight(5);
	hoffmanData[1].SetCode('b');
	hoffmanData[1].SetWeight(2);
	hoffmanData[2].SetCode('c');
	hoffmanData[2].SetWeight(8);
	hoffmanData[3].SetCode('d');
	hoffmanData[3].SetWeight(4);
	hoffmanData[4].SetCode('e');
	hoffmanData[4].SetWeight(6);
	hoffmanData[5].SetCode('f');
	hoffmanData[5].SetWeight(3);
	hoffmanData[6].SetCode('g');
	hoffmanData[6].SetWeight(6);
	hoffmanData[7].SetCode('h');
	hoffmanData[7].SetWeight(1);
	hoffmanData[8].SetCode('i');
	hoffmanData[8].SetWeight(7);
	hoffmanData[9].SetCode('j');
	hoffmanData[9].SetWeight(9);
	BinaryNode* tree = hoffmanTree.CreateHoffmanTree(hoffmanData, 10);
	hoffmanTree.PrintLeft();
	HoffmanMap* map = hoffmanTree.CreateHoffmanMap(tree);
	for (HoffmanMap::iterator it = map->begin(); it != map->end(); ++it)
	{
		printf("%c:%s ", it->first, it->second.c_str());
	}
	printf("\n");
	system("pause");
	return 0;
}

