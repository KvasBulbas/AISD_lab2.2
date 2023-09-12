#include "BinaryTree.h"
#include <iostream>

void BinaryTree::clearTree(Node* subTreeRoot)
{
	if (subTreeRoot == nullptr)
		return;


	if (subTreeRoot->left)
		clearTree(subTreeRoot->left);
	if (subTreeRoot->right)
		clearTree(subTreeRoot->right);

	if (subTreeRoot == _root)
		_root = nullptr;

	delete subTreeRoot;
}

BinaryTree::~BinaryTree()
{
	if (_root)
		clearTree(_root);
}

void BinaryTree::clearTree()
{
	clearTree(_root);
}
