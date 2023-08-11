#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    Node *prev;
    
    Node(int _data){
    	data=_data;
    	next=NULL;
    	prev=NULL;
	}
};

class DoublyLinkedList
{
  private:
    Node *head;
  public:
    DoublyLinkedList()
    {
      head = NULL;
    }

    void Add(int _data)
    {
      Node *node = new Node(_data);
      

      if(head == NULL)
      {
        head = node;     
		return;   
      }
      
      
        Node* temp= head;
        while(temp->next !=NULL){
        	temp= temp->next;
		}
      temp->next=node;
      node->prev=temp;
   
    }

    void Remove()
    {
      Node *temp = head;
      
    while(temp->next!=NULL){
    	
    	temp=temp->next;
	}
       
       temp->prev->next=NULL;

    //  cout <<"\nRemoving Node from tail : " << tail->data << endl; 
      delete temp;
      
      cout <<"Updated List " << endl;
      Display();      
    }

    void Display()
    {
      Node *temp = head;
      
      while(temp != NULL)
      {
        cout << temp->data << " "; 
        temp = temp->next;
      }
      cout << endl;
    }   
};

int main() 
{
  DoublyLinkedList *dll = new DoublyLinkedList();

  dll->Add(10);
  dll->Add(20);
  dll->Add(30);
  dll->Add(40);
  dll->Add(50);

  cout << "list " << endl;
  dll->Display(); 
cout<<"Remove------------------"<<endl;
  dll->Remove();
  dll->Add(50);
 dll->Display();
  
  
}
