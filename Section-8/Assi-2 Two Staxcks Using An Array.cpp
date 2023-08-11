#include <iostream>
using namespace std;

template<typename T>
class StackUsingArray {
public:
    T* arr;
    int front, front2;
    int size;

    StackUsingArray(int _size) {
        size = _size;
        arr = new T[size];
        front = 0;
        front2 = size - 1;
    }

    void Push1(T x) {
        if (front + 1 == front2) {
            cout << "Stack 1 is full." << endl;
            return;
        }
        arr[front] = x;
        front++;
    }

    void Push2(T x) {
        if (front2 - 1 == front) {
            cout << "Stack 2 is full." << endl;
            return;
        }
        arr[front2] = x;
        front2--;
    }

    void Pop1() {
        if (IsEmpty1() == true) {
            cout << "Stack 1 is empty." << endl;
            return;
        }
        front--;
    }

    void Pop2() {
        if (IsEmpty2() == true) {
            cout << "Stack 2 is empty." << endl;
            return;
        }
        front2++;
    }

    bool IsEmpty1() {
        return (front == 0);
    }

    bool IsEmpty2() {
        return (front2 == size-1);
    }

    T getTop1() {
        if (IsEmpty1()) {
            cout << "Stack 1 is empty." << endl;
            return -1;
        }
        return arr[front - 1];
    }

    T getTop2() {
        if (IsEmpty2()) {
            cout << "Stack 2 is empty." << endl;
            return -1;
        }
        return arr[front2+1];
    }
};

int main() {
    StackUsingArray<int> obj(8);

    cout << "Popping in 1" << endl;
    obj.Pop1();

    cout << "Pushing in 1" << endl;
    obj.Push1(1);
    obj.Push1(2);
    obj.Push1(3);

    cout << "Get Top from 1" << endl;
    cout << obj.getTop1() << endl;

    cout << "Pushing in 2" << endl;
    obj.Push2(11);
    obj.Push2(22);
    obj.Push2(33);
    obj.Push2(44);
    obj.Push2(55);
    obj.Push2(66);
    obj.Push2(77);
    obj.Push2(88);

    cout << "Get Top from 2" << endl;
    cout << obj.getTop2() << endl;

    return 0;
}

