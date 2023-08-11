#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
};

class Outscal {
public:
  bool detectpalindrome(Node *head) {
    if (head == NULL || head->next == NULL) {
      return true; // Fixed: Return true for empty or single-node list
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }
//cout<<"curr->next"<<slow->data<<endl;
    // Reversing the ll after finding the midpoint...
    Node *prev = NULL;
    Node *curr = slow;
    Node *nextNode = NULL;
    while (curr != NULL) {
      nextNode = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextNode;
    }
         //cout<<"curr->next"<<curr->data<<endl;
    // Now the ll is split into two parts, one is original and the other is reverse.
    // So let's compare both parts ...
    Node *start = head;
    Node *end = prev;
    while (start != NULL && end != NULL) { 
          cout<<"start->data :"<<start->data<<" And "<<"end->data :"<<end->data<<endl;
      if (start->data != end->data) { 
        return false;
      } else {
        start = start->next;
        end = end->next;
      }
    }

    return true;
  } // palindrome function...
};

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
  class Outscal s;
  bool t = s.detectpalindrome(head);
  if (t)
    cout << "true";
  else
    cout << "false";
  return 0;
}

