#include <iostream>

class Node
{
public:
    Node *right;

    Node *left;

    int data;

    Node(int value);

    ~Node();
};

Node::Node(int value)
{
    data = value;
    right = nullptr;
    left = nullptr;
}

Node::~Node()
{
}

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree(int value);

    void add(int value);

    void show();

    ~BinaryTree();
};

BinaryTree::BinaryTree(int value)
{
    root = new Node(value);
}

void BinaryTree::add(int value)
{
    Node *newNode = new Node(value);
    Node *tempNode = root;
    Node *tempPreviousNode = root;
    while (tempNode != nullptr)
    {
        if (value > tempNode->data)
        {
            tempNode = tempNode->left;
            if (tempNode == nullptr)
            {
                tempPreviousNode->left = newNode;
            }
        }
        else
        {
            tempNode = tempNode->right;
            if (tempNode == nullptr)
            {
                tempPreviousNode->right = newNode;
            }
        }
        tempPreviousNode = tempNode;
    }
    tempNode = nullptr;
    tempPreviousNode = nullptr;
    delete tempNode;
    delete tempPreviousNode;
}

void BinaryTree::show()
{
    Node *tempNode = root;
    while (tempNode != nullptr)
    {
        std::cout << tempNode->data << std::endl;
        tempNode = tempNode->right;
    }
    tempNode = root->left;
    while (tempNode != nullptr)
    {
        std::cout << tempNode->data << std::endl;
        tempNode = tempNode->left;
    }
    delete tempNode;
    tempNode = nullptr;
}

BinaryTree::~BinaryTree()
{
}

int main()
{
    BinaryTree binaryTree(4);
    binaryTree.add(3);
    binaryTree.add(5);
    binaryTree.add(2);
    binaryTree.add(10);
    binaryTree.show();
    return 0;
}
