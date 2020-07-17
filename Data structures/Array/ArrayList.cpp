#include<iostream>
using namespace std;

class ArrayList{
private:
    int capacity;
    int size;
    int* myArray;

public:

    ArrayList(){
        capacity = 16;
        size = 0;
        myArray = new int[capacity];
    }

    void Push(int item){
        if(size == capacity){
            resize();
        }
        myArray[size] = item;
        size++;
    }

    int Pop(){
        if(size == 0) return 0;
        int poppedvalue = myArray[size-1];
        size--;
        return poppedvalue;
    }

    void Delete(int index){
        // [1,2,3,4]
        if( index < 0 || index >= size) throw("Index out of bounds");
        for (int i = index ; i <= myArray[size-1]; i++)
        {
            myArray[i] = myArray[i+1];
        }
        size--;
    }

    int Size(){
        return size;
    }

    bool IsEmpty(){
        return size == 0;
    }

    int At(int index){
        if( index < 0 || index >= size) throw("Index out of bounds");
        return myArray[index];
    }

    void Insert(int index, int item){
        if( index < 0 || index >= size) throw("Index out of bounds");
        for (int i = myArray[size-1]; i >= index; i--)
        {
            myArray[i+1] = myArray[i];
        }
        myArray[index] = item;
        size++;
    }

    void resize(){
        capacity *= 2;
        int* newArray = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = myArray[i];
        }
        delete[] myArray;
        myArray = newArray;
    }

    void display(){
        cout << "My Arraylist size is: " << size << endl;
        cout << "arrayList:" << "[";
        for (int i = 0; i < size; i++)
        {
            cout <<  myArray[i] << ",";
        }
        cout << "]" << endl;
    }

};

int main(){
    ArrayList arrayList;
    arrayList.Push(7);
    arrayList.Push(8);
    arrayList.Insert(1,9);
    arrayList.Pop();
    arrayList.Delete(1);
    arrayList.display();
    return 0;
}