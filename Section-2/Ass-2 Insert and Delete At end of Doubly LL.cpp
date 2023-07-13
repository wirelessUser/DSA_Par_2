#include <iostream>
using namespace std;
class Node {
	
	public:
	int data ;
	Node* prev=NULL;
	Node* next=NULL;
	
	
	
	Node(int _data){
		
		data=_data;
		prev=NULL;
		next=NULL;
			
	}
};



class DoublyLL{
	
	Node* head;
	
	public:
		DoublyLL(){
			head=NULL;
		}
		
		
			//... InsertAtHead In the Double LL..........................
		void InsertAtHead(Node*& _head,int data){
			
			Node* newNode= new Node(data);
			
			//... if node is null..
			
			if( _head==NULL){
				_head= newNode;
			}
			else{
				 
				 newNode->next= _head;
				 _head->prev=newNode;
				 _head= newNode;
			}
		}//InsertAtHead
		
		
		//... InsertAtEndIn the Double LL..........................
		void InsertAtTail(Node*& _head,int data){
			 
			 Node* newNode= new  Node(data);
			 
			 Node* temp=_head;
			
			 while(temp->next !=NULL){
			 	
			 	temp=temp->next;
			 }
			 
			 if(temp->next==NULL){
			 	
			 	newNode->prev= temp;
			 	temp->next= newNode;
			 	
			 }
		
		}//InsertAtTail
		
				//... DeleteAtEnd In the Double LL..........................
				
				void DeleteAtTail(Node*& _head){
			
		             Node* curr= _head;
		             Node* prev=NULL;
		             while(curr->next !=NULL){
		             	prev=curr;
		             	curr=curr->next;
		             	
					 }
					 
					prev->next=NULL;
					delete curr;
		}//DeleteAtTail.....


        void Display(Node* node){
	            
	            while(node!=NULL){
	            	
	            	cout<<"Node:"<<node->data<<endl;
	            	node= node->next;
				}
	
        }//Display/......
};

int main() {
	
	Node* head=NULL;
	DoublyLL objDLL;
	objDLL.InsertAtHead(head,1);
	objDLL.InsertAtHead(head,2);
	objDLL.InsertAtHead(head,3);
	objDLL.InsertAtHead(head,4);
	cout<<"-------------------Inseting at Tail------------------------"<<endl;
	
objDLL.InsertAtTail(head,20);

	objDLL.Display(head);
		cout<<"-------------------Deleting at Tail------------------------"<<endl;
	objDLL.DeleteAtTail(head);
			objDLL.Display(head);
}











