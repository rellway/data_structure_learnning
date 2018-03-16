#include "stdafx.h"
#include "gtest\gtest.h"
#include "TrieTree.h"
#include "CharData.h"
#include <vector>

using namespace learn_data_structure;
TEST(TrieTreeTest, TrieTreeTest_Print)
{
	/*
	CharData a('a');
	CharData b('b');
	CharData c('c');
	CharData d('d');
	CharData e('e');
	CharData f('f');
	CharData g('g');
	CharData h('h');

	TrieTree tree(a.Number());

	Word abc;
	abc.push_back(&a);
	abc.push_back(&b);
	abc.push_back(&c);
	tree.Insert(&abc);

	Word abcdefgh;
	abcdefgh.push_back(&a);
	abcdefgh.push_back(&b);
	abcdefgh.push_back(&c);
	abcdefgh.push_back(&d);
	abcdefgh.push_back(&e);
	abcdefgh.push_back(&f);
	abcdefgh.push_back(&g);
	abcdefgh.push_back(&h);
	tree.Insert(&abcdefgh);

	Word defgh;
	defgh.push_back(&d);
	defgh.push_back(&e);
	defgh.push_back(&f);
	defgh.push_back(&g);
	defgh.push_back(&h);
	tree.Insert(&defgh);

	Word hgfedcba;
	hgfedcba.push_back(&h);
	hgfedcba.push_back(&g);
	hgfedcba.push_back(&f);
	hgfedcba.push_back(&e);
	hgfedcba.push_back(&d);
	hgfedcba.push_back(&c);
	hgfedcba.push_back(&b);
	hgfedcba.push_back(&a);
	tree.Insert(&hgfedcba);
	*/
	TrieTree tree(26);
	CharWord abc("abc");
	tree.Insert(abc.GetWord());
	CharWord abcdefgh("abcdefgh");
	tree.Insert(abcdefgh.GetWord());
	CharWord defgh("defgh");
	tree.Insert(defgh.GetWord());
	CharWord hgfedcba("hgfedcba");
	tree.Insert(hgfedcba.GetWord());
	tree.Print();

	printf("\n");
}

TEST(TrieTreeTest, TrieTreeTest_Search)
{
	TrieTree tree(26);
	CharWord abc("abc");
	tree.Insert(abc.GetWord());
	CharWord abcdefgh("abcdefgh");
	tree.Insert(abcdefgh.GetWord());
	CharWord defgh("defgh");
	tree.Insert(defgh.GetWord());
	CharWord hgfedcba("hgfedcba");
	tree.Insert(hgfedcba.GetWord());
	ASSERT_EQ(tree.Search(defgh.GetWord()), true);
	CharWord dcba("dcba");
	ASSERT_EQ(tree.Search(dcba.GetWord()), false);
	CharWord ab("ab");
	ASSERT_EQ(tree.Search(ab.GetWord()), false);
	CharWord abcd("abcd");
	ASSERT_EQ(tree.Search(abcd.GetWord()), false);
}