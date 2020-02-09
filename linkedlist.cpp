#include <bits/stdc++.h>

class Node {
    public:
        int data;
        Node* next;        
};


void PrintList(Node* head)
{
    while(head != nullptr)
    {
        std::cout<<head->data<<"  ";
        head = head->next;
    }
    std::cout<<std::endl;
}

void InsertAtFront(Node* &head, int new_data)
{
    Node* new_node = new Node();

    new_node->data = new_data;
    new_node->next = head;
    head = new_node;

    return;
}


void InsertAfter(Node* prev_node, int new_data)
{
    if (prev_node == nullptr)
    {
        std::cout<<"Previous Node Cannot be NULL!"<<std::endl;
        return;
    }

    Node* new_node = new Node();
    
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

    return;
}

void InsertAtEnd(Node* &head, int new_data)
{
    Node* last = head;

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    while(last->next != nullptr)
        last = last->next;

    last->next = new_node;

    return;
}

int main()
{
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;


    PrintList(head);

    std::cout<<"Adding 0 to Front of List \n";
    InsertAtFront(head, 0);
    PrintList(head);

    std::cout<<"Adding 8 after second Node \n";
    InsertAfter(second,8);
    PrintList(head);

    std::cout<<"Adding 10 at the end of the list\n";
    InsertAtEnd(head,10);
    PrintList(head);

    return 0;
}