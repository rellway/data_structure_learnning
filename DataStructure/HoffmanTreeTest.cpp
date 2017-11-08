#include "stdafx.h"
#include "HoffmanTreeTest.h"


#include <stdio.h>
#include "HoffmanTree.h"

using namespace learn_data_structure;

bool HoffmanTreeTest::Test()
{
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
	//hoffmanTree.PrintLeft();
	HoffmanMap* map = hoffmanTree.CreateHoffmanMap(tree);
	for (HoffmanMap::iterator it = map->begin(); it != map->end(); ++it)
	{
		printf("%c:%s ", it->first, it->second.c_str());
	}
	printf("\n");
	return true;
}