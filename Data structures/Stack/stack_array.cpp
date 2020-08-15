#include <iostream>
using namespace std;
class Stack
{
private:
    int stackSize;
    int top;
    int entry[];

public:
    Stack(int _stackSize)
    {
        stackSize = _stackSize;
        top = 0;
        for (int i = 0; i < stackSize; i++)
        {
            entry[i] = 0;
        }
    }

    bool IsFull()
    {
        return top == stackSize;
    }

    bool IsEmpty()
    {
        return top == 0;
    }

    void Push(int value)
    {
        if (IsFull())
            cout << "Stack overflow"
                 << "\n";
        else
        {
            // push process
            entry[top] = value;
            top++;
        }
    }

    int Pop()
    {
        if (IsEmpty())
        {
            return 0;
        }

        int popedItem = entry[top - 1];
        entry[top - 1] = 0;
        top--;

        return popedItem;
    }

    void Display()
    {
        for (int i = stackSize - 1; i >= 0; i--)
        {
            cout << entry[i] << "\n";
        }
    }
};