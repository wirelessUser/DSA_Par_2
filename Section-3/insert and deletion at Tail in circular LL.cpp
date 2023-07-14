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


void insertAtTail(Node*& _head, int data) {
    Node* newNode = new Node(data);

    if (_head == NULL) {
        _head = newNode;
        newNode->next = newNode;
        return;
    }

    Node* temp = _head;
    while (temp->next != _head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = _head;
}

void deleteAtTail(Node* _head){
	 Node* curr= _head;
	 Node* prev =NULL;
	 while( curr->next !=_head){
	 	
	 	prev=curr;
	 	curr= curr->next;	 	
	 }
	 
	 prev->next=_head;
	 delete curr;
	
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

    // Insert nodes at the tail
    myList.insertAtTail(head, 1);
    myList.insertAtTail(head, 2);
    myList.insertAtTail(head, 3);
    myList.insertAtTail(head, 4);
    myList.insertAtTail(head, 5);
    myList.insertAtTail(head, 6);
    myList.insertAtTail(head, 7);

    // Print the list
    cout << "Circular Linked List: ";
    myList.printList(head);

    //Delete nodes from the tail
   myList.deleteAtTail(head);

   // Print the updated list
    cout << " Deleted from tail Circular Linked List: ";
    myList.printList(head);

    return 0;
}

