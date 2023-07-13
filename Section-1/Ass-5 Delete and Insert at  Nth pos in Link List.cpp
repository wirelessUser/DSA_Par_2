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
	public:
	Node *head;
	

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
		
		
		//  printing the nodes data............................


       void Remove(int _data){
	        Node* cur= head;
	        Node*prev= NULL;
	          while(cur->data!=_data && cur !=NULL){
	          	
	          	prev= cur;
	          	cur=cur->next;
	          	
	          	}//while...
	          	
	          	if(cur==NULL){
	          		cout<<"Not such value is found"<<endl;
				  }
				  
				  if(prev==NULL){
				  	
				  	//Head is beoing removed..
				  	head= cur->next;
				  	
				  }else{
				  	prev->next= cur->next;
				  }
	          	
	          delete cur;     
			  
     }// Remove...
	 
	//................. InsertAtHead  ................
	
	void InsertAtHead(int data){
		
		Node* newNode= new Node(data);
		
		     newNode->next= head->next;
			 head= newNode;
	}
	
	
	
		//................ InsertATail  .................
	void InsertATail( int data) {
  Node* newNode = new Node(data);
  if (head == NULL) {
    head = newNode;
    return;
  }

  Node* curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = newNode;
}

Node* ReverseAList(Node* head){
	
	 Node* prev = NULL;
        Node* curr = head;
        Node* temp = NULL;

        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
}


 
 //.....................insert a node at the Nth position from the beginning
 
 void InsertAtNthPos(int data , int pos){
 	
 	Node* newNode= new Node(data);
 	  	if(pos==1){
 		 newNode->next= head;
 		 head= newNode;
 		 return;
	 }
 	  Node* curr=head;
 	  Node* prev=NULL;
 	  int i=1;
 	while(i<pos && curr !=NULL){
 		prev=curr;
 		curr=curr->next;
 			
 		i++; 		
	 }
	 
	 if(i==pos){
	 	newNode->next=curr;
	 	prev->next=newNode;
	 }else{
	 	
	 	cout<<"Not a right Pos Input"<<endl;
	 }
 	
 }//InsertAtNthPos
 
  void DeleteAtNthPos( int pos){
 	  Node* curr =head;
	  Node* prev=NULL;
	  
 	if(head==NULL){
 		 cout<<"Empty list Nothing to delete"<<endl;
 		 return;
	 }
	 
	 if(pos==1){
	 	
	 	
	 	curr->next=head;
	 	return;
	 }
	  int i=1;
	  	
	  	while(i<pos && curr !=NULL){
	  		prev=curr;
	  		curr = curr->next;
	  		
	  		i++;
		  }
	  	if(i==pos && curr !=NULL){
	  		prev->next=curr->next;
	  		delete curr;
		  }else{
		  	
		  	cout<<"Invalid Inoput..."<<endl;
		  }
	  	
 	
 }//

};


int main() {
   

LinkedList   linkListObj;

linkListObj.Insert(1);
linkListObj.Insert(2);
linkListObj.Insert(3);
linkListObj.Insert(4);
linkListObj.Insert(5);

linkListObj.Print();

//linkListObj.Remove(3);

//cout<<"---------------- After Removal------------------------"<<endl;


//cout<<"---------------- Inset at Head------------------------"<<endl;

//linkListObj.InsertAtHead(20);
//linkListObj.Print();
//cout<<"---------------- Inset at Tail------------------------"<<endl;

//linkListObj.InsertATail(23);

//cout<<"---------------- Reverse a Link List -----------------------"<<endl;

 //linkListObj.head = linkListObj.ReverseList(linkListObj.head);

   // cout << "Reversed Linked List: ";
   // linkListObj.Print();

cout<<"---------------- Delete an Nth pos in List------------------------"<<endl;

linkListObj.DeleteAtNthPos(2);


linkListObj.Print();

cout<<"---------------- Insert an Nth pos in List------------------------"<<endl;

linkListObj.InsertAtNthPos(33,1);


linkListObj.Print();

}












