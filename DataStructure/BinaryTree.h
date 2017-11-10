#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <stdio.h>
#include "stdafx.h"
#include "CommonDef.h"
#include "DataInterface.h"

namespace learn_data_structure
{
	struct BinaryNode
	{
		IData* data;
		BinaryNode* lchild;
		BinaryNode* rchild;
		BinaryNode* parent;
		bool operator <(const BinaryNode& node) const
		{
			return  *data < *node.data;
		}
		bool operator >(const BinaryNode& node) const
		{
			return *data > *node.data;
		}
		BinaryNode& operator =(const BinaryNode& node)
		{
			*data = *node.data;
			lchild = node.lchild;
			rchild = node.rchild;
			parent = node.parent;
		}
	};

	class BinaryTree
	{
	public:
		BinaryTree()
		{
			root_ = NULL;
		}
		virtual ~BinaryTree()
		{
			Delete();
		}
		BinaryNode* AddLeft(BinaryNode* node, IData* data)
		{
			if (NULL == data)
				return NULL;
			if (node->lchild != NULL)
				return NULL;
			else
			{
				BinaryNode* newNode = new BinaryNode;
				if (NULL == node)
				{
					return NULL;
				}
				newNode->data = data;
				node->lchild = newNode;
				newNode->parent = node;
				newNode->lchild = newNode->rchild = NULL;
				return node;
			}
		}
		BinaryNode* AddRight(BinaryNode* node, IData* data)
		{
			if (NULL == data)
				return NULL;
			if (node->rchild != NULL)
				return NULL;
			else
			{
				BinaryNode* newNode = new BinaryNode;
				if (NULL == node)
				{
					return NULL;
				}
				newNode->data = data;
				node->rchild = newNode;
				newNode->parent = node;
				newNode->lchild = newNode->rchild = NULL;
				return node;
			}
		}
		BinaryNode* AddLeft(BinaryNode* node, BinaryNode* lnode)
		{
			if (NULL == lnode)
				return NULL;
			if (node->lchild != NULL)
				return NULL;
			else
			{
				node->lchild = lnode;
				lnode->parent = node;
				return node;
			}
		}
		BinaryNode* AddRight(BinaryNode* node, BinaryNode* rnode)
		{
			if (NULL == rnode)
				return NULL;
			if (node->rchild != NULL)
				return NULL;
			else
			{
				node->rchild = rnode;
				rnode->parent = node;
				return node;
			}
		}
		BinaryNode* Create()
		{
			BinaryNode* root = new BinaryNode;
			if (NULL == root)
			{
				return NULL;
			}
			root->lchild = root->rchild = NULL;
			root_ = root;
			return root;
		}
		void SetRoot(BinaryNode* node)
		{
			root_ = node;
		}
		BinaryNode* GetRoot(void)
		{
			return root_;
		}
		BinaryNode* NewNode(IData* data)
		{
			if (NULL == data)
				return NULL;
			BinaryNode* node = new BinaryNode;
			if (NULL == node)
			{
				return NULL;
			}
			node->data = data;
			node->lchild = node->rchild = node->parent = NULL;
			return node;
		}
		BinaryNode* CreatRoot(IData* data)
		{
			if (NULL == data)
				return NULL;
			BinaryNode* root = new BinaryNode;
			if (NULL == root)
			{
				return NULL;
			}
			root->data = data;
			root->lchild = root->rchild = NULL;
			root_ = root;
			return root;
		}
		void PrintLeft(BinaryNode* node)
		{
			if (NULL == node)
				return;
			node->data->Print();
			printf(" ");
			PrintLeft(node->lchild);
			PrintLeft(node->rchild);
		}
		void PrintLeft()
		{
			if (NULL == root_)
			{
				printf("null tree!\n");
			}
			PrintLeft(root_);
			printf("\n");
		}
		void PrintMiddle(BinaryNode* node)
		{
			if (NULL == node)
				return;
			PrintMiddle(node->lchild);
			node->data->Print();
			printf(" ");
			PrintMiddle(node->rchild);
		}
		void PrintMiddle()
		{
			if (NULL == root_)
			{
				printf("null tree!\n");
			}
			PrintMiddle(root_);
			printf("\n");
		}
		void PrintRight(BinaryNode* node)
		{
			if (NULL == node)
				return;
			PrintRight(node->lchild);
			PrintRight(node->rchild);
			node->data->Print();
			printf(" ");
		}
		void PrintRight()
		{
			if (NULL == root_)
			{
				printf("null tree!\n");
			}
			PrintRight(root_);
			printf("\n");
		}
		void Delete(BinaryNode* node)
		{
			if (NULL == node)
				return;
			Delete(node->lchild);
			Delete(node->rchild);
			if (node->data)
			{
				delete node->data;
			}
		}
		void Delete()
		{
			Delete(root_);
		}
		private:
			BinaryNode* root_;
	};
} // end of namespace learn_data_structure
#endif