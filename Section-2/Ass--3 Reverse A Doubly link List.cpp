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
	void Reverse(Node*& _head) {
   
     Node* curr=_head;
    while (curr != NULL) {
        
       Node* temp= curr->prev;
        curr->prev= curr->next;
        curr->next= temp;
        
        _head=curr;
        curr= curr->prev;
    }

   
}
		
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
		cout<<"------------------- Double LL------------------------"<<endl;

		objDLL.Display(head);
	cout<<"-------------------Reverse a Double LL------------------------"<<endl;
	
objDLL.Reverse(head);

	objDLL.Display(head);

}











