#include <iostream>
using namespace std;

class Node
{
  public :
    int data;
    Node* next;
    Node* prev;
    
    Node(int _data){
    	data=_data;
    	next=NULL;
    	prev=NULL;
	}
};

class DoublyLinkedList
{
  private :
    Node* top;
    Node* mid;
    int count;
  
  public :
    
    DoublyLinkedList()
    {
      top = NULL;
      mid = NULL;
      count = 0;
    }

    void push(int value)
    {
      Node* newNode = new Node(value);
      

      if(newNode == NULL)
      {
        cout<<"Stack Overflow";
        exit(1);
      }
      
      if(top == NULL)
      {
        top = newNode;
        mid = newNode;
        count++;
      }
      else
      {
        newNode -> next = top;
        top -> prev = newNode;
        top = top -> prev;
        count++;
        cout<<"Count ::"<<count<<endl;
           cout<<"mid->data previous :"<<mid->data<<endl;
             cout<<"top :"<<top->data<<endl;
        if(count%2 == 0)
        {
          mid = mid->prev;
          cout<<"mid->data :"<<mid->data<<endl;
          cout<<"top :"<<top->data<<endl;
        }
      }
    }

    int pop()
    {
      Node* temp = top;
      int value =temp->data;

      if ( top == NULL)
      {
          cout<<"Stack Underflow"<<endl;
          exit(1);
      }      
      else
      {
        top = top -> next;
        count--;
        if(count % 2 != 0)
        {
          mid = mid -> next;
        }
        delete temp;
      }
       return value;
    } 

    int getMid()
    {    
      return mid->data;
    }

    void removeMid()
    {
      Node* tempM = mid;

      if(mid -> next == NULL)
      {
        tempM =NULL;
        top = NULL;
        count = 0 ;

        delete tempM;
      }
      else if (mid -> prev == NULL && top == mid)
      {
        top = top -> next;
        count--;
        mid = mid -> next;
        top -> prev = NULL;
        delete tempM; 
      }
      else
      {
        Node* pre = mid -> prev;
        Node* nex = mid -> next;

        pre -> next = nex;
        nex -> prev = pre;
        count--;
        
        if(count%2 == 0)
        {
          mid = pre;
        }
        else
        {
          mid = nex;
        }
       delete tempM;
      }
    }

    void display()
    {
      if(top == NULL)
      {
        cout<<"Stack Underflow";
        exit(1);
      }

      Node* temp = top;
      while(temp != NULL)
      {
        cout<<temp->data<<"->";
        temp = temp -> next;
      }
    }
};

class Stack
{
  private :
    DoublyLinkedList* dl;

  public :

   Stack()
   {
      dl =  new DoublyLinkedList();
   }

   void push(int value)
   {
     dl->push(value);
   }

   int pop()
   {
      return dl->pop();
   }

   int getMid()
   {
      if ( dl->getMid() == 0)
      {
        cout<<"Error :Stack is Empty"<<endl;
      }
      return dl->getMid();
   } 

   void removeMiddle()
   {
     dl->removeMid();
   }

   void Display()
   {
     dl->display();
   }
};

int main() 
{
  Stack* st = new Stack();

  st->push(1);
 st->push(22);
 // st->push(3);
 // st->push(4);
 // st->push(5);
  

 
  cout<<"\nMid is "<<st->getMid();
  cout<<endl;

  st->Display();
  cout<<endl;


}
