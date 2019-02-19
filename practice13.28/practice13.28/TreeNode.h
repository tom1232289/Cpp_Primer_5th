#pragma once

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
public:
	TreeNode() :
		value(string()),
		count(new int(1)),
		left(nullptr),
		right(nullptr)
	{	}
	TreeNode(const string &s) :
		value(s),
		count(new int(1)),
		left(nullptr),
		right(nullptr)
	{	}
	TreeNode(const TreeNode &tn) :
		value(tn.value),
		count(tn.count),
		left(tn.left),
		right(tn.right)
	{
		++*count;
	}
	TreeNode & operator=(const TreeNode &rhs);
	~TreeNode();

private:
	string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

TreeNode::~TreeNode()
{
	if (--*count == 0) {
		if (left) {
			delete left;
			left = nullptr;
		}
		if (right) {
			delete right;
			right = nullptr;
		}
		delete count;
		count = nullptr;
	}
}

TreeNode & TreeNode::operator=(const TreeNode &rhs)
{
	++*rhs.count;
	if (--*count == 0) {
		if (left) {
			delete left;
			left = nullptr;
		}
		if (right) {
			delete right;
			right = nullptr;
		}
		delete count;
		count = nullptr;
	}
	value = rhs.value;
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;
	return *this;
}

#endif	// !TREE_NODE_H
