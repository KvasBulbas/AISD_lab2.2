#pragma once
class BinaryTree
{
public:
	struct Node;
	BinaryTree() = default;
	virtual ~BinaryTree();


protected:
	Node* _root = nullptr;
};


struct BinaryTree::Node
{
	int key = 0;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(int k = 0, Node* l = nullptr, Node* r = nullptr)
	{
		key = k;
		left = l;
		right = r;
	}

	~Node() {};
};

