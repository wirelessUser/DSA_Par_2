#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    void addNode(int val) {
        if (head == NULL) {
            head = new Node(val);
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new Node(val);
        }
    }

    void printList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    Node* partitionLinkedList(int x) {
        Node* lessDummy = new Node(0); // Pointer to a dummy node for nodes less than x
        Node* greaterDummy = new Node(0); // Pointer to a dummy node for nodes greater than or equal to x

        Node* lessTail = lessDummy; // Pointer to the tail of the less partition
        Node* greaterTail = greaterDummy; // Pointer to the tail of the greater partition

        Node* current = head;

        // Traverse the original list and add nodes to their respective partitions
        while (current != NULL) {
            if (current->data < x) {
                lessTail->next = current;
                lessTail = lessTail->next;
            } else {
                greaterTail->next = current;
                greaterTail = greaterTail->next;
            }
            current = current->next;
        }

        // Connect the two partitions to form the final linked list
        lessTail->next = greaterDummy->next;
        greaterTail->next = NULL; // Mark the end of the greater partition

        // Update head to point to the head of the less partition
        head = lessDummy->next;

        // Delete the dummy nodes (not the actual data nodes)
        delete lessDummy;
        delete greaterDummy;

        return head;
    }
};

int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(4);
    list.addNode(3);
    list.addNode(2);
    list.addNode(5);
    list.addNode(2);

    int x = 3;

    std::cout << "Original List: ";
    list.printList();

    Node* partitionedHead = list.partitionLinkedList(x);

    std::cout << "Partitioned List: ";
    while (partitionedHead) {
        std::cout << partitionedHead->data << " -> ";
        partitionedHead = partitionedHead->next;
    }
    std::cout << "nullptr" << std::endl;

    return 0;
}

