#pragma once
class BinaryTree
{
public:
	struct Node;
	BinaryTree() = default;
	virtual ~BinaryTree();

	void clearTree();
	void clearTree(Node* subTreeRoot);

	bool isEmpty() const;

	Node* addNode(int k);
	Node* addNode(Node* nd, int k);

	int getHeight() const;
	int getHeight(Node* nd) const;

	void printTree();
	void printTree(Node* nd);

	Node* nlrSearch(const int k) const;
	Node* nlrSearch(Node* nd, const int k) const;

	Node* findParent(Node* nd) const;

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

