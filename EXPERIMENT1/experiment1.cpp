#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> list;   
    int capacity;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        list.reserve(size);
    }

    // Check if stack is empty
    bool isEmpty() const {
        return list.empty();
    }

    // Check if stack is full
    bool isFull() const {
        return (int)list.size() == capacity;
    }

    // Push element
    void push(T item) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << item << endl;
            return;
        }
        list.push_back(item);
        cout << item << " pushed into stack." << endl;
    }

    // Pop element
    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return T(); 
        }
        T topElement = list.back();
        list.pop_back();
        return topElement;
    }

    // Peek top element
    T peek() const {
        if (isEmpty()) {
            cout << "Stack is empty! No top element." << endl;
            return T(); 
        }
        return list.back();
    }

    // Display stack elements
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (auto &item : list) {
            cout << item << " ";
        }
        cout << endl;
    }
};

// Demo
int main() {
    Stack<int> intStack(5);

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    intStack.display();
    cout << "Top element: " << intStack.peek() << endl;

    intStack.pop();
    intStack.display();

    cout << "Is Empty? " << (intStack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is Full? " << (intStack.isFull() ? "Yes" : "No") << endl;

    return 0;
}
