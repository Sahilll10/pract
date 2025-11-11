#include <bits/stdc++.h>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
    Student* next;
};
Student* head = NULL;

void insertStudent() {
    int r;
    string n;
    float m;
    cout << "Enter Roll, Name, Marks: ";
    cin >> r >> m;
    cin.ignore();
    getline(cin,n);
    Student* newStudent = new Student{r,n,m, nullptr};
    if (head == nullptr) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newStudent;
    }
    cout << "Student added successfully\n";
}

void deleteStudent(int roll) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Student* temp = head;
    Student* prev = nullptr;
    while (temp != nullptr && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Student not found\n";
        return;
    }
    if (prev == nullptr)
        head = head->next;
    else
        prev->next = temp->next;
    delete temp;
    cout << "Student deleted\n";
}
void traverse() {
    if (!head) { cout << "No records\n"; return; }
    Student* temp= head;
    while (temp) {
        cout << "Roll: " << temp->roll << "  Name: " << temp->name << "  Marks: " << temp->marks << endl;
        temp= temp->next;
    }
}
void searchStudent(int roll) {
    Student* temp= head;
    while (temp) {
        if (temp->roll == roll) {
            cout << "Found: " << temp->name << " (" << temp->marks << ")\n";
            return;
        }
        temp= temp->next;
    }
    cout << "Not found\n";
}
int length() {
    int count = 0;
    Student* temp= head;
    while (temp) {
         count++; 
         temp= temp->next;
         }
    return count;
}
void concatenate(Student* list2) {
    if (head == nullptr) {
        head = list2;
        return;
    }
    Student* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = list2;
    cout << "Lists concatenated successfully\n";
}
void bubbleSortByRoll() {
    int n = length();
    for (int i = 0; i < n - 1; i++) {
        Student* n1 = head;
        Student* n2 = head->next;
        for (int j = 0; j < n - i - 1 && n2; j++) {
            if (n1->marks > n2->marks) {
                swap(n1->roll, n2->roll);
                swap(n1->name, n2->name);
                swap(n1->marks, n2->marks);
            }
            n1 = n2;
            n2 = n2->next;
        }
    }
    cout << "List sorted by marks.\n";
}
int main() {
    int ch;
    do {
        cout << "\n1.Insert  2.Delete  3.Traverse  4.Search  5.Sort by Roll  6.Sort by Marks  7.Exit\nEnter choice: ";
        cin >> ch;
        if (ch == 1) insertStudent();
        else if (ch == 2) {
            int r; cout << "Enter Roll: "; cin >> r;
            deleteStudent(r);
        }
        else if (ch == 3) traverse();
        else if (ch == 4) {
            int r; cout << "Enter Roll: "; cin >> r;
            searchStudent(r);
        }
        else if (ch == 5) bubbleSortByRoll();
        else if (ch == 7) cout << "Exit\n";
        else cout << "Invalid\n";
    } while (ch != 7);
}
