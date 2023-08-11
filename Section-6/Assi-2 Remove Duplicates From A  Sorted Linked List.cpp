#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
};

class Outscal {
public:
  void removeDuplicates(Node *&head) {

    // base..
    if (head == NULL || head->next == NULL) {
      cout << "Nothing to do" << endl;
      return;
    }

    Node *curr = head;
    Node *second = curr->next;

    while(curr->next!=NULL){
    	if(curr->data==curr->next->data){	   	
    	   	curr->next=second->next;
    	   		curr= second;
		second= second->next;
		}else{
				curr= second;
		second= second->next;
		}
	
	}//while...
	
  }//removeDuplicates...
  
  
  
};

void printList(Node *node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
}

void push(Node **head_ref, int new_data) {
  Node *new_node = new Node();
  Node *last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}

int main() {
  int n, value;
  Node *head = NULL;
  cin >> n;
  while (n) {
    cin >> value;
    push(&head, value);
    n--;
  }
  cout << "................Original....................." << endl;
  printList(head);
  cout << "..................After ..................." << endl;
  class Outscal s;
  s.removeDuplicates(head);
  printList(head);
  return 0;
}
