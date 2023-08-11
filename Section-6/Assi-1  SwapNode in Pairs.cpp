#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* swap(Node* head) {
    // Base case
    if (head == NULL || head->next == NULL)
        return head;

    // taking two pointers for the first and second node
    Node* first = head;
    Node* second = head->next;
    Node* temp= second->next;
      second->next = first;
    first->next = swap(temp);;
   

    // new head will be the second node of the original list
    return second;
}

void printList(Node* head) {
    while (head) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
  //  head->next->next->next->next = new Node(5);
    std::cout << "Original List: ";
    printList(head);

    Node* swapped_head = swap(head);

    std::cout << "Swapped List: ";
    printList(swapped_head);

    return 0;
}

