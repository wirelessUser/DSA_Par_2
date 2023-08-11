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
       Node *node = new Node(_data);
  
        if (head == NULL)
        {
            head = node;          
        } 
        else 
        {
            Node *lastnode = head;
            while (lastnode->next != NULL)
            {
                lastnode = lastnode->next;
            }
            lastnode->next = node;        
        }
    }

    void MakeListCircular()
    {
        if (head == NULL || head->next == NULL) {
            cout << "List is  empty." << endl;
            return;
        }
       
        
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
        
        DisplayCircularFromPosition();
    }

    void DisplayCircularFromPosition()
    {      
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node* temp = head;
        do
        {
            cout << "temp->data: " << temp->data << " ";
            temp = temp->next;
        } while (temp->next != head);
       
        cout << "Last node next data in simple LL: " << temp->next->data << endl;
    }

    void DisplaySinglyLinkedList()
    {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node *temp = head;
        cout << "List: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "Last node next data in simple LL: ";
        if (temp != NULL) {
            cout << temp->next->data << endl;
        } else {
            cout << "N/A" << endl;
        }
    }          
};

int main() 
{
    LinkedList *sll = new LinkedList();
  
    sll->Add(10);
    sll->Add(20);
    sll->Add(30);
    sll->Add(40);
    sll->Add(50);
    cout << "Before making the list Circular.." << endl;
    sll->DisplaySinglyLinkedList(); 
    cout << "After making the list Circular.." << endl;
    sll->MakeListCircular();

    return 0;
}

