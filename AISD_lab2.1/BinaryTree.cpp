#include "BinaryTree.h"
#include <iostream>
#include <vector>

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


void BinaryTree::printTree()
{
	return printTree(_root);
}

void BinaryTree::printTree(Node* nd)
{
	if (nd == nullptr)
	{
		std::cerr << "Tree is empty";
		return;
	}

	int height = getHeight(nd);

	for (int level = 0; level < height; level++)
	{
		//std::cout << level << '\n';
		std::vector<Node*> currentLevel;
		currentLevel.push_back(_root);

		for (int i = 0; i < level; i++)
		{
			std::vector<Node*> nextLevel;
			nextLevel.reserve(currentLevel.size() * 2);

			for (Node* Node : currentLevel)
			{
				if (Node)
				{
					nextLevel.push_back(Node->left);
					nextLevel.push_back(Node->right);
				}
				else
				{
					nextLevel.push_back(nullptr);
					nextLevel.push_back(nullptr);
				}
			}

			currentLevel.swap(nextLevel);
		}

		for (int i = 0, tabs = 6; i < currentLevel.size(); i++, tabs--)
		{
			if (currentLevel[i])
				std::cout << currentLevel[i]->key << "  ";
			else
				std::cout << -1 << ' ';
		}
		std::cout << '\n';
	}

}

BinaryTree::Node* BinaryTree::nlrSearch(const int k) const
{
	return nlrSearch(_root, k);
}

BinaryTree::Node* BinaryTree::nlrSearch(Node* nd, const int k) const
{
	if (nd)
	{
		if (nd->key == k)
			return nd;

		Node* leftChild = nlrSearch(nd->left, k);
		Node* rightChild = nlrSearch(nd->right, k);

		if (leftChild && leftChild->key == k)
			return leftChild;

		if (rightChild && rightChild->key == k)
			return rightChild;

		return nullptr;
	}

	return nullptr;
}

BinaryTree::Node* BinaryTree::findParent(Node* nd) const
{
	//std::cout << "child id: " << nd << '\n';
	if (nd == nullptr || _root == nd)
		return nullptr;

	std::vector<Node*> currLevel;
	currLevel.push_back(_root);

	while (currLevel.size())
	{

		std::vector<Node*> nextLevel;
		nextLevel.reserve(currLevel.size() * 2);

		for (Node* node : currLevel)
		{
			if (node->left)
			{
				//std::cout << "left: " << node->left->key << " id: " << node->left << " nd id: " << nd << '\n';
				if (node->left == nd)
				{
					//std::cout << "findParent: " << node << '\n';
					return node;
				}
				nextLevel.push_back(node->left);

			}

			if (node->right)
			{
				//std::cout << "rigth: " << node->right->key <<  " id: " << node->right << " nd id: " << nd <<  '\n';

				if (node->right == nd)
				{
					//std::cout << "findParent: " << node << '\n';
					return node;
				}

				nextLevel.push_back(node->right);

			}
		}
		currLevel.swap(nextLevel);
	}
	return nullptr;
}



