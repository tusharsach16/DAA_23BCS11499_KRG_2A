#include <iostream>
using namespace std;

// Doubly LL
class DoublyNode {
public:
    int data;
    DoublyNode *prev, *next;
    DoublyNode(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DoublyNode *head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Insert at beginning
    void insertAtBeginning(int data) {
        DoublyNode *newNode = new DoublyNode(data);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int data) {
        DoublyNode *newNode = new DoublyNode(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        DoublyNode *temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete at beginning
    void deleteAtBeginning() {
        if (head == nullptr) return;
        DoublyNode *temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        delete temp;
    }

    // Delete at end
    void deleteAtEnd() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        DoublyNode *temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }

    // Display DLL
    void display() {
        DoublyNode *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

//Circular LL
class CircularNode {
public:
    int data;
    CircularNode *next;
    CircularNode(int data) : data(data), next(nullptr) {}
};

class CircularLinkedList {
private:
    CircularNode *head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Insert at beginning
    void insertAtBeginning(int data) {
        CircularNode *newNode = new CircularNode(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            CircularNode *temp = head;
            while (temp->next != head) temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    // Insert at end
    void insertAtEnd(int data) {
        CircularNode *newNode = new CircularNode(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            CircularNode *temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Delete at beginning
    void deleteAtBeginning() {
        if (head == nullptr) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        CircularNode *temp = head;
        while (temp->next != head) temp = temp->next;
        CircularNode *delNode = head;
        head = head->next;
        temp->next = head;
        delete delNode;
    }

    // Delete at end
    void deleteAtEnd() {
        if (head == nullptr) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        CircularNode *temp = head;
        CircularNode *prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }

    // Display CLL
    void display() {
        if (head == nullptr) return;
        CircularNode *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};


int main() {
    cout << "Doubly Linked List:" << endl;
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.display();
    dll.deleteAtBeginning();
    dll.display();
    dll.deleteAtEnd();
    dll.display();

    cout << "\nCircular Linked List:" << endl;
    CircularLinkedList cll;
    cll.insertAtBeginning(10);
    cll.insertAtEnd(20);
    cll.insertAtBeginning(5);
    cll.display();
    cll.deleteAtBeginning();
    cll.display();
    cll.deleteAtEnd();
    cll.display();

    return 0;
}
