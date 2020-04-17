#include <bits/stdc++.h>
class Node
{
public:
    int data;
    Node *next;
};

void PrintList(Node *head)
{
    if (head == nullptr)
    {
        std::cout << "List is Empty!\n";
        return;
    }
    while (head != nullptr)
    {
        std::cout << head->data << "  ";
        head = head->next;
    }
    std::cout << std::endl;
}

void InsertAtFront(Node *&head, int new_data)
{
    Node *new_node = new Node();

    new_node->data = new_data;
    new_node->next = head;
    head = new_node;

    return;
}

void InsertAfter(Node *prev_node, int new_data)
{
    if (prev_node == nullptr)
    {
        std::cout << "Previous Node Cannot be NULL!" << std::endl;
        return;
    }

    Node *new_node = new Node();

    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

    return;
}

void InsertAtEnd(Node *&head, int new_data)
{
    if (head == nullptr)
    {
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = nullptr;
        head = new_node;
    }
    Node *last = head;

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    while (last->next != nullptr)
        last = last->next;

    last->next = new_node;

    return;
}

void DeleteNode(Node *&head, int key)
{
    Node *temp = head, *prev;

    if (temp->next != nullptr && temp->data == key)
    {
        head = temp->next;
        delete temp;
        return;
    }
    while (temp->data != key && temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        std::cout << "No Element with given key in List\n";
        return;
    }

    prev->next = temp->next;

    delete temp;
    return;
}

// finding lenght using recursion
int length(Node *head)
{
    if (head == nullptr)
        return 0;
    return 1 + length(head->next);
}
// finding length using itreation
/*
int length(Node* head)
{
    int length = 0;
    Node* temp = head;
    if (temp == nullptr)
        return length;
    while(temp->next != nullptr)
    {
        ++length;
        temp = temp->next;
    }
    return ++length;
}*/

void DeleteNodeAtPosition(Node *&head, int position)
{
    if (position <= length(head))
    {
        Node *temp = head, *prev;

        if (position == 1)
        {
            head = temp->next;
            delete temp;
            return;
        }

        for (auto i = 0; temp->next != nullptr && i < position - 1; ++i)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;
        return;
    }
    else
    {
        std::cout << "Error : Out of Range!\n";
    }
}

int GetNthNodeElement(Node *head, int position)
{
    if (position <= length(head))
    {
        Node *current = head;
        for (int i = 0; current->next != nullptr; ++i)
        {
            if (i == position - 1)
            {
                return current->data;
            }
            current = current->next;
        }
    }
    else
    {
        std::cout << "Error : Out of Range!\n";
    }
}

void DeleteList(Node *&head)
{
    Node *current = head, *next;
    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

int main()
{
    Node *head = nullptr;
    /* Node* second = nullptr;
    Node* third = nullptr;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;*/

    PrintList(head);

    std::cout << "Adding 0 to Front of List \n";
    InsertAtFront(head, 0);
    PrintList(head);

    std::cout << "Adding 5 to Front of List \n";
    InsertAtFront(head, 5);
    PrintList(head);

    std::cout << "Adding 6 to Front of List \n";
    InsertAtFront(head, 6);
    PrintList(head);

    std::cout << "Adding 9 to Front of List \n";
    InsertAtFront(head, 9);
    PrintList(head);

    std::cout << "Adding 11 to Front of List \n";
    InsertAtFront(head, 11);
    PrintList(head);

    /* std::cout<<"Adding 8 after second Node \n";
    InsertAfter(second,8);
    PrintList(head);*/

    std::cout << "Adding 10 at the end of the list\n";
    InsertAtEnd(head, 10);
    PrintList(head);

    std::cout << "Adding 8 at the end of the list\n";
    InsertAtEnd(head, 8);
    PrintList(head);

    std::cout << "Adding 12 at the end of the list\n";
    InsertAtEnd(head, 12);
    PrintList(head);

    std::cout << "Adding 15 at the end of the list\n";
    InsertAtEnd(head, 15);
    PrintList(head);

    /*  std::cout<<"Deleting 0 form list\n";
    DeleteNode(head,0);
    PrintList(head);

    std::cout<<"Deleting 8 form list\n";
    DeleteNode(head,8);
    PrintList(head);

    std::cout<<"Deleting Element At position 2\n";
    DeleteNodeAtPosition(head,2);
    PrintList(head);

    std::cout<<"Deleting Element At position 1\n";
    DeleteNodeAtPosition(head,1);
    PrintList(head);

    std::cout<<"Deleting Element At position 2\n";
    DeleteNodeAtPosition(head,2);
    PrintList(head);

    std::cout<<"Deleting Element At position 2\n";
    DeleteNodeAtPosition(head,2);
    PrintList(head);

    std::cout<<"Deleting Element At position 12\n";
    DeleteNodeAtPosition(head,12);
    PrintList(head);

    std::cout<<"Deleting Element At position 2\n";
    DeleteNodeAtPosition(head,2);
    PrintList(head);

    std::cout<<"Deleting Element At position 2\n";
    DeleteNodeAtPosition(head,2);
    PrintList(head);*/

    std::cout << GetNthNodeElement(head, 3);
    std::cout << std::endl;

    std::cout << "Deleting the List\n";
    DeleteList(head);
    PrintList(head);

    return 0;
}
