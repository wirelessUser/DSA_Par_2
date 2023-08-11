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

  //  printing the nodes data............................

  //................. Swap  Nodes   ................
  void SwapNodes(int count) {

    // Swappin to nodes node1 aND node2...
  Node* node1= NULL;
  Node* node2=NULL;
  Node* temp= head;
  while(temp!=NULL){
  	
  	   	 if(node2!=NULL){
  		node2=node2->next;
	  }
  	count--;
  
  	 if(count==0){
  	 	node1=temp;
  	 	node2=head;
	   }
	   	 temp=temp->next;
	   	 
	
  }
  
  
  int tempor= node1->data;
  node1->data= node2->data;
   node2->data=tempor;
  
 }//SwapNodes.
};

int main() {

  LinkedList linkListObj;

  linkListObj.Insert(1);
  linkListObj.Insert(2);
  linkListObj.Insert(3);
  linkListObj.Insert(4);
  linkListObj.Insert(5);

  linkListObj.Print();

  cout << "---------------- Swap  Nodes ------------------------";
    cout << endl;
  linkListObj.SwapNodes(1);
linkListObj.Print();

}

