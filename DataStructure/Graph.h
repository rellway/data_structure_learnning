#include "DataInterface.h"

namespace learn_data_structure
{
	class IEdge
	{
	public:
		IEdge(){};
		virtual ~IEdge(){};
		virtual bool Exist() = 0;
		virtual size_t Size() = 0;
		virtual void Print() = 0;
	};
	class WeightEdge : public IEdge
	{
	public:
		WeightEdge(bool exist, int weight) :exist_(exist), weight_(weight){};
		virtual ~WeightEdge(){};
		virtual bool Exist()
		{
			return exist_;
		}
		int GetWeight()
		{
			return weight_;
		}
		virtual size_t Size()
		{
			return sizeof(WeightEdge);
		}
		virtual void Print()
		{
			if (exist_)
			{
				printf("weight:%d", weight_);
			}
			else
			{
				printf("not exist");
			}
			
		}
	private:
		bool exist_;
		int weight_;
	};
	struct GraphNode
	{
		IData* vertexe;
		IEdge* edge;
		size_t vertexeNum;
		size_t egdeNum;
	};
	class Graph
	{
	public:
		Graph(){};
		virtual ~Graph(){};
		bool CreateByMatrix(IData* vertexes, IEdge* edges, size_t vertexeNum, size_t egdeNum)
		{
			if (NULL == vertexes && NULL == edges)
				return false;
			graph_.vertexeNum = vertexeNum;
			graph_.egdeNum = egdeNum;
			graph_.vertexe = reinterpret_cast<IData*>(malloc(vertexeNum * vertexes->Size()));
			if (NULL == graph_.vertexe)
				return false;
			memcpy(graph_.vertexe, vertexes, vertexeNum * vertexes->Size());
			graph_.edge = reinterpret_cast<IEdge*>(malloc(vertexeNum * vertexeNum * edges->Size()));
			if (NULL == graph_.edge)
				return false;
			memcpy(graph_.edge, edges, vertexeNum * vertexeNum * edges->Size());
			return true;
		}
		void PrintVertexe()
		{
			if (NULL == graph_.vertexe)
			{
				printf("vertexes not exist!\n");
				return;
			}
			IData* pVertexe = NULL;
			char* head = reinterpret_cast<char*>(graph_.vertexe);
			for (size_t i = 0; i < graph_.vertexeNum; ++i)
			{
				pVertexe = reinterpret_cast<IData*>(head);
				printf("v%d:", i);
				pVertexe->Print();
				printf(" ");
				head += pVertexe->Size();
			}
			printf("\n");
		}
		void PrintDdges()
		{
			if (NULL == graph_.edge)
			{
				printf("edges not exist!\n");
				return;
			}
			IEdge* pEdge = NULL;
			char* head = reinterpret_cast<char*>(graph_.edge);
			for (size_t i = 0; i < graph_.vertexeNum; ++i)
			{
				for (size_t j = 0; j < graph_.vertexeNum; ++j)
				{
					pEdge = reinterpret_cast<IEdge*>(head);
					printf("v%d->v%d:", i, j);
					pEdge->Print();
					printf(" ");
					head += pEdge->Size();
				}
				printf("\n");
			}
			printf("\n");
		}
	private:
		GraphNode graph_;
	};
}