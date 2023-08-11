#include <iostream>
//#include<tuple>
#include <utility>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int _data) {
        this->data = _data;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    Node* Insert(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    void Print() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void Print(Node*& _head) {
        Node* temp = _head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    pair<Node*, Node*> reverseALL(Node*& _head, int count) {
        Node* temp = _head;
        Node* prev = NULL;
        Node* curr = _head;

        while (count > 0) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count--;
        }

        return { prev, curr };
    }

    Node* ReverseAPartOfLL(Node* _head, int _left, int _right) {
        if (_head == NULL || _head->next == NULL || _left == _right|| _left>_right) {
            return _head;
        }
       

        Node* prevLeft = _head;
        Node* left = _head;
        Node* nextToRight = _head;
        Node* right = _head;

        for (int i = 1; i < _left; i++) {
            prevLeft = left;
            left = left->next;
        }

        auto [reversedLeft, nextNode] = reverseALL(left, _right - _left + 1);
        right = reversedLeft;
        nextToRight = nextNode;

        if (prevLeft) {
            prevLeft->next = right;
        }
        else {
            _head = right;
        }
        left->next = nextToRight;

        return _head;
    }
};

int main() {

    LinkedList linkListObj;

    Node* head1 = linkListObj.Insert(1);
    Node* head2 = linkListObj.Insert(2);
    Node* head3 = linkListObj.Insert(3);
    Node* head4 = linkListObj.Insert(4);
    Node* head5 = linkListObj.Insert(5);

    // create a loop ...
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;

    head5->next = NULL;

    cout << "---------------- Original Linked List ------------------------" << endl;
    linkListObj.Print(head1);
    cout << "---------------- Reversed Sublist ------------------------" << endl;
    Node* reversedHead = linkListObj.ReverseAPartOfLL(head1, 2, 4);
    linkListObj.Print(reversedHead);

    return 0;
}

