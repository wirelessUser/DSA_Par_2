#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
};

class Outscal {
public:
Node* reverse(Node* head, int k) {
    Node* curr = head;
    Node* prev = NULL;
    Node* nextNode = NULL;
    int count = 0;

    // Count the number of nodes in the current group
    while (curr != NULL && count < k) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }

    // At this point, 'prev' will point to the head of the reversed group,
    // and 'curr' will point to the head of the next group (k+1 node).

    // Now, 'curr' points to the head of the next group or NULL if there is no more group.

    // Recursively reverse the next group of size k and link it to the current group.
    if (curr != NULL) {
        head->next = reverse(curr, k);
    }

    // 'prev' now points to the new head of the reversed group.
    return prev;
}
 // func...
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
  int n, value, k;
  Node *head = NULL;
  cin >> n;
  while (n) {
    cin >> value;
    push(&head, value);
    n--;
  }
  cin >> k;
  class Outscal s;
  Node *temp = s.reverse(head, k);
  cout << endl;
  cout << "..................................." << endl;
  printList(temp);
  return 0;
}
