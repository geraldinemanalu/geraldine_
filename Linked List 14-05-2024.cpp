#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }
void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteNode(int value) {
        if (head == NULL) {
            return;
        }

 if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = NULL;
        while (current != NULL && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current) {
            prev->next = current->next;
            delete current;
        }
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
 cout << endl;
    }
};

int main() {
    LinkedList linkedList;

    linkedList.insertAtEnd(10);
    linkedList.insertAtEnd(20);
    linkedList.insertAtBeginning(5);

    linkedList.display();  // Output: 5 10 20

    linkedList.deleteNode(10);

    linkedList.display();  // Output: 5 20

    return 0;
}

