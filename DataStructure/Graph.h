#include "DataInterface.h"
#include <queue>

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
		virtual IEdge* New() = 0;
		//virtual IEdge& operator[](size_t n) = 0;
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
				printf("%d", weight_);
			}
			else
			{
				printf("*");
			}
		}
		virtual IEdge* New()
		{
			return new WeightEdge(false, 0);
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
	struct EdgeLink
	{
		IEdge* edge;
		size_t linkVertexeIndex;
		EdgeLink* next;
	};
	struct VertexeLink
	{
		IData* data;
		EdgeLink* edge;
	};
	class Graph
	{
	public:
		Graph()
		{
			graph_.vertexe = NULL;
			graph_.edge = NULL;
			graph_.egdeNum = 0;
			graph_.vertexeNum = 0;
		}
		virtual ~Graph()
		{
			Delete();
		}
		bool CreateByMatrix(IData* vertexes, IEdge* edges, size_t vertexeNum, size_t egdeNum)
		{
			if (NULL == vertexes || NULL == edges)
				return false;
			Delete();
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
		bool CreateByLink(VertexeLink* vertexeLinks, size_t vertexeNum)
		{
			if (NULL == vertexeLinks)
				return false;
			// 假设不存在孤点
			if (vertexeLinks[0].edge == NULL)
				return false;
			
			Delete();
			size_t edgeSize = vertexeLinks[0].edge->edge->Size();
			size_t vertexeSize = vertexeLinks->data->Size();
			graph_.vertexe = reinterpret_cast<IData*>(malloc(vertexeNum * vertexeSize));
			graph_.edge = reinterpret_cast<IEdge*>(malloc(vertexeNum * vertexeNum * edgeSize));
			char* vertexeHead = reinterpret_cast<char*>(graph_.vertexe);
			char* edgeHead = reinterpret_cast<char*>(graph_.edge);
			EdgeLink* nextEdge = NULL;
			size_t count = 0;
			bool* exist = new bool[vertexeNum];
			for (size_t i = 0; i < vertexeNum; ++i)
			{
				exist[i] = false;
			}
			for (size_t i = 0; i < vertexeNum; ++i)
			{
				memcpy(vertexeHead + i * vertexeSize, vertexeLinks[i].data, vertexeSize);
				nextEdge = vertexeLinks[i].edge;
				count = 0;
				for (size_t j = 0; j < vertexeNum; ++j)
				{
					exist[j] = false;
				}
				while (NULL != nextEdge)
				{
					memcpy(edgeHead + i * edgeSize * vertexeNum + nextEdge->linkVertexeIndex * edgeSize, nextEdge->edge, edgeSize);
					exist[nextEdge->linkVertexeIndex] = true;
					nextEdge = nextEdge->next;
				}
				for (size_t j = 0; j < vertexeNum; ++j)
				{
					if (!exist[j])
					{
						memcpy(edgeHead + i * edgeSize * vertexeNum + j * edgeSize, vertexeLinks[i].edge->edge->New(), edgeSize);
					}
				}
			}
			delete exist;
			graph_.vertexeNum = vertexeNum;
			return true;
		}
		void Delete()
		{
			if (graph_.vertexe)
				free(graph_.vertexe);
			if (graph_.edge)
				free(graph_.edge);
			graph_.vertexe = NULL;
			graph_.edge = NULL;
			graph_.egdeNum = 0;
			graph_.vertexeNum = 0;
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
			printf("    ");
			for (size_t i = 0; i < graph_.vertexeNum; ++i)
			{
				printf("v%d ", i);
			}
			printf("\n");
			for (size_t i = 0; i < graph_.vertexeNum; ++i)
			{
				printf("v%d| ", i);
				for (size_t j = 0; j < graph_.vertexeNum; ++j)
				{
					pEdge = reinterpret_cast<IEdge*>(head);
					//printf("v%d->v%d:", i, j);
					pEdge->Print();
					printf("  ");
					head += pEdge->Size();
				}
				printf("|\n");
			}
			printf("\n");
		}
		void DFS(GraphNode* graph, size_t count, bool* visit)
		{
			size_t adgeSize = graph->edge->Size();
			size_t vertexeSize = graph->vertexe->Size();
			char* edgeHead = reinterpret_cast<char*>(graph->edge);
			char* vertexeHead = reinterpret_cast<char*>(graph_.vertexe);
			IData* vertexe = reinterpret_cast<IData*>(vertexeHead + count * vertexeSize);
			printf("v%d:", count);
			vertexe->Print();
			printf(" ");
			visit[count] = true;
			for (size_t i = 0; i < graph->vertexeNum; ++i)
			{
				IEdge* adge = reinterpret_cast<IEdge*>(edgeHead + count * graph_.vertexeNum * adgeSize + i * adgeSize);
				if (adge->Exist() && !visit[i])
				{
					DFS(graph, i, visit);
				}
			}
		}
		void DFSTraverse()
		{
			if (graph_.vertexe == NULL || graph_.edge == NULL)
				return;
			bool* visit = new bool[graph_.vertexeNum];
			for (size_t i = 0; i < graph_.vertexeNum; ++i)
			{
				visit[i] = false;
			}
			for (size_t i = 0; i < graph_.vertexeNum; ++i)
			{
				if (!visit[i])
					DFS(&graph_, i, visit);
			}
		}
		void BFSTraverse()
		{
			if (graph_.vertexe == NULL || graph_.edge == NULL)
				return;
			bool* visit = new bool[graph_.vertexeNum];
			for (size_t i = 0; i < graph_.vertexeNum; ++i)
			{
				visit[i] = false;
			}
			std::queue<size_t> dataQueue;
			size_t adgeSize = graph_.edge->Size();
			size_t vertexeSize = graph_.vertexe->Size();
			char* edgeHead = reinterpret_cast<char*>(graph_.edge);
			char* vertexeHead = reinterpret_cast<char*>(graph_.vertexe);
			for (size_t i = 0; i < graph_.vertexeNum; ++i)
			{
				if (!visit[i])
				{
					IData* vertexe = reinterpret_cast<IData*>(vertexeHead + i * vertexeSize);
					printf("v%d:", i);
					vertexe->Print();
					printf(" ");
					visit[i] = true;
					dataQueue.push(i);
				}
				while (!dataQueue.empty())
				{
					size_t index = dataQueue.front();
					dataQueue.pop();
					IEdge* adge = reinterpret_cast<IEdge*>(edgeHead + i * graph_.vertexeNum * adgeSize + index * adgeSize);
					if (adge->Exist() && !visit[index])
					{
						IData* vertexe = reinterpret_cast<IData*>(vertexeHead + index * vertexeSize);
						printf("v%d:", index);
						vertexe->Print();
						printf(" ");
						visit[index] = true;
						dataQueue.push(index);
					}
				}
			}
		}
	private:
		GraphNode graph_;
	};
}