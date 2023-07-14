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
    void insertAtHead(Node* _head ,int data) {
        Node* newNode = new Node(data);
        if(_head==NULL){
        
        	newNode->next=newNode;  
				_head=newNode;
				return;    	
		}
		Node* temp= _head;
			while(temp->next !=_head){
				
				temp= temp->next;
				
			}
			temp->next= newNode;
			newNode->next=_head;
			_head=newNode;
		
    }

    // Delete the node at the head of the circular linked list
    void deleteAtHead() {
       
    }

    // Print the entire circular linked list
    void printList(Node* _head) {
        if (_head == NULL) {
           cout << "List is empty." << std::endl;
            return;
        }

        Node* curr = _head;
        //cout<<"current:"<<current->data<<endl;
        do  {
            cout << curr->data << " ";
            //cout<<"current->next:"<<current->next->data<<endl;
            curr = curr->next;
            
        } while (curr != _head) ;

       cout << endl;
    }
};

int main() {
    CircularLinkedList myList;
Node* head=NULL;
    // Insert nodes at the head
    myList.insertAtHead(head,1);
    myList.insertAtHead(head,2);
 myList.insertAtHead(head,3); myList.insertAtHead(head,4); myList.insertAtHead(head,5); myList.insertAtHead(head,6);  myList.insertAtHead(head,7);
    // Print the list
    std::cout << "Circular Linked List: ";
    myList.printList(head);

    // Delete nodes from the head
    
}

