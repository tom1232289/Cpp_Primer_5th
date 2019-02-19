#pragma once

#ifndef BIN_STR_TREE_H
#define BIN_STR_TREE_H

#include <iostream>
#include "TreeNode.h"

using namespace std;

class BinStrTree
{
public:
	BinStrTree() :
		root(new TreeNode()) 
	{	}
	BinStrTree(const BinStrTree &bst):
		root(new TreeNode(*bst.root))
	{	}
	BinStrTree & operator=(const BinStrTree &rhs);
	~BinStrTree() {
		delete root;
	}

private:
	TreeNode *root;
};

BinStrTree & BinStrTree::operator=(const BinStrTree &rhs)
{
	auto newRoot = new TreeNode(*rhs.root);
	delete root;
	root = newRoot;
	return *this;
}

#endif	// !BIN_STR_TREE_H