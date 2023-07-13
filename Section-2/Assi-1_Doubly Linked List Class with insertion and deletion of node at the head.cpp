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
		
				//... DeleteAtHead In the Double LL..........................
				
				void DeleteAtHead(Node*& _head){
			
		              if(_head==NULL){
		              	cout<<"Nothing to delete..."<<endl;
					  }else{
					  	
					  	Node* temp= _head;
					  	_head= _head->next;
					  	
					  	if(_head !=NULL){
					  		_head->prev= NULL;
					  		
						  }
						  
						  delete temp;
					  }
		}//DeleteAtHead.....


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
	cout<<"-------------------Inseting at head------------------------"<<endl;
	
	//objDLL.InsertAtHead(head,1);
//	objDLL.InsertAtHead(head,2);
	//objDLL.InsertAtHead(head,3);
	//objDLL.InsertAtHead(head,4);
	
	objDLL.Display(head);
		cout<<"-------------------Deleting at head------------------------"<<endl;
		objDLL.DeleteAtHead(head);
			objDLL.Display(head);
}











