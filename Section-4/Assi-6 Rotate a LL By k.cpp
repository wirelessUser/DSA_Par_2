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
  void Insert(int data) {

    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
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

  //................. Roatte nodes by k     ................

  Node *RotateByK(int k) {
    // finding lenght and take mod by lenght ..
    if (head == NULL && head->next == NULL && k == 0) {
      return head;
    }
   
   Node* temp= head;
   int len=1;
    while(temp->next!=NULL){
    	temp=temp->next;
    	len++;
	}
	cout<<"Lenght :"<<len<<endl;
   temp->next= head;
  
     k %=len;
    
    if(k==0){
    	return head;
	}
    Node* 	temp2=head;
	for (int i = 0; i <len - k-1 ; i++) {

      temp2 = temp2->next;
    }
   Node* newHead= temp2->next;
   temp2->next=NULL;
    return newHead;
     
 }
 
 
};

int main() {

  LinkedList linkListObj;

  linkListObj.Insert(1);
  linkListObj.Insert(2);
 // linkListObj.Insert(3);
 // linkListObj.Insert(4);
 // linkListObj.Insert(5);

  linkListObj.Print();

  cout << "---------------- Rotate  Nodes ------------------------";
  cout << endl;
  Node *newHead = linkListObj.RotateByK(1);
  linkListObj.Print(newHead);
}

