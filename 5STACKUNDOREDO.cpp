#include <bits/stdc++.h>
using namespace std;

stack<string> undoStack, redoStack;
vector<string> versions;
string cur = "", original = "";

void snapshot() { 
    versions.push_back(cur);
 }

void makeChange(string s) {
    undoStack.push(cur);
    cur = s;
    while(!redoStack.empty()) 
        redoStack.pop();
    snapshot();
}
void undo() {
    if(undoStack.empty()) 
        return;
    redoStack.push(cur);
    cur = undoStack.top();
    undoStack.pop();
    snapshot();
}
void redo() {
    if(redoStack.empty()) 
         return;
    undoStack.push(cur);
    cur = redoStack.top();
    redoStack.pop();
    snapshot();
}
void display() { cout<<"Current curument: "<<cur<<"\n"; }
void save() {
    while(!undoStack.empty()) undoStack.pop();
    while(!redoStack.empty()) redoStack.pop();
    snapshot();
    cout<<"curument Saved\n";
}
void showUndo() {
    stack<string> t=undoStack;
    cout<<"Undo History:\n";
    while(!t.empty()){ cout<<t.top()<<"\n"; t.pop(); }
}
void showRedo() {
    stack<string> t=redoStack;
    cout<<"Redo History:\n";
    while(!t.empty()){ 
        cout<<t.top()<<"\n"; t.pop(); }
}
void revert() {
    cur = original;
    while(!undoStack.empty()) undoStack.pop();
    while(!redoStack.empty()) redoStack.pop();
    snapshot();
    cout<<"Reverted to Original\n";
}
void showVersions() {
    for(int i=0;i<versions.size();i++)
        cout<<"Version "<<i<<": "<<versions[i]<<"\n";
}
int main() {
    original = "";
    versions.push_back(cur);
    int ch;
    string s;
    while(true){
        cout<<"\n1.Make Change 2.Undo 3.Redo 4.Display 5.Save 6.Show Undo 7.Show Redo 8.Revert 9.Show Versions 10.Exit\n";
        cin>>ch;
        cin.ignore();
        if(ch==1){ getline(cin,s); makeChange(s); }
        else if(ch==2) undo();
        else if(ch==3) redo();
        else if(ch==4) display();
        else if(ch==5) save();
        else if(ch==6) showUndo();
        else if(ch==7) showRedo();
        else if(ch==8) revert();
        else if(ch==9) showVersions();
        else break;
    }
}


