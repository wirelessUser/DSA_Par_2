#include <iostream>

using namespace std;



class Node{
	
	public:
	   int data;
       Node *next;
       
       Node(int _data){
       	this->data= _data;
       	next=NULL;
	   }
	
	
};



class LinkedList{
	
	Node *head;
	
	public:
	LinkedList(){
		head= NULL;
	}


	
	
	
//  Inserting the  the nodes ............................

	public:
		void Insert(int data ){
			
			Node* newNode= new Node(data);
			newNode->next=head;
		    head= newNode;
		}// Insert...
		
//  printing the nodes data............................
			void Print(){
			
			Node* temp = head;
			
			while(temp != NULL){
				cout<<temp->data<<endl;
			temp= temp->next;
			}
			
			
		}// Print...
		
};


int main() {
   

LinkedList   linkListObj;

linkListObj.Insert(1);
linkListObj.Insert(2);
linkListObj.Insert(3);
linkListObj.Insert(4);
linkListObj.Insert(5);

linkListObj.Print();
}


