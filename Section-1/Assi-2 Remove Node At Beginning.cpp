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
        cout<<"\n";    
    }

   void remove(int _data)
{
    Node *node = head;
    Node *prev = NULL;

    if (node == NULL) {
        cout << "Empty List" << endl;
        return;
    }

    // Find the node to be removed
    while (node != NULL) {
        if (node->data == _data) {
            break;
        }
        prev = node;
        node = node->next;
    }

    if (node == NULL) {
        cout << "Node with this data doesn't exist" << endl;
        return;
    }

    // Removing head node
    if (prev == NULL) {
    	cout<<"Imnside previous";
       // head = node->next;
        delete node;
        head=NULL;
    } else {
        prev->next = node->next;
        delete node;
    }
}

	  
};

int main() 
{
    LinkedList *list = new LinkedList();
    
    list->Add(10);
  

    list->Print();	

    list-> remove(10);
cout<<"After removal....."<<endl;
    list->Print();		
    
    cout<<"Again Isnerting.."<<endl;
    
      list->Add(20);
    list->Add(30);
    list->Add(40);
   list->Add(50);
   
     list->Print();
}
