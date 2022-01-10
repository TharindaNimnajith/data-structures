#include <iostream>

class Node
{
public:
    int data;

    Node *next;

    Node(int value);

    Node getNext();

    ~Node();
};

Node::Node(int value)
{
    data = value;
    next = nullptr;
}

Node::~Node()
{
}

class LinkedList
{
private:
    Node *head;

    int size = 1;

public:
    LinkedList(int value);

    int getSize();

    void add(int value);

    void deleteByIndex(int index);

    void addByIndex(int index, int value);

    void showList();

    ~LinkedList();
};

LinkedList::LinkedList(int value)
{
    head = new Node(value);
}

void LinkedList::add(int value)
{
    size++;
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::deleteByIndex(int index)
{
    int tempIndex = 0;
    Node *temp = head;
    Node *previous;

    for (int i = 0; i < size; i++)
    {
        if (index == 0)
        {
            head = temp->next;
            size--;
            delete temp;
            break;
        }
        else if (tempIndex == index)
        {
            previous->next = temp->next;
            size--;
            delete temp;
            break;
        }
        previous = temp;
        temp = temp->next;
        tempIndex++;
    }
}

void LinkedList::addByIndex(int index, int value)
{
    int tempIndex = 0;
    Node *temp = head;
    Node *previous;

    for (int i = 0; i < size; i++)
    {
        if (index == 0)
        {
            add(value);
            break;
        }
        else if (tempIndex == index)
        {
            Node *rest = temp;
            temp = new Node(value);
            temp->next = rest;
            previous->next = temp;
            size++;
            break;
        }
        previous = temp;
        temp = temp->next;
        tempIndex++;
    }
}

int LinkedList::getSize()
{
    return size;
}

void LinkedList::showList()
{
    Node *temp;
    temp = head;
    for (int i = 0; i < size; i++)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
    std::cout << std::endl;
}

LinkedList::~LinkedList()
{
}

int main()
{
    LinkedList linkedList(2);
    linkedList.add(3);
    linkedList.add(4);
    linkedList.add(50);
    linkedList.add(520);
    linkedList.showList();

    linkedList.addByIndex(2, 456);
    linkedList.showList();

    linkedList.deleteByIndex(2);
    linkedList.showList();

    std::cout << linkedList.getSize() << std::endl;

    return 0;
}
