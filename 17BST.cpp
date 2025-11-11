#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}
Node* search(Node* root, int val) {
    if (root == NULL || root->data == val) return root;
    if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}
Node* deleteNode(Node* root, int val) {
    if (root == NULL) return root;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    int ch, val;
    do {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n7. Exit\nEnter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            root = insert(root, val);
        }
        else if (ch == 2) {
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
        }
        else if (ch == 3) {
            cout << "Enter value to search: ";
            cin >> val;
            Node* res = search(root, val);
            if (res) cout << "Found!\n";
            else cout << "Not found!\n";
        }
        else if (ch == 4) {
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
        }
        else if (ch == 5) {
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
        }
        else if (ch == 6) {
            cout << "Postorder: ";
            postorder(root);
            cout << endl;
        }
        else if (ch == 7) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (ch != 7);

    return 0;
}
