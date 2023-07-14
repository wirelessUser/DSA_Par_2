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

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Insert a node at the head of the circular linked list
    void insertAtHead(Node*& _head, int data) {
        Node* newNode = new Node(data);
        if (_head == NULL) {
            newNode->next = newNode;
            _head = newNode;
            return;
        }
        Node* temp = _head;
        while (temp->next != _head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = _head;
        _head = newNode;
    }

    // Delete the node at the head of the circular linked list
    void deleteAtHead(Node*& _head) {
        if (_head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = _head;
        Node* tail = _head;
        while (tail->next != _head) {
            tail = tail->next;
        }

        if (_head == _head->next) {
            _head = NULL;
        } else {
            _head = _head->next;
            tail->next = _head;
        }
        delete temp;
    }

    // Print the entire circular linked list
    void printList(Node* _head) {
        if (_head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* curr = _head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != _head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList myList;
    Node* head = NULL;

    // Insert nodes at the head
    myList.insertAtHead(head, 1);
    myList.insertAtHead(head, 2);
    myList.insertAtHead(head, 3);
    myList.insertAtHead(head, 4);
    myList.insertAtHead(head, 5);
    myList.insertAtHead(head, 6);
    myList.insertAtHead(head, 7);

    // Print the list
    cout << "Circular Linked List: ";
    myList.printList(head);

    // Delete nodes from the head
    myList.deleteAtHead(head);

    // Print the updated list
    cout << "Updated Circular Linked List: ";
    myList.printList(head);

    return 0;
}

