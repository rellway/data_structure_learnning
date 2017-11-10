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
		{ { false, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 }},
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { false, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { false, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { false, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { false, 9 }, { false, 0 } },
		{ { true, 1 }, { false, 0 }, { true, 3 }, { false, 0 }, { true, 5 }, { false, 0 }, { true, 7 }, { false, 0 }, { true, 9 }, { false, 0 } }
	};
	//graph.CreateByMatrix(vertexes, reinterpret_cast<IEdge*>(edges), 10, 10);
	//graph.PrintVertexe();
	//graph.PrintDdges();


	IEdge* edge = NULL;
	VertexeLink vertexeLink[100];
	EdgeLink* edgeLink = NULL;
	EdgeLink* newEdgeLink = NULL;
	for (size_t i = 0; i < 20; ++i)
	{
		vertexeLink[i].data = new IntData(2 * i);
		for (size_t j = 0; j < 20; ++j)
		{
			if (i == j)
			{
				edge = new WeightEdge(false, 0);
			}
			else
			{
				edge = new WeightEdge(true, i + j);
			}
			newEdgeLink = new EdgeLink;
			newEdgeLink->edge = edge;
			newEdgeLink->linkVertexeIndex = j;
			newEdgeLink->next = edgeLink;
			edgeLink = newEdgeLink;
		}
		vertexeLink[i].edge = edgeLink;
	}
	printf("WeightEdge:%d\n", sizeof(WeightEdge));
	graph.CreateByLink(vertexeLink, 20);
	graph.PrintVertexe();
	graph.PrintDdges();
	printf("DFSTraverse - ");
	graph.DFSTraverse();
	printf("\n");
	printf("BFSTraverse - ");
	graph.BFSTraverse();
	printf("\n");
	return true;
}