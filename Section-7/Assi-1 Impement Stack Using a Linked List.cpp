#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
  T data;
  Node *next;
  
  Node(T  _data){
  	  data= _data;
  	  next=NULL;
  }
  
  
};

// Stack = Last in  First Out....
template<typename T>
class StackUsingLL {

public:
   Node<T>* head;
   
   StackUsingLL(){
   	head=NULL;
   }
   
   
   
  void  Push(T x){
  	 
  	 Node<T>* newNode= new Node<T>(x);
  	 
  	 if(IsEmpty()){
  	 	head=newNode;
	   }
  	 
  	 newNode->next=head;
  	 head=newNode;
  }//Push...
   
   
   void Pop(){
   	
   	if(IsEmpty()){
   		cout<<"List is empty.."<<endl;
   		return;
	   }
	   
	   Node<T>* temp=head;
	   
	   head=head->next;
	   delete temp;
	   
   }//Pop...
   
   
   
   bool IsEmpty() {
   	if(head==NULL){
   		
   		return true;
	   }
	   return false;
   }//IsEmpty.
   
   
   T getTop(){
   	
   	 if(IsEmpty()){
   		cout<<"List is empty.."<<endl;
   		return -1;
	   }
	   return head->data;
	   
   }//getTop...
   
   
   
   
   
};





int main() {
 
 StackUsingLL<int>  obj;
 
 cout<<"Popping "<<endl;
 obj.Pop();
 
 cout<<"Pushing "<<endl;
 
 obj.Push(1);
  obj.Push(2);
   obj.Push(3);
   
 cout<<"Get Top"<<endl;
 
 cout<<obj.getTop();
}







