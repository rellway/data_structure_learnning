#include "stdafx.h"
#include "gtest\gtest.h"
#include "InterpolationSearch.h"
#include "IntData.h"
#include <vector>

using namespace learn_data_structure;
TEST(InterpolationSearch, InterpolationSearch_List)
{
	DataList list;
	int testNum = 10000;

	IData** data = new IData*[testNum];
	for (int i = 0; i < testNum; ++i)
	{
		data[i] = new IntData(i);
		list.push_back(data[i]);
	}

	size_t index;
	for (int i = 0; i < testNum; ++i)
	{
		InterpolationSearch::Search(list, IntData(i), index);
		ASSERT_EQ(index, i);
	}

	for (int i = 0; i < testNum; ++i)
	{
		delete(data[i]);
	}
	delete[] data;
}