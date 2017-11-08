#include <set>
#include <map>
#include <string>
#include "BinaryTree.h"

namespace learn_data_structure
{
	class HoffmanData : public IData
	{
	public:
		virtual void* GetData()
		{
			return &code_;
		}
		virtual void Print()
		{
			printf("%c:%d", code_, weight_);
		}
		virtual bool operator <(const IData& data) const
		{
			HoffmanData hoffmanData = dynamic_cast<const HoffmanData&>(data);
			return weight_ < hoffmanData.GetWeight();
		}
		virtual bool operator >(const IData& data) const
		{
			HoffmanData hoffmanData = dynamic_cast<const HoffmanData&>(data);
			return weight_ > hoffmanData.GetWeight();
		}
		virtual IData& operator =(const IData& data)
		{
			HoffmanData hoffmanData = dynamic_cast<const HoffmanData&>(data);
			weight_ = hoffmanData.GetWeight();
			code_ = hoffmanData.GetCode();
			return *this;
		}
		int GetWeight()
		{
			return weight_;
		}
		void SetWeight(int weight)
		{
			weight_ = weight;
		}
		int GetCode()
		{
			return code_;
		}
		void SetCode(char code)
		{
			code_ = code;
		}
		virtual size_t Size()
		{
			return sizeof(HoffmanData);
		}
	private:
		char code_;
		int weight_;
	};
	typedef std::map<char, std::string> HoffmanMap;
	class HoffmanTree : public BinaryTree
	{
	public:
		HoffmanTree(){};
		~HoffmanTree(){};
		bool Search(BinaryNode* node, std::string code, HoffmanMap* map)
		{
			if (!node->lchild && !node->rchild)
			{
				char* data = reinterpret_cast<char*>(node->data->GetData());
				if (NULL == data)
					return false;
				//printf("data:%c code:%s\n", *data, code.c_str());
				map->insert(std::pair<char, std::string>(*data, code));
				return true;
			}
			if (node->lchild)
			{
				//printf("lcode:%s\n", code.c_str());
				code += "0";
				if (!Search(node->lchild, code, map))
					return false;
			}
			if (node->rchild)
			{
				//printf("rcode:%s\n", code.c_str());
				code += "1";
				if (!Search(node->rchild, code, map))
					return false;
			}
		}
		HoffmanMap* CreateHoffmanMap(BinaryNode* hoffmanTree)
		{
			HoffmanMap* map = new HoffmanMap;
			std::string code = "";
			Search(hoffmanTree, code, map);
			return map;
		}
		BinaryNode* CreateHoffmanTree(HoffmanData* in, int num)
		{
			if (NULL == in)
				return false;
			HoffmanData* newData = NULL;
			BinaryNode node;
			std::multiset<BinaryNode> list;
			for (int i = 0; i < num; ++i)
			{
				newData = new HoffmanData(in[i]);
				if (NULL == newData)
					return NULL;
				node.data = newData;
				node.lchild = node.rchild = node.parent = NULL;
				list.insert(node);
				//printf("size:%d\n", list.size());
				newData = NULL;
			}
			BinaryNode* newNode = NULL;
			BinaryNode* node1, *node2;

			while (list.size() >= 2)
			{
				node1 = ListPop(&list);
				node2 = ListPop(&list);
				/*
				printf("pop:");
				node1->data->Print();
				printf(",");
				node2->data->Print();
				printf("\n");
				*/
				newData = new HoffmanData;
				newData->SetWeight(dynamic_cast<HoffmanData*>(node1->data)->GetWeight() +
					dynamic_cast<HoffmanData*>(node2->data)->GetWeight());
				//newData->SetCode('#');
				newNode = NewNode(newData);
				AddLeft(newNode, node1);
				AddRight(newNode, node2);
				list.insert(*newNode);
				SetRoot(newNode);
			}
			return GetRoot();
		}
		
	private:
		BinaryNode* ListPop(std::multiset<BinaryNode>* list)
		{
			/*
			printf("list before-");
			for (std::multiset<BinaryNode>::iterator it = list->begin(); it != list->end(); ++it)
			{
				BinaryNode printNode = *it;
				printNode.data->Print();
				printf(" ");
			}
			printf("\n");
			*/
			BinaryNode begin = *list->begin();
			BinaryNode* data = new BinaryNode(begin);
			list->erase(list->find(*list->begin()));
			/*
			printf("list after-");
			for (std::multiset<BinaryNode>::iterator it = list->begin(); it != list->end(); ++it)
			{
				BinaryNode printNode = *it;
				printNode.data->Print();
				printf(" ");
			}
			printf("\n");
			*/
			return data;
		}
		HoffmanMap map_;
		 
	};
}