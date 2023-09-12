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

bool BinaryTree::isEmpty() const
{
	if (_root)
		return true;
	return false;
}

BinaryTree::Node* BinaryTree::addNode(const int k)
{
	return addNode(_root, k);

}

BinaryTree::Node* BinaryTree::addNode(Node* nd, const int k)
{
	if (nd == nullptr)
		if (_root == nullptr)
		{
			_root = new Node(k);
			return _root;
		}
		else
			return nullptr;


	if (nd->left == nullptr)
	{
		nd->left = new Node(k);
		return nd->left;
	}

	if (nd->right == nullptr)
	{
		nd->right = new Node(k);
		return nd->right;
	}

	if (rand() % 2)
		return addNode(nd->left, k);
	else
		return addNode(nd->right, k);

}

int BinaryTree::getHeight() const
{
	return getHeight(_root);
}

int BinaryTree::getHeight(Node* nd) const
{

	if (nd == nullptr)
		return 0;

	if ((nd->left == nullptr) && (nd->right == nullptr))
		return 1;

	int leftHeight = 0, rightHeight = 0;

	if (nd->left)
		leftHeight = getHeight(nd->left);

	if (nd->right)
		rightHeight = getHeight(nd->right);

	int height;

	if (rightHeight > leftHeight)
		height = rightHeight;
	else
		height = leftHeight;

	return height + 1;


}



