#include "stdafx.h"
#include "GraphTest.h"

#include "Graph.h"
#include "IntData.h"

using namespace learn_data_structure;
bool GraphTest::Test()
{
	Graph graph;
	IntData vertexes[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	WeightEdge edges[10][10] = { 
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 }},
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } }
	};
	graph.CreateByMatrix(vertexes, reinterpret_cast<IEdge*>(edges), 10, 10);
	graph.PrintVertexe();
	graph.PrintDdges();
	return true;
}