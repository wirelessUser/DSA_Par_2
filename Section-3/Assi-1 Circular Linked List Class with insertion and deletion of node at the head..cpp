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
       
      
       if(head==NULL){
       	head=node;
       	node->next=node;
       	return;
	   }
	   Node* temp= head;
	   while(temp->next!=head){
	   	temp=temp->next;
	   }
	 //  cout<<temp->data<<"temp->data"<<temp->next->data<<"temp->next->data"<<endl;
	   node->next=head;
	   temp->next=node;
	   head=node;
	 //  cout<<temp->next->data<<"temp->next->data"<<endl;
	   
    }//Add Node..

  void Print() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* node = head;
    do {
        cout << node->data << " ";
        node = node->next;
    } while (node != head);

    cout << endl;
}


  void RemoveAtHead()
  {
   Node* temp= head;
   if(temp->next==head){
  // 	delete temp;
   	head=NULL;
   	delete temp;
   	 cout<<"Now list is empty.."<<endl;
   	 return;
   }
   while(temp->next!=head){
   	temp=temp->next;
   }    
   
   
   temp->next = head->next;
   head=head->next;
  
  }//RemoveAtHead.
};

int main() 
{
    CirularLinkedList *cll = new CirularLinkedList();
    
    cll->Add(10);

  
    cll->Print();	
cout<<"After removal---1"<<endl;
  cll->RemoveAtHead();
  cll->Print();	

  cout<<"Add Again..."<<endl;
  
  cll->Add(10);
  	cll->Print();
}
