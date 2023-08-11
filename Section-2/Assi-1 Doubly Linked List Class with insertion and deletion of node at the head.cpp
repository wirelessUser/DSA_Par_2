#include <bits/stdc++.h>
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
         node->next= head;
		 head->prev= node;
		 
		 head=node;      
        }
    }

    void Remove()
    {
        Node *temp = head;
        cout <<"\nRemoving Node from Head : " << temp->data << endl; 
        temp->next->prev = NULL;
        head = temp->next;  
  
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
      
      dll->Display();
    
     dll->Remove();
      
      dll->Remove();   
}
