#include <iostream>
using namespace std;

struct Node {
    int accession;
    Node* next;
};
Node* hashTable[10] = {NULL};
int hashFunction(int key) {
    return key % 10;
}

void insertBook(int num) {
    int index = hashFunction(num);
    Node* newNode = new Node{num, NULL};
    if (!hashTable[index])
       hashTable[index] = newNode;
    else {
        Node* temp = hashTable[index];
        while (temp->next) 
          temp = temp->next;
        temp->next = newNode;
    }
    cout << "Book inserted in bucket " << index << endl;
}

void searchBook(int num) {
    int index = hashFunction(num);
    Node* head = hashTable[index];
    while (head) {
        if (head->accession == num) {
            cout << "Book " << num << " found in bucket " << index << endl;
            return;
        }
        head = head->next;
    }
    cout << "Book not found\n";
}
void deleteBook(int num) {
    int index = hashFunction(num);
    Node* head = hashTable[index];
    if (head == nullptr) {
        cout << "Bucket " << index << " is empty\n";
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->accession != num) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Book not found in bucket " << index << endl;
        return;
    }
    if (prev == nullptr)
        head = head->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Book " << num << " deleted from bucket " << index << endl;
}


void displayTable() {
    for (int i = 0; i < 10; i++) {
        cout << "Bucket " << i << ": ";
        Node* temp = hashTable[i];
        if (!temp) cout << "Empty";
        while (temp) {
            cout << temp->accession << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    int ch, num;
    do {
        cout << "\n1.Insert Book\n2.Search Book\n3.Delete Book\n4.Display Table\n5.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter Accession Number: ";
                cin >> num;
                insertBook(num);
                break;
            case 2:
                cout << "Enter Accession Number: ";
                cin >> num;
                searchBook(num);
                break;
            case 3:
                cout << "Enter Accession Number: ";
                cin >> num;
                deleteBook(num);
                break;
            case 4:
                displayTable();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (ch != 5);
}

