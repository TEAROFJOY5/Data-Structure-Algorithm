
#include <iostream>
using namespace std;

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

Node* root = nullptr;

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

    return root;
}

// Level Order Traversal
void levelOrder(Node* root) {

    if (root == NULL) {
        return;
    }

    Node* queue[100];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        cout << current->key << " ";

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

// Calculate height of a node
int height(Node* root) {

    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    else {
        return rightHeight + 1;
    }
}

// Calculate balance factor
int balanceFactor(Node* root) {

    if (root == nullptr) {
        return 0;
    }

    return height(root->left) - height(root->right);
}

// Check ALL nodes for AVL violations
bool checkAVL(Node* root) {

    if (root == nullptr) {
        return true;
    }

    bool isAVL = true;

    // Check current node
    int bf = balanceFactor(root);

    if (bf > 1 || bf < -1) {
        cout << "Node " << root->key
             << " violates AVL property. "
             << "Balance Factor = " << bf << endl;

        isAVL = false;
    }

    // Check left subtree
    bool leftAVL = checkAVL(root->left);

    // Check right subtree
    bool rightAVL = checkAVL(root->right);

    return isAVL && leftAVL && rightAVL;
}

// Main function
int main() {

    // FIRST TREE
    int arr[] = {50,30,70,20,40,60,80,10,5};

    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        root = bstInsert(root, arr[i]);
    }

    cout << "FIRST TREE" << endl;

    cout << "Level Order: ";
    levelOrder(root);

    cout << "\n\nViolating Nodes:" << endl;

    bool result = checkAVL(root);

    if (result) {
        cout << "Final Verdict: AVL" << endl;
    }
    else {
        cout << "Final Verdict: NOT AVL" << endl;
    }

    // SECOND TREE
    Node* root2 = nullptr;

    int arr2[] = {40,20,60,10,30,50,70};

    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    for (int i = 0; i < size2; i++) {
        root2 = bstInsert(root2, arr2[i]);
    }

    cout << "\n\nSECOND TREE" << endl;

    cout << "Level Order: ";
    levelOrder(root2);

    cout << "\n\nViolating Nodes:" << endl;

    bool result2 = checkAVL(root2);

    if (result2) {
        cout << "No violating nodes found." << endl;
        cout << "Final Verdict: AVL" << endl;
    }
    else {
        cout << "Final Verdict: NOT AVL" << endl;
    }

    return 0;
}
