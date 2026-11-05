#include <iostream>
#include <algorithm>
using namespace std;
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return root->height;
}

int balanceFactor(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return height(root->left) - height(root->right);
}

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

Node* rightRotate(Node* y) {

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left),
                        height(y->right));

    x->height = 1 + max(height(x->left),
                        height(x->right));

    return x;
}

Node* leftRotate(Node* x) {

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left),
                        height(x->right));

    y->height = 1 + max(height(y->left),
                        height(y->right));

    return y;
}

Node* avlInsert(Node* root, int key) {

    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = avlInsert(root->left, key);
    }
    else if (key > root->key) {
        root->right = avlInsert(root->right, key);
    }
    else {
        return root;
    }

    // Update height
    root->height = 1 + max(height(root->left),
                           height(root->right));

    int bf = balanceFactor(root);

    // LL Case
    if (bf > 1 && key < root->left->key) {
        return rightRotate(root);
    }

    // RR Case
    if (bf < -1 && key > root->right->key) {
        return leftRotate(root);
    }

    // LR Case
    if (bf > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (bf < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool search(Node* root, int key, int &count) {

    if (root == nullptr) {
        return false;
    }

    // Count each visited node
    count++;

    if (root->key == key) {
        return true;
    }

    if (key < root->key) {
        return search(root->left, key, count);
    }
    else {
        return search(root->right, key, count);
    }
}


void levelOrder(Node* root) {

    if (root == nullptr) {
        return;
    }

    Node* queue[100];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {

        Node* current = queue[front++];

        cout << current->key << " ";

        if (current->left != nullptr) {
            queue[rear++] = current->left;
        }

        if (current->right != nullptr) {
            queue[rear++] = current->right;
        }
    }
}

int main() {

    Node* bstRoot = nullptr;
    Node* avlRoot = nullptr;

    cout << "HEIGHT RACE\n";

    for (int i = 1; i <= 31; i++) {

        bstRoot = bstInsert(bstRoot, i);

        avlRoot = avlInsert(avlRoot, i);

        if (i % 5 == 0) {

            cout << "\nAfter " << i << " insertions:\n";

            cout << "Plain BST Height: "
                 << height(bstRoot) << endl;

            cout << "AVL Tree Height: "
                 << height(avlRoot) << endl;
        }
    }

    cout << "Plain BST Height: "
         << height(bstRoot) << endl;

    cout << "AVL Tree Height: "
         << height(avlRoot) << endl;

    int bstCount = 0;
    int avlCount = 0;
    bool bstFound = search(bstRoot, 31, bstCount);
    bool avlFound = search(avlRoot, 31, avlCount);

    cout << "Searching for key 31:\n";

    cout << "Plain BST: ";

    if (bstFound) {
        cout << "Found";
    }
    else {
        cout << "Not Found";
    }

    cout << "\nNodes visited: " << bstCount << endl;

    cout << "\nAVL Tree: ";

    if (avlFound) {
        cout << "Found";
    }
    else {
        cout << "Not Found";
    }

    cout << "\nNodes visited: " << avlCount << endl;
    cout << "\n========== TREE TRAVERSAL ==========\n";
    cout << "Plain BST Level Order:\n";
    levelOrder(bstRoot);
    cout << "\n\nAVL Tree Level Order:\n";
    levelOrder(avlRoot);
    cout << endl;
    return 0;
}
