#include <bits/stdc++.h>
using namespace std;
struct Node {
    int coeff;
    int exp;
    Node* next;
};
Node* insert(Node* head, int c, int e) {
    Node* newNode = new Node{c, e, nullptr};
    if (!head) 
        return newNode;
    Node* temp= head;
    while (temp->next) 
       temp= temp->next;
    temp->next = newNode;
    return head;
}
Node* input() {
    Node* head = nullptr;
    int n, c, e;
    cout << "No. of terms: "; cin >> n;
    for (int i=0; i<n; i++) {
        cout << "Coeff & Exp: ";
        cin >> c >> e;
        head= insert(head, c, e);
    }
    return head;
}
void display(Node* head) {
    if (!head) { 
        cout << "0\n"; 
        return;
     }
    while (head) {
        cout << head->coeff << "x^" << head->exp;
        if (head->next) 
           cout << " + ";
        head = head->next;
    }
    cout << "\n";
}
double eval(Node* head, int x) {
    double s = 0;
    while (head) {
        s += head->coeff * pow(x, head->exp);
        head = head->next;
    }
    return s;
}
Node* add(Node* a, Node* b) {
    Node* head = nullptr;
    while (a || b) {
        int c = 0, e;
        if (!b || (a && a->exp > b->exp)) { 
            c=a->coeff;
             e=a->exp; 
             a=a->next;
         }
        else if (!a || (b && b->exp > a->exp)) { 
            c=b->coeff; 
            e=b->exp;
             b=b->next; 
        }
        else { 
            c=a->coeff+b->coeff;
             e=a->exp; 
             a=a->next;
              b=b->next; 
            }
        if (c!=0) 
          head = insert(head, c, e);
    }
    return head;
}
Node* multiply(Node* a, Node* b) {
    Node* head= nullptr;
    for (Node* p=a; p; p=p->next)
        for (Node* q=b; q; q=q->next)
            head = insert(head, p->coeff*q->coeff, p->exp+q->exp);
    return head;
}
int main() {
    Node *p1=nullptr,*p2=nullptr,*res=nullptr;
    int ch,x;
    do {
        cout << "\n1.Input P1  2.Input P2  3.Show P1  4.Show P2\n"
             << "5.Eval P1  6.Add  7.Multiply  8.Show Result  9.Exit\nChoice: ";
        cin >> ch;
        if (ch==1)
           p1=input();
        else if (ch==2)
             p2=input();
        else if (ch==3) {
             cout<<"P1: ";
              display(p1); 
            }
        else if (ch==4) { 
            cout<<"P2: ";
             display(p2);
             }
        else if (ch==5) {
             cout<<"x=";
             cin>>x;
              cout<<"P1("<<x<<")="<<eval(p1,x)<<"\n"; 
            }
        else if (ch==6) { 
            res=add(p1,p2); 
            cout<<"Added.\n"; 
        }
        else if (ch==7) { 
            res=multiply(p1,p2);
             cout<<"Multiplied.\n";
             }
        else if (ch==8) { 
            cout<<"Result: ";
             display(res); 
            }
    } while (ch!=9);
}
