#include <iostream>
#include <stack>
using namespace std;

bool CheckBalanceParnthesis(string par) {
    stack<char> myStack;
    int len = par.length();

    for (int i = 0; i < len; i++) {
        char curr = par[i];
        if (curr == '(' || curr == '{' || curr == '[') {
            myStack.push(curr);
        } else if (curr == ')' || curr == '}' || curr == ']') {
            if (myStack.empty() ||
                (curr == ')' && myStack.top() != '(') ||
                (curr == '}' && myStack.top() != '{') ||
                (curr == ']' && myStack.top() != '[')) {
                return false;
            }
            myStack.pop();
        }
    }

    return myStack.empty();
}

int main() {
    string parentheses1 = "{[()]}";
    string parentheses2 = "[(])";

    cout << "Is " << parentheses1 << " balanced? " << (CheckBalanceParnthesis(parentheses1) ? "Yes" : "No") << endl;
    cout << "Is " << parentheses2 << " balanced? " << (CheckBalanceParnthesis(parentheses2) ? "Yes" : "No") << endl;

    return 0;
}

