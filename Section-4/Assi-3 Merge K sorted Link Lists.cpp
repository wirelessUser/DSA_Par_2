#include <iostream>
using namespace std;
#define k 3

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

Node* arr[k];

class SinglyLinkedList
{
  private:
    Node *head;
    
  public:
    SinglyLinkedList()
    {
        head = NULL;
    }
  
    Node * Add(int _data)
    {
         Node *newNode = new Node(_data);
    
        if(head == NULL)
        {
            head = node;        
        } 
        else 
        {
            Node *lastnode = head;
            while(lastnode->next != NULL)
            {
                lastnode = lastnode->next;
            }
            lastnode->next = node;            
        }  
        return node;
    }
};

Node* mergeKLists(Node* arr[])
{
  
  
}//mergeKLists...

void display(Node *head)
{      
  if(head == NULL)
      cout <<"List is Empty" << endl;
  else
  {
    Node *temp = head;
    cout <<"List " << endl;
    while(temp != NULL)
    {
        cout <<  temp->data << " -> ";
        temp = temp->next;
    }      
    cout << "NULL" << endl;
  }
}

int main()
{
    SinglyLinkedList *l1 = new SinglyLinkedList();
    arr[0] = l1->Add(1);
    arr[0]->next = l1->Add(3);
    arr[0]->next->next = l1->Add(5);
    arr[0]->next->next->next = l1->Add(7);
  
    SinglyLinkedList *l2 = new SinglyLinkedList();
    arr[1] = l2->Add(2);
    arr[1]->next = l2->Add(4);
    arr[1]->next->next = l2->Add(6);
    arr[1]->next->next->next = l2->Add(8);

    SinglyLinkedList *l3 = new SinglyLinkedList();
    arr[2] = l3->Add(0);
    arr[2]->next = l3->Add(9);
    arr[2]->next->next = l3->Add(10);
    arr[2]->next->next->next = l3->Add(11);
 
    display(arr[0]);
    display(arr[1]);
    display(arr[2]);

    Node* head = mergeKLists(arr);
    cout << "The Sorted List :"<< endl;
    display(head);
}
