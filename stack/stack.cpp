/************************************************************
 * STACK is a liner data structure, it works on the principle of Last In First Out (LIFO) or equivalently we can say First In Last Out (FILO)
 * 
 * Operation on stack
 *          1 - Push ->  Adds an item at the top of the stack and if the stack is full prompts Stack Overflow
 *          2 - Pop -> Removes an item from the top of the stack and prompts stack underflow if stack is empty
 *          3 - Peek -> returns the element which is at the top of stack
 *          4 - isEmpty -> checks if stack is empty or not
 * 
 * Stack can be implemented using Arrays or Linked List
 * 
 * 
 * ********************************************************/

#include <iostream>

const int MAX = 1000;


class Stack
{
    private:
        int top;
        int arr[MAX];
    public:
        Stack(): top(0) {};
        bool push(int n);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push(int n)
{
    if(top > (MAX - 1))
    {
        std::cout<<"Stack Overflow!\n";
        return false;
    }
    else
    {
        arr[++top] = n;
        std::cout<<n<<" pushed into stack\n";
        return true;
    }
    
}

int Stack::pop()
{
    if(top < 0)
    {
        std::cout<<"Stack Underflow!\n";
        return 0;
    }
    else
    {
        int x = arr[top--];
        return x;
    }
}

int Stack::peek()
{
    if (isEmpty())
    {
        std::cout<<"Stack Empty\n";
        return 0;
    }
    return arr[top];
}

bool Stack::isEmpty()
{
    return (top < 0);
}

// Testing
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    std::cout<<s.pop()<<" Popped from stack\n";
    std::cout<<s.peek()<<" At top\n";
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    std::cout<<s.peek()<<" At top\n";
    return 0;
}