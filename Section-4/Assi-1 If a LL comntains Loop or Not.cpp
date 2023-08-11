#include <bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    
    Node(int _data){
    	
    	data= _data;
    	next=NULL;
	}
};

class LinkedList
{
  private:
    Node *head;
    int totalNode;
  public:
    LinkedList()
    {
      head = NULL;
      totalNode = 0;
    }

    void add(int _data)
    {
     Node *node = new Node(_data);

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
      totalNode++;
    }

    bool DetectLoop()
    {
       Node* slow=head;
       Node* fast=head;
       
       while(fast->next!=NULL){
       	
       	if(slow==fast){
       		return true;
		   }
		  slow=slow->next;
		  fast=fast->next->next; 
		   
	   }
	   
	   	return false;
    }//DetectLoop

    void makelastnodehead()
    {
        cout << endl << "Creating loop by making last Node Head ";
        Node *lastnode = head;
        while (lastnode->next != NULL) 
        {
          lastnode = lastnode->next;
        }
        lastnode->next = head->next->next->next;
      }

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

  list->add(10);
  list->add(20);
  list->add(30);
  list->add(40);
  list->add(50); 
  list->display();

  list->DetectLoop() ? cout << endl <<"There is LOOP" : cout << endl <<"There is no LOOP";  

  list->add(60);
  list->makelastnodehead();

  list->DetectLoop() ? cout << endl <<"There is LOOP" : cout << endl <<"There is no LOOP";    
}
