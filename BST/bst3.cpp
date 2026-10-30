
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* root = nullptr;

// Create the complete tree in one function call
Node* makeTree(int val) {

    int c;
    Node* newNode = new Node(val);

    if (root == nullptr) {
        root = newNode;
    }

    cout << "Enter a value (-1 to stop): ";
    cin >> c;

    while (c != -1) {

        if (c < root->data) {
            Node* temp = root;

            while (temp->left != nullptr && c < temp->data) {
                temp = temp->left;
            }

            if (c < temp->data)
                temp->left = new Node(c);
            else
                temp->right = new Node(c);
        }
        else {
            Node* temp = root;

            while (temp->right != nullptr && c > temp->data) {
                temp = temp->right;
            }

            if (c > temp->data)
                temp->right = new Node(c);
            else
                temp->left = new Node(c);
        }

        cout << "Enter a value (-1 to stop): ";
        cin >> c;
    }

    return root;
}

// Insert a new node in the existing BST
Node* insert(Node* root, int val) {

    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);

    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Inorder
void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder
void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder
void postorder(Node* root) {
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {

    int val;

    cout << "Enter root value: ";
    cin >> val;

    makeTree(val);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    // Adding a new node whenever required
    cout << "\nEnter a new node to insert: ";
    cin >> val;

    root = insert(root, val);

    cout << "\nUpdated Inorder: ";
    inorder(root);

    return 0;
}
