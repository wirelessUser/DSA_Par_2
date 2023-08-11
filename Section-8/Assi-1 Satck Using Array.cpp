#include <iostream>
using namespace std;

template<typename T>
class StackUsingArray {
public:
    T* arr;
    int front;

    StackUsingArray(int size) {
        arr = new T[size];
        front = 0;
    }

    void Push(T x) {
        arr[front] = x;
        front++;
    }

    void Pop() {
        if (IsEmpty() == true) {
            cout << "@Nothing to Pop, it's empty.." << endl;
            return;
        }
        front--;
    }

    bool IsEmpty() {
        return (front == 0);
    }

    T getTop() {
        if (IsEmpty()) {
            cout << "Stack is empty.." << endl;
            return -1;
        }
        return arr[front - 1];
    }
};

int main() {
    StackUsingArray<int> obj(10);

    cout << "Popping" << endl;
    obj.Pop();

    cout << "Pushing" << endl;
    obj.Push(1);
    obj.Push(2);
    obj.Push(3);

    cout << "Get Top" << endl;
    cout << obj.getTop() << endl;

    return 0;
}

