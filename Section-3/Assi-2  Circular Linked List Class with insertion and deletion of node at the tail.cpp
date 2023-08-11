#include <iostream>
using namespace std;

class Node
{
    public:
      int data;
      Node *next;
      
      Node(int _data){
      	data=_data;
      	next=NULL;
	  }
};

class CirularLinkedList
{
    Node *head;

  public: 
    CirularLinkedList()
    {
        head = NULL;
    }

    void Add(int _data)
    {
         Node *node = new Node(_data);
         
         
        Node* temp=head;
        
        if(head==NULL){
        	head=node;
        	node->next=node;
        	return;
		}
		
		while(temp->next!=head){
			temp=temp->next;
		}
		
		node->next=temp->next;
		temp->next=node;
		
    }

    void Print()	
    {
        Node *node = new Node();
        node = head;
        while(node->next != head)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << node->data <<endl;
    }

  void RemoveAtTail()
  {

        Node* curr=head;
    
        if(curr->next==head){
        	head=NULL;
        	delete curr;
        	return;
		}
            Node* prev=NULL;
        
        while(curr->next!=head){
        	prev=curr;
        	curr=curr->next;
		}
		
		prev->next=curr->next;
		delete curr;
  }
};

int main() 
{
    CirularLinkedList *cll = new CirularLinkedList();
    
    cll->Add(10);
    cll->Add(20);
    cll->Add(30);
    cll->Add(40);
    cll->Add(50);
  
    cll->Print();	

cout<<"after Removing at tail..."<<endl;
  cll->RemoveAtTail();
  cll->Print();			
}
