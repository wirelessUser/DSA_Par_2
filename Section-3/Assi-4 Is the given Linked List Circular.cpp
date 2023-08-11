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

class CircularLinkedList 
{
private:
  Node *head;
  
public:
  CircularLinkedList() { head = NULL; }

  void Add(int _data) 
  {
    Node *node = new Node(_data);

    if (head == NULL) 
    {
      head = node;
      node->next = head;
    } 
    else 
    {
      Node *lastnode = head;
      while (lastnode->next != head) 
      {
        lastnode = lastnode->next;
      }
      lastnode->next = node;
      node->next = head;
    }
  }

  bool IsCircular() 
  {    
    Node* temp=head;
	
	while(temp->next!=head && temp->next!=NULL){
		temp=temp->next;
	}  
	
	if(temp->next==head){
		return true;
	}else if(temp->next==NULL){
		return false;
	}
	
  }//IsCircular..

  void display() 
  {
    if (head == NULL)
      cout << "List is Empty" << endl;
    else 
    {
      Node *temp = head;
      cout << "\nList " << endl;

      while (temp->next != head)
      {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << temp->data << endl;
    }
  }  
};

int main() 
{
  CircularLinkedList *cll = new CircularLinkedList();

  cll->Add(10);
  cll->Add(20);
  cll->Add(30);
  cll->Add(40);
  cll->Add(50);
 
  cll->display();
  if(cll->IsCircular())
        cout << "List is Circular " << endl;
    else
        cout << "List is Not Circular " << endl;	 
}
