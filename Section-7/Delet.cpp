#include <iostream>
#include <stack>
#include <string>
using namespace std;

string ReverseNum(int num) {
    stack<char> myStack;

    while (num != 0) {
        myStack.push('0' + num % 10);
        num /= 10;
    }

    string res;
    while (!myStack.empty()) {
        res.push_back(myStack.top());
        myStack.pop();
    }
    
   while (originalNumber % 10 == 0 && originalNumber != 0) {
    revNum *= 10;
    originalNumber /= 10;
  }
  
  
    return res;
}

int main() {
    int number1 = 120;
    int number2 = 12340;
    int number3 = 1;

    cout << "Original num == " << number1 << endl;
    cout << "Reversed Number: " << ReverseNum(number1) << endl;

    return 0;
}

