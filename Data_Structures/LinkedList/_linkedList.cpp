#include <iostream>

using namespace std;

template <class T>
class node {
  public:
    T value;
    node<T> *next;
};

template <class T>
class linkedList {
  private:
    node<T> *start;
    node<T> *end;
  public:
    linkedList(): start(nullptr), end(nullptr) {}
    void pushFront(T);
    void pushBack(T);
    void popFront();
    void popBack();
    void showList();
};

template <class T>
void linkedList<T>::pushFront(T val) {
  // none of the node is present in the list at this time
  if (start == nullptr && end == nullptr) {
    node<T> * newNode = new node<T>;
    newNode->value = val;
    newNode->next = nullptr;
    start = newNode;
    end = newNode; 
  } else {
    node<T> *newNode = new node<T>;
    newNode->value = val;
    newNode->next = start;
    start = newNode;
  }
}

template <class T>
void linkedList<T>::pushBack(T val) {
  
  // none of the node is present in the list at this time
  if (start == nullptr && end == nullptr) {
    node<T> * newNode = new node<T>;
    newNode->value = val;
    newNode->next = nullptr;
    start = newNode;
    end = newNode; 
  } else {
    // if linked list already have some node and the user wants
    // to add new node at the back or at the end of the list then
    node<T> *newNode = new node<T>;
    newNode->value = val;
    newNode->next = nullptr;
    end->next = newNode;
    end = newNode;
  }
}

template <class T>
void linkedList<T>::showList() {
  // cout<<start->value<<" "<<start->next->value;
  // cout<<endl<<end->value;
  node<T> *current = start; 
  while(true) {
    if (current == end)
      break;
    cout<<current->value<<" ";
    current = current->next;
  }
  cout<<endl;
}

template <class T>
void linkedList<T>::popBack() {
  // TODO
}

template <class T>
void linkedList<T>::popFront() {
  // TODO
}

int main() {
  linkedList<int> ll;
  ll.pushBack(12);
  ll.pushBack(23);
  ll.pushBack(1);
  ll.pushBack(2);
  ll.pushBack(4);
  ll.pushFront(100);
  ll.pushFront(200);
  ll.showList();
  return 0;
}

