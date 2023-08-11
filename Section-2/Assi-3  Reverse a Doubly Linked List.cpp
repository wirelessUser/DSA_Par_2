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
      }
      else 
      {
        Node *temp = head;

        while(temp->next != NULL)
        {
          temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;      
      }
    }

    void ReverseList()
    {
      Node *curr = head;  

     Node* next= head;
      Node* prev= NULL;
     while(curr!=NULL){
     	
     	next= next->next;
     	
     	curr->next= prev;
     	curr->prev= next;
     	prev=curr;
     	curr=next;
	 }
	 
	 head=prev;
	 
    }//ReverseList

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

  cout << "List " << endl;
  dll->Display();
  
  dll->ReverseList();
  cout << "List After Reverse " << endl;
  dll->Display();
}

