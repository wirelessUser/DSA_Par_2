#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
       Node(int _data){
    	
    	data= _data;
    	next=NULL;
	}
};

class SinglyLinkedList {
public:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    void Add(int _data) {
        Node* node = new Node(_data);
        node->data = _data;
        node->next = NULL;

        if (head == NULL) {
            head = node;
        } else {
            Node* lastnode = head;
            while (lastnode->next != NULL) {
                lastnode = lastnode->next;
            }
            lastnode->next = node;
        }
    }

    void ReverseList(Node*& head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void RearrangeList(Node*& head) {
        if (head == NULL || head->next == NULL) {
            return; // No need to rearrange if the list is empty or has only one node
        }

        Node* slow = head;
        Node* fast = head->next;

        while (fast->next->next != NULL&& fast->next != NULL  ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<"Slow->data"<<slow->data<<endl;
        Node* mid = slow;
        Node* first = head;
        Node* second = mid->next;
        mid->next = NULL;

        ReverseList(second); // Reverse the second half of the list

        MergeLL(first, second); // Merge the two halves
    }

    void MergeLL(Node*& l1, Node*& l2) {
        while (l1 != NULL && l2 != NULL) {
            Node* next1 = l1->next;
            Node* next2 = l2->next;

            l1->next = l2;
            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is Empty" << endl;
        } else {
            Node* temp = head;
            cout << "\nList " << endl;
            while (temp != NULL) {
                cout << temp->data << "->" << " ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
    }
};

int main() {
    SinglyLinkedList* cll = new SinglyLinkedList();

    cll->Add(10);
    cll->Add(20);
    cll->Add(30);
    cll->Add(40);
    cll->Add(50);
   // cll->Add(60);

    cout << "Before rearrange:" << endl;
    cll->display();

    cout << "After rearrange:" << endl;
    cll->RearrangeList(cll->head);
    cll->display();

    return 0;
}

