// DataStructure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include "BinaryTreeTest.h"
#include "HoffmanTreeTest.h"
#include "HoffmanTree.h"
#include "GraphTest.h"
#include "gtest\gtest.h"
#include "TrieTree.h"

using namespace learn_data_structure;

int _tmain(int argc, _TCHAR* argv[])
{
	//BinaryTreeTest::Test();
	//HoffmanTreeTest::Test();
	//GraphTest::Test();
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}

