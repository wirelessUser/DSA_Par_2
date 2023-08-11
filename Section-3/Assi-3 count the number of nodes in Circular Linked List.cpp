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
    int numberOfNodes;
  
  public:
    CircularLinkedList()
    {
      head = NULL;
      numberOfNodes = 0;
    }

    void Add(int _data)
    {
     Node *node = new Node(_data);

      if(head == NULL)
      {
        head = node;
        node->next = head;
      } 
      else 
      {
        Node *lastnode = head;
        while(lastnode->next != head)
        {
          lastnode = lastnode->next;
        }
        lastnode->next = node;
        node->next = head;        
      }   
      numberOfNodes++;
    }

    void Remove()
    {
      Node *lastnode = head;
      Node *node = NULL;
          
      while(lastnode->next->next != head)
      {
         lastnode = lastnode->next;
      }

      node = lastnode->next;
      lastnode->next = node->next;
      
      cout <<endl<< "Removing Node : "<< node->data << endl;
      delete node;
      numberOfNodes--;
      if(numberOfNodes <= 0)
      {
        head = NULL;
      }      
    }

    void display()
    {
      int count=1;
      if(head == NULL)
        cout <<"List is Empty"<<"nodes=0 " << endl;
      else
      {
        Node *temp = head;
        cout <<"\nList " << endl;
        while(temp->next != head)
        {
          cout << temp->data << " ";
          temp = temp->next;
          count++;
        }        
        cout <<temp->data << endl;
      }
      cout <<"Number of node=="<<count<<"  "<<endl;
    }
  
    void DisplayNumberOfNode()
    {
        cout << "\nNumber Of Nodes: "<<numberOfNodes <<endl;
    }
};

int main() 
{
  CircularLinkedList *cll = new CircularLinkedList();

  cll->Add(10);
  cll->Add(20);

  cll->display(); 
  //cll->DisplayNumberOfNode();
  
  cll->Add(30);
  cll->Add(40);
  cll->Add(50);

  cll->display(); 
  //cll->DisplayNumberOfNode(); 

  cll->Remove();
  cll->Remove();
  
  cll->display(); 
 // //cll->DisplayNumberOfNode(); 
  
//  cll->Remove();
 // cll->Remove();
 // cll->Remove();
  
 // cll->display(); 
 // cll->DisplayNumberOfNode();  
}
