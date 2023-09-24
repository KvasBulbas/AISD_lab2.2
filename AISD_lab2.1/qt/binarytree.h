#ifndef BINARYTREE_H
#define BINARYTREE_H


#include <vector>
class BinaryTree
{
public:

    struct Node;
    BinaryTree() = default;
    BinaryTree(const BinaryTree& tree);
    virtual ~BinaryTree();
    Node* getRoot() const;

    void clearTree();

    void clearTree(Node* subTreeRoot);

    bool isEmpty() const;

    Node* addNode(int k);
    Node* addNode(Node* nd, int k);

    Node* nlrSearch(const int k) const;
    Node* nlrSearch(Node* nd, const int k) const;

    Node* nlrSearch(const int k, int & leftPos, int & rightPos) const;
    Node* nlrSearch(Node* nd, const int k, int & leftPos, int & rightPos) const;

    Node* findParent(Node* nd) const;


    bool deleteNodeByKey(const int k);
    bool deleteNodeByKey(Node* nd, const int k);

    bool deleteNode(Node* nd, Node* parent);
    bool deleteNode(Node * node);

    int getHeight() const;
    int getHeight(Node* nd) const;


    Node* getFreeNode() const;
    Node* getFreeNode(Node* nd) const;

    int getCountOfNode() const;
    int getCountOfNode(Node* nd) const;



    std::vector<int> getTreeAsVector() const;
    std::vector<int> getTreeAsVector(Node* subTreeRoot) const;

    void printTree();
    void printTree(Node* nd);

    BinaryTree& operator = (const BinaryTree & outTree);
    void copyTree(Node*& inTree, Node* outTree);

    std::vector<Node *> getNodes();
    std::vector<Node*> getNodes(Node* nd);



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

#endif // BINARYTREE_H
