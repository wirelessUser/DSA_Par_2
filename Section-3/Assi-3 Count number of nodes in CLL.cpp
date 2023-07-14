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

int CountNodes(Node* _head){
	
	if (_head == NULL) {
            return 0;
        }

	 int count=1;
	 Node* temp =_head;
	 while( temp->next !=_head){
	 	
	 	 	count++;
	 	 	temp= temp->next;
	 }
	 
	return count;
	
}

int checkIfCLL(Node*& _head){
	if (_head == NULL) {
        return 0; // Not a CLL, as head is null
    }
	Node* temp= _head;
	
	while(temp->next== NULL ||temp->next==_head){
		
	    temp= temp->next;
		
	}
	
	if(temp==NULL){
		return 0;
	}else if(temp==_head){
		
		return 1;
	}
}//checkIfCLL


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
   // myList.insertAtTail(head, 2);
   // myList.insertAtTail(head, 3);
    myList.insertAtTail(head, 4);
   // myList.insertAtTail(head, 5);
   // myList.insertAtTail(head, 6);
   // myList.insertAtTail(head, 7);

    // Print the list
    cout << "Circular Linked List: ";
    myList.printList(head);

    //Delete nodes from the tail
    int count= myList.CountNodes(head);

   // Print the updated list
    cout << " The Count is : ";
 
 cout<<count<<endl;
 
    cout << "Circular Linked OR NOT : ";
  int isCLL= myList.checkIfCLL(head);
  cout<<isCLL<<endl;
    return 0;
}





