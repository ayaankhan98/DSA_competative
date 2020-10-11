/**
 *
 * Linked List Implementation.
 */

#include <iostream>

using std::cout;

template <typename T>
class node {
  public:
    T val;
    node* nxt;
    node() {}
    virtual ~node(){
      delete nxt;
    }
};

/**
 * wrapper class around node
 */
template <typename T>
class linkedList {
  private:
    node<T>* _start;
  public:
    linkedList(): _start(nullptr) {}
    virtual ~linkedList() {
      delete _start;
    }
    void _insert(T, T);
    void _delete(T);
    void _display();
    bool _isEmpty();
    int _search(T);
    int _length();
};

template <typename T>
void linkedList<T>::_insert(T k, T x) {
  node<T>* new_node = new node<T>;
  new_node->val = x;
  new_node->nxt = nullptr;
  if (_start == nullptr) {
    _start = new_node;
    return;
  }
  node<T>* current = _start;
  while(current != nullptr) {
    if (current->val == k) {
      new_node->nxt = current->nxt;
      current->nxt = new_node;
      return;
    }
    if (current->nxt == nullptr) {
      current->nxt = new_node;
      return;
    }
    current = current->nxt;
  }
}

template <typename T>
void linkedList<T>::_delete(T k) {
  node<T>* current = _start;
  if (k == 1) {
    _start = current->nxt;
    return;
  }
  node<T>* _prev = nullptr;
  int pos = 1;
  while(current != nullptr) {
    if (pos == k) {
      _prev->nxt = current->nxt;
      return;
    }
    _prev = current;
    current = current->nxt;
    pos++;
  }
}

template <typename T>
void linkedList<T>::_display() {
  node<T>* current = _start;
  while(current != nullptr) {
    cout << current->val << " ";
    current = current->nxt;
  }
  cout << "\n";
}

template <typename T>
int linkedList<T>::_search(T x) {
  int pos = 1;
  node<T>* current = _start;
  while(current != nullptr) {
    if (current->val == x) {
      return pos;
    }
    current = current->nxt;
    pos++;
  }
  return 0;
}

template <typename T>
bool linkedList<T>::_isEmpty() {
  return _start == nullptr ? true : false;
}

template <typename T>
int linkedList<T>::_length() {
  int len = 0;
  node<T>* current = _start;
  while(current != nullptr) {
    current = current->nxt;
    len++;
  }
  return len;
}

int main() {
  /// declaring a linked list of type int
  linkedList<int> l;
  cout << "Creating a Empty linked list\n";
  /// testing _isEmpty() function

  cout << "Checking if the list is empty or not : ";
  cout << (l._isEmpty() ? "Empty" : "Not Empty") << "\n";
  /// inserting elements

  cout << "Inserting 2...\n";
  l._insert(1, 2);
  l._display();

  cout << "Inserting 3 after 2...\n";
  l._insert(2, 3);
  l._display();

  cout << "Inserting 4 after 3...\n";
  l._insert(3, 4);
  l._display();

  cout << "Inserting 5 after 4...\n";
  l._insert(4, 5);
  l._display();

  cout << "Inserting 10 after 2...\n";
  l._insert(2, 10);

  /// testing display function
  cout << "Final List : ";
  l._display();

  /// testing length function
  cout << "Length is : " << l._length() << "\n";

  /// testing search function.
  cout << "Searching 5...\n";
  cout << "5 Found at : " << l._search(5) << "\n";
  cout << "Searching 2...\n";
  cout << "2 Found at : " << l._search(2) << "\n";

  cout << "Checking if the list is empty or not : ";
  cout << (l._isEmpty() ? "Empty" : "Not Empty") << "\n";

  cout << "Deleting element at position 2...\n";
  l._delete(2);
  cout << "Final List : ";
  l._display();

  return 0;
}
