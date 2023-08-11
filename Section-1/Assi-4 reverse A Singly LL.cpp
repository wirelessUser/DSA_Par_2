#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    
    
};

class LinkedList
{
  Node *head;
  public:
    LinkedList()
    {
       head = NULL; 
    }

    void Add(int _data)
    {
      Node *node = new Node();
      node->data = _data;
      node->next = NULL;
      
      if(head == NULL)
      {
        head = node;
      } 
      else
      {
        Node *lastNode = head;
        
        while(lastNode->next != NULL)
        {
          lastNode = lastNode->next;
        }        
        lastNode->next = node;        
      }      
    }

    void reverseList()
    {
      Node *curr = head;
      Node *prev=NULL;
	  Node* next=NULL;
	  
	  while(curr!=NULL){
	  	
	  	next=curr->next;
	  	curr->next=prev;
	  	
	  	prev=curr;
	  	curr=next;
	  }
	  head=prev;
	  
}
    void display()
    {
      Node *node = head;

      while(node != NULL)
      {
        cout << node->data << " -> ";
        node = node->next;
      }
      cout << endl;
    }
};

int main() 
{
  LinkedList *list = new LinkedList();

  list->Add(10);
  list->Add(20);
  list->Add(30);
  list->Add(40);
  list->Add(50);

  cout <<endl<<"List Before Reverse : " <<endl;
  list->display();

  list->reverseList();

  cout <<endl<<"List After Reverse : " <<endl;
  list->display();
}
