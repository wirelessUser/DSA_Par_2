#include <iostream>

using namespace std;

class Node {

public:
  int data;
  Node *next;

  Node(int _data) {
    this->data = _data;
    next = NULL;
  }
};

class LinkedList {
public:
  Node *head;

  LinkedList() { head = NULL; }

  //  Inserting the  the nodes ............................

public:
  // void Insert(int data) {

  // Node *newNode = new Node(data);
  // newNode->next = head;
  //  head = newNode;
  // } // Insert...

  Node *Insert(int data) {

    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
  } // Insert...

  //  printing the nodes data............................
  void Print() {

    Node *temp = head;

    while (temp != NULL) {
      cout << temp->data << endl;
      temp = temp->next;
    }

  } // Print...
  void Print(Node *&_head) {

    Node *temp = _head;

    while (temp != NULL) {
      cout << temp->data << endl;
      temp = temp->next;
    }

  } // Print...

  //  printing the nodes data............................

  //................. Print where cycle starts    ................

  Node *CycleStarts(Node *&_head) {
    Node* slow= _head;
    Node* fast= _head;
    while(fast->next->next!=NULL&& fast->next!=NULL ){
    	
    	slow=slow->next;
    	fast=fast->next->next;
    	
    	if(fast==slow){
    		break;
		}
	}
	  Node* temp =_head;
	 while(fast!=temp){
	 	temp=temp->next;
	 	fast=fast->next;
	 }
	 
	 return temp;
  } // CycleStarts
  

};

int main() {

  LinkedList linkListObj;

  Node *head1 = linkListObj.Insert(1);
  Node *head2 = linkListObj.Insert(2);
  Node *head3 = linkListObj.Insert(3);
  Node *head4 = linkListObj.Insert(4);
  Node *head5 = linkListObj.Insert(5);

  //  create a loop ...
  head1->next = head2;
  head2->next = head3;
  head3->next = head4;
  head4->next = head5;

  head5->next = head3;

  // linkListObj.Print();

  cout << "---------------- Where cycle starts   ------------------------";

  Node *foundedCycle = linkListObj.CycleStarts(head1);

  cout << "Cyelc node is" << foundedCycle->data << endl;
}

