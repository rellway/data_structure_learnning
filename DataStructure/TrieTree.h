#ifndef _TRIE_TREE_H_
#define _TRIE_TREE_H_
#include <stdio.h>
#include "stdafx.h"
#include "CommonDef.h"
#include "DataInterface.h"

namespace learn_data_structure
{
	struct TrieNode
	{
		TrieNode(IEnumData* data, size_t childNumber)
		{
			child_ = new TrieNode*[childNumber];
			for (size_t i = 0; i < childNumber; ++i)
			{
				child_[i] = NULL;
			}
			childNumber_ = childNumber;
			data_ = data;
			count_ = 1;
			exist_ = false;
		}
		IEnumData* data_;
		TrieNode** child_;
		TrieNode& operator =(const TrieNode& node)
		{
			data_ = node.data_;
			for (size_t i = 0; i < childNumber_; ++i)
			{
				child_[i] = node.child_[i];
			}
		}
		
		size_t count_;
		size_t childNumber_;
		bool exist_;
	};

	class TrieTree
	{
	public:
		TrieTree(size_t childNumber)
		{
			root_ = new TrieNode(NULL, childNumber);
			childNumber_ = childNumber;
		}
		virtual ~TrieTree()
		{
			//Delete();
		}

		bool Insert(Word* word)
		{
			if (NULL == word)
				return false;
			TrieNode* p = root_;
			for (WordIterator it = word->begin(); it != word->end(); ++it)
			{
				if (p->child_[(*it)->Location()] == NULL)
				{
					p->child_[(*it)->Location()] = new TrieNode(*it, childNumber_);
					if (p == root_)
					{
						printf("new node:");
						(*it)->Print();
						printf("(%p), child of root\n", p->child_[(*it)->Location()]);
					}
					else
					{
						printf("new node:");
						(*it)->Print();
						printf("(%p), child of ", p->child_[(*it)->Location()]);
						p->data_->Print();
						printf("\n");
					}
				}
				else
				{
					TrieNode* child = p->child_[(*it)->Location()];
					child->count_++;
					printf("old node:");
					(*it)->Print();
					if (p == root_)
					{
						printf("(%p) count = %d, child of root\n", p->child_[(*it)->Location()], p->child_[(*it)->Location()]->count_);
					}
					else
					{
						printf("(%p) count = %d, child of ", p->child_[(*it)->Location()], p->child_[(*it)->Location()]->count_);
						p->data_->Print();
					}

					printf("\n");
				}
				p = p->child_[(*it)->Location()];
			}
			p->exist_ = true;
		}
		bool Search(Word* word)
		{
			TrieNode* p = root_;
			for (WordIterator it = word->begin(); it != word->end(); ++it)
			{
				if (NULL == p->child_[(*it)->Location()])
					return false;
				else
				{
					p = p->child_[(*it)->Location()];
				}
			}
			if (p->exist_)
				return true;
			else
				return false;
		}
		void Print(TrieNode* node)
		{
			if (NULL != node->data_)
				node->data_->Print();
			for (size_t i = 0; i < node->childNumber_; i++)
			{
				if (NULL != node->child_[i])
				{
					Print(node->child_[i]);
				}
			}
		}
		void Print()
		{
			Print(root_);
		}
		/*
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
		*/
		private:
			TrieNode* root_;
			size_t childNumber_;
	};
} // end of namespace learn_data_structure
#endif