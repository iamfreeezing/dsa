#include <iostream>
using namespace std;

class Stack {
    public:
    int* arr;
    int top;
    int size;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if (++top <= size) {
            arr[top] = element;           
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if (top<0) {
            cout << "Stack underflow" << endl;
        }
        else {
            top--;
        }
    }

    void peek() {
        if (top<0) {
            cout << "Stack is empty" << endl;
        }
        else {
            cout << arr[top] << endl;
        }
    }

    bool isFull() {
        if (top+1==size) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (top<0) {
            return true;
        }
        return false;
    }   

};


int main() {

    Stack our(6);

    our.push(2);
    our.peek();


}