#include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE];
bool vis[SIZE];
int hashFunction(int key) {
    return key % SIZE;
}
void insertWithoutReplacement(int key) {
    int index = hashFunction(key);
    int start = index;
    while (vis[index]) {
        index = (index + 1) % SIZE;
        if (index == start) {
            cout << "Hash Table Full!\n";
            return;
        }
    }

    hashTable[index] = key;
    vis[index] = true;
    cout << "Book " << key << " inserted at index " << index << endl;
}

void insertWithReplacement(int key) {
    int index = hashFunction(key);
    if (!vis[index]) {
        hashTable[index] = key;
        vis[index] = true;
        cout << "Book " << key << " inserted at index " << index << endl;
        return;
    }

    int existingKey = hashTable[index];
    int existingIDX = hashFunction(existingKey);

    if (existingIDX != index) {
        cout << "Replacing " << existingKey << " with " << key << endl;
        hashTable[index] = key;
        int i = (index + 1) % SIZE;
        while (vis[i]) {
           i = (i + 1) % SIZE;
        }
        hashTable[i] = existingKey;
        vis[i] = true;
    } 
    else {
        int i = (index + 1) % SIZE;
        while (vis[i]) 
           i = (i + 1) % SIZE;
        hashTable[i] = key;
        vis[i] = true;
    }
    cout << "Book " << key << " inserted (with replacement)\n";
}

void searchBook(int key) {
    int index = hashFunction(key);
    int start = index;
    while (vis[index]) {
        if (hashTable[index] == key) {
            cout << "Book " << key << " found at index " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) break;
    }
    cout << "Book not found\n";
}

void deleteBook(int key) {
    int index = hashFunction(key);
    int start = index;
    while (vis[index]) {
        if (hashTable[index] == key) {
            vis[index] = false;
            cout << "Book " << key << " deleted from index " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) break;
    }
    cout << "Book not found\n";
}

void displayTable() {
    cout << "\n--- Hash Table ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        if (vis[i]) 
           cout << hashTable[i];
        else cout << "Empty";
        cout << endl;
    }
}

int main() {
    int ch, key;
    do {
        cout << "\n1.Insert (Without Replacement)\n2.Insert (With Replacement)\n3.Search\n4.Delete\n5.Display\n6.Exit\nEnter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter Accession Number: ";
            cin >> key;
            insertWithoutReplacement(key);
        } 
        else if (ch == 2) {
            cout << "Enter Accession Number: ";
            cin >> key;
            insertWithReplacement(key);
        } 
        else if (ch == 3) {
            cout << "Enter Accession Number: ";
            cin >> key;
            searchBook(key);
        } 
        else if (ch == 4) {
            cout << "Enter Accession Number: ";
            cin >> key;
            deleteBook(key);
        } 
        else if (ch == 5) {
            displayTable();
        } 
        else if (ch == 6) {
            cout << "Exiting...\n";
        } 
        else {
            cout << "Invalid choice\n";
        }

    }
     while (ch != 6);
}
