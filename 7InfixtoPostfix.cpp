#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

string infixToPostfix(const string &expr) {
    stack<char> st;
    string ans;
    for (char c : expr) {
        if (isspace(c)) continue;

        if (isalnum(c)) ans.push_back(c);

        else if (c == '(') 
            st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans.push_back(st.top());
                 st.pop();
            }
            if (!st.empty()) 
               st.pop();
        } 

        else if (isOperator(c)) {
            while (!st.empty() && isOperator(st.top())) {
                int pTop = precedence(st.top());
                int pCur = precedence(c);
                if (pTop > pCur || (pTop == pCur && c != '^')) {
                    ans.push_back(st.top());
                     st.pop();
                   } 
                else 
                  break;
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        ans.push_back(st.top());
         st.pop();
    }
    return ans;
}

int main() {
    string expr;
    cout<< "Enter infix expression: ";
    getline(cin, expr);
    string postfix = infixToPostfix(expr);
    cout<< "Postfix expression: " << postfix << "\n";
    return 0;
}
