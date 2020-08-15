#include <iostream>

using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
    public:
        int* myQueue;
        // constructor
        Queue(int _size){
            size = _size;
            front = rear = -1;
            myQueue = new int[size];
            for (int i = 0; i < size; i++)
            {
                myQueue[i] = 0;
            }    
        }

        // methods
        bool IsFull(){
            return rear == (size-1);
        }

        bool IsEmpty(){
            return (front == -1 && rear == -1);
        }

        void Enqueue(int value){
            if(IsFull()) throw ("Queue is full");
            if(IsEmpty()){
                front = rear = 0;
                myQueue[0] = value;
                return;
            }
            rear++;
            myQueue[rear] = value;
        }

        int Dequeue(){
            if(IsEmpty()) throw("Queue is empty");
            int dequeuedValue = myQueue[front];
            myQueue[front] = 0;
            if(front == rear) front = rear = -1;
            else front++;
            
            return dequeuedValue;
        }

};