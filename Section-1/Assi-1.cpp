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
            node->next=head;
            head=node;
        } 
    }

    void Print()	
    { 
        Node *node = new Node();
        node = head;
        while(node != NULL)      
        {
            cout<<node->data<<"\n";			
            node = node->next;
        }
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

    list->Print();	  		
}
