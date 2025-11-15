#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* topNode;
    int length;

public:
    Stack() {
        topNode = nullptr;
        length = 0;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
        length++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        length--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    int size() {
        return length;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.peek() << endl;

    st.pop();
    cout << "Top after pop: " << st.peek() << endl;

    cout << "Current Size: " << st.size() << endl;

    return 0;
}
