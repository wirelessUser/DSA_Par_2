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
  private:
    Node *head;
  public:
    LinkedList()
    {
      head = NULL;
    }

    void add(int _data)
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

    void AddAtPosition(int pos, int _data)
    {
      Node *node = new Node();
      node->data = _data;
      node->next = NULL;
          
          if(head==NULL){
          	head=node;
          	return;
		  }
  
    Node* curr=head;
    Node* prev=NULL;
      int count=1;
	  while(curr!=NULL){
	  	
	  	if(count==pos){
	  		break;
		  }
		  
		  prev=curr;
		  curr=curr->next;
		  count++;
	  }
	  prev->next=node;
	  node->next=curr;
	  
	  
  }//AddAtPosition..

    void RemoveAt(int pos)
    {
      Node *curr = head;
     Node *prev = NULL;
	 		 if(pos==1){
	 	head=head->next;
	 	
	 	delete curr;
	 	delete prev;
	 	return;
	 }
     
     if(head==NULL){
     	cout<<"Empty List"<<endl;
     	return;
	   }

	 int count=1;
	 while(curr!=NULL){

	 	if(count==pos){
	 		break;
		 }
		 prev=curr;
		 curr=curr->next;
		 
	 	count++;
	 }

	 	prev->next=curr->next;
	 
	 delete curr;
	 
    }//RemoveAt/...

    void display()
    {
      Node *node = head;
      if(head == NULL)
      {
        cout <<"\nList is Empty "<<endl;
      }
      else
      {
        while(node != NULL)
        {
          cout << node->data << " ";
          node = node->next;
        }
        cout << endl;
      }      
    }
};

int main() 
{
  LinkedList *list = new LinkedList();

  list->display();
  list->add(10);
 // list->add(20);
//  list->add(30);
//  list->add(40);
 // list->add(50);
 // list->display();
 // cout<<"After Removal----"<<endl;
 // list->RemoveAt(1);
  list->display();
cout<<endl;
  list->AddAtPosition(2,25);
  
  list->display();
}
