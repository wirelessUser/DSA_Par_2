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
    Node *head, *last;
    
  public:
    LinkedList()
    {
      head = NULL;
      last = head;
    }

    void InsertAtHead(int _data)
    { 
        Node *node = new Node();
        node->data = _data;
        node->next = NULL;

    if (head == NULL) 
    {
        head = node;
        last = head;
    }
    else if(head != NULL)
    {
        node->next = head;
    } 
     
    head = node;
    } 

    void InsertAtTail(int _data)
    {
        Node *node = new Node();
        node->data = _data;
        node->next = NULL;

        last->next = node;
        last = last->next;    
    }


    void display()
    {
        Node *node = new Node();
        node = head;
        cout<<"------------Start of List-------------"<< endl;
        while(node != NULL)
        {
            cout << node->data << endl;
            node = node->next;
        }
        cout<<"------------End of List-------------"<<endl;
    }
};

int main() 
{
  LinkedList *list = new LinkedList();

  list->InsertAtHead(10);
  list->display();
  
  list->InsertAtHead(20);
  list->display();
  
  list->InsertAtHead(30);
  list->display();
  
  list->InsertAtTail(200);
  list->display();
 
}
