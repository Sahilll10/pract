#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
    char arr[SIZE];
    int top;
public:
    Stack() { 
        top = -1; 
    }
    void push(char c) {
        if (top < SIZE - 1) 
             arr[++top] = c;
        else
           cout << "Stack Overflow\n";
    }
    char pop() {
        if (top == -1) 
           return '\0';
        return arr[top--];
    }
    bool isEmpty() {
        return top == -1;
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string exp) {
    Stack st;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i]== '(' || exp[i] == '{' || exp[i] == '[')
            st.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (st.isEmpty()) 
               return false;
            char top = st.pop();
            if (!isMatchingPair(top,exp[i])) 
                return false;
        }
    }
    return st.isEmpty();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Expression is well parenthesized.\n";
    else
        cout << "Expression is NOT well parenthesized.\n";

    return 0;
}
