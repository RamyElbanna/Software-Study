#include <iostream>
using namespace std;

class LinkedList{
private:
    struct Node{
        int value;
        Node* next;
    };
    Node* head;
    int size;
public:
    LinkedList(){
        size = 0;
        head = nullptr;
    }

    bool IsEmpty(){
        return size == 0 && head == nullptr;
    }

    int Size(){
        return size;
    }

    void PushFront(int item){
        Node* temp = new Node();
        temp->value = item;
        temp->next = head;
        head = temp;
        size++;
    }

    int PopFront(){
        if(head == nullptr) return 0;
        Node* temp = head;
        int poppedValue = temp->value;
        head = head->next;
        delete(temp);
        size--;
        return poppedValue;
    }

    void Insert(int index, int item){
        if(index == 0){
            return PushFront(item);
        }

        if(index > size) throw("out of boundries");

        Node* current = head;
        for (int i = 0; i < index -1; i++)
        {
            current = current->next;
        }

        Node* newNode = new Node();
        newNode->value = item;
        newNode->next = current->next;
        current->next = newNode;
        size++;
        
    }

    int ValueAt(int index){
        if(size == 1) return head->value;
        Node* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->value;
    }

    void Display(){
        cout << "the size of likedlist = " << size << endl;
        Node* current = head;
        while(current != nullptr){
            cout << current->value << ",";
            current = current->next;
        }
    }

};