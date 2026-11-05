
#include <iostream>
#include <queue>
using namespace std;

// ----------------- Basic BST Helpers -----------------

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
    }
};

// Insert a node into the BST
Node* bstInsert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = bstInsert(root->left, key);
    }
    else if (key > root->key) {
        root->right = bstInsert(root->right, key);
    }

    return root; // Duplicates are ignored
}

// Inorder traversal
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Count total nodes
int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

// Free allocated memory
void freeTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);

    delete root;
}

// ----------------- BST Helper Functions -----------------

// Step 1: Store BST keys in a sorted array using inorder traversal
void storeInorder(Node* root, int arr[], int& idx) {
    if (root == nullptr) {
        return;
    }

    storeInorder(root->left, arr, idx);

    arr[idx++] = root->key;

    storeInorder(root->right, arr, idx);
}

// Step 2: Build a balanced BST from the sorted array
Node* buildBalancedTree(int arr[], int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;

    Node* root = new Node(arr[mid]);

    root->left = buildBalancedTree(arr, start, mid - 1);
    root->right = buildBalancedTree(arr, mid + 1, end);

    return root;
}

// ----------------- Function to Balance a BST -----------------

Node* balanceBST(Node* root) {
    int n = countNodes(root);

    // Handle empty tree
    if (n == 0) {
        return nullptr;
    }

    int* arr = new int[n];

    int idx = 0;

    // Store inorder traversal into the array
    storeInorder(root, arr, idx);

    // Build and return balanced BST
    Node* balanced = buildBalancedTree(arr, 0, n - 1);

    delete[] arr;

    return balanced;
}
// Print tree in level order (uses the STL queue)
void printLevelOrder(Node* root)
{
    if (root == nullptr)
    {
        cout << "(empty)";
        return;
    }

    queue<Node*> qq;
    qq.push(root);

    while (!qq.empty())
    {
        Node* curr = qq.front();
        qq.pop();

        cout << curr->key << " ";

        if (curr->left)
            qq.push(curr->left);

        if (curr->right)
            qq.push(curr->right);
    }
}

// Lab Manual 09

int main()
{
    // Constructing the unbalanced BST shown in the figure above
    Node* root = new Node(4);

    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);

    root->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    cout << "Level Order of Unbalanced BST:\n";
    printLevelOrder(root);
    cout << endl;

    // Balance the BST
    Node* balancedRoot = balanceBST(root);

    // Print in Level Order
    cout << "Level Order of Balanced BST:\n";
    printLevelOrder(balancedRoot);
    cout << endl;

    freeTree(root);
    freeTree(balancedRoot);

    return 0;
}
