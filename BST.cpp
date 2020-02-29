#include <iostream>
#include <queue>

using namespace std;

class Node
{
    private:
        int data;
        Node* left;
        Node* right;
    public:
        void insert(Node*& , int);
        int getMin(Node*);
        int getMax(Node*);
        void display(Node*);
        int getHeight(Node*);
        void preOrder(Node*);
        void inOrder(Node*);
        void postOrder(Node*);
        Node* deleteNode(Node*&, int);
};


void Node::insert(Node* &root, int data)
{
    if (root == nullptr)
    {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->left = nullptr;
        new_node->right = nullptr;
        root = new_node;
    }
    else if (data <= root->data)
    {
        if (root->left == nullptr)
        {
            Node* new_node = new Node;
            new_node->data = data;
            new_node->left = nullptr;
            new_node->right = nullptr;
            root->left = new_node;
        }
        else
        {
            insert(root->left,data);
        }
        
    }
    else
    {
        if (root->right == nullptr)
        {
            Node* new_node = new Node;
            new_node->data = data;
            new_node->left = nullptr;
            new_node->right = nullptr;
            root->right = new_node;
        }
        else
        {
            insert(root->right,data);
        }
        
    }
}

int Node::getMin(Node* root)
{
    if(root == nullptr)
    {
        cout<<"Error : *root poiting to NULL"<<endl;
        return -1;
    }
    else if (root->left == nullptr)
        return root->data;
    return getMin(root->left);
}

int Node::getMax(Node* root)
{
    if (root == nullptr)
    {
        cout<<"Error : *root pointing to NULL"<<endl;
        return -1;
    }
    else if(root->right == nullptr)
        return root->data;
    return getMax(root->right);
}

void Node::display(Node* root)
{
    queue<Node*> q;
    while(root != nullptr)
    {
        cout<<root->data<<"  ";
        if (root->left != nullptr)
            q.push(root->left);
        if (root->right != nullptr)
            q.push(root->right);
        root = q.front();
        q.pop();
    }   
}

int Node::getHeight(Node* root)
{
    if (root == nullptr)
        return -1;
    return max(getHeight(root->left),getHeight(root->right)) + 1;
}

void Node::preOrder(Node* root)
{
    if (root == nullptr)
        return;
    cout<<root->data<<"  ";
    preOrder(root->left);
    preOrder(root->right);
}

void Node::inOrder(Node* root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout<<root->data<<"  ";
    inOrder(root->right);
}

void Node::postOrder(Node* root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"  ";
}

Node* Node::deleteNode(Node* &root, int data)
{
    if (root == nullptr)
        return root;
    else if(data < root->data)
        root->left = deleteNode(root->left, data);
    else if(data > root->data)
        root->right = deleteNode(root->right,data);
    else if(data == root->data)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if(root->left == nullptr)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            int minValue = getMin(root->right);
            root->data = minValue;
            root->right = deleteNode(root->right,minValue);
        }
    }
    return root;
}

int main()
{
    Node BST;
    Node* root = nullptr;
    BST.getMin(root);
    BST.insert(root,12);    
    BST.insert(root,5);
    BST.insert(root,15);
    BST.insert(root,3);
    BST.insert(root,7);
    BST.insert(root,13);
    BST.insert(root,17);
    BST.insert(root,1);
    BST.insert(root,9);
    cout<<BST.getMin(root)<<endl;
    cout<<BST.getMax(root)<<endl;
    cout<<"PreOrder : ";
    BST.preOrder(root);
    cout<<endl;
    cout<<"InOrder : ";
    BST.inOrder(root);
    cout<<endl;
    cout<<"PostOrder : ";
    BST.postOrder(root);
    cout<<endl;
    cout<<BST.getHeight(root);
    cout<<endl;
    BST.preOrder(root);
    cout<<endl;
    BST.deleteNode(root,15);
    BST.preOrder(root);
    cout<<endl;
    return 0;
}