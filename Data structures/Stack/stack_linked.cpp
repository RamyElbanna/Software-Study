#include <iostream>
using namespace std;
class Stack
{
private:
    struct Node
    {
        int value;
        Node *next;
    };

    // pointer to the stack
    Node *top = nullptr;

public:
    void Push(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        if (IsEmpty())
            newNode->next = nullptr;
        else
            newNode->next = top;

        top = newNode;
    }

    int Pop()
    {
        int poppedValue = top->value;
        Node *temp = top;
        top = top->next;
        delete (temp);
        return poppedValue;
    }

    bool IsEmpty()
    {
        return top == nullptr;
    }

    int TopValue()
    {
        return top->value;
    }
};

int main()
{
    Stack s;
    s.Push(5);
    s.Push(7);
    s.Push(8);
    s.Push(9);

    while (!s.IsEmpty())
    {
        cout << s.Pop();
    }

    return 0;
}