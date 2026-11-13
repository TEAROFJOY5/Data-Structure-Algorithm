
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class AVLNode
{
public:
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k)
    {
        key = k;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

int height(AVLNode* n)
{
    return n ? n->height : 0;
}

int getBalance(AVLNode* n)
{
    return n ? height(n->left) - height(n->right) : 0;
}

void updateHeight(AVLNode* n)
{
    n->height = 1 + max(height(n->left), height(n->right));
}

AVLNode* rightRotate(AVLNode* y)
{
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLNode* leftRotate(AVLNode* x)
{
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

AVLNode* insert(AVLNode* node, int key)
{
    if (node == nullptr)
        return new AVLNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);

    else if (key > node->key)
        node->right = insert(node->right, key);

    else
        return node;

    updateHeight(node);

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode* minValueNode(AVLNode* node)
{
    while (node->left != nullptr)
        node = node->left;

    return node;
}

AVLNode* deleteNode(AVLNode* root, int key)
{
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            AVLNode* child = root->left ? root->left : root->right;

            delete root;

            return child;
        }

        AVLNode* succ = minValueNode(root->right);

        root->key = succ->key;

        root->right = deleteNode(root->right, succ->key);
    }

    if (root == nullptr)
        return root;

    updateHeight(root);

    int balance = getBalance(root);

    if (balance > 1)
    {
        int childBalance = getBalance(root->left);

        if (childBalance >= 0)
        {
            cout << "Unbalanced node: " << root->key << endl;
            cout << "Balance factor: " << balance << endl;
            cout << "Heavy child: " << root->left->key << endl;
            cout << "Heavy child balance factor: "
                 << childBalance << endl;
            cout << "Rotation: LL (Single Right Rotation)" << endl;
            cout << endl;

            return rightRotate(root);
        }

        cout << "Unbalanced node: " << root->key << endl;
        cout << "Balance factor: " << balance << endl;
        cout << "Heavy child: " << root->left->key << endl;
        cout << "Heavy child balance factor: "
             << childBalance << endl;
        cout << "Rotation: LR (Left-Right Rotation)" << endl;
        cout << endl;

        root->left = leftRotate(root->left);

        return rightRotate(root);
    }

    if (balance < -1)
    {
        int childBalance = getBalance(root->right);

        if (childBalance <= 0)
        {
            cout << "Unbalanced node: " << root->key << endl;
            cout << "Balance factor: " << balance << endl;
            cout << "Heavy child: " << root->right->key << endl;
            cout << "Heavy child balance factor: "
                 << childBalance << endl;
            cout << "Rotation: RR (Single Left Rotation)" << endl;
            cout << endl;

            return leftRotate(root);
        }

        cout << "Unbalanced node: " << root->key << endl;
        cout << "Balance factor: " << balance << endl;
        cout << "Heavy child: " << root->right->key << endl;
        cout << "Heavy child balance factor: "
             << childBalance << endl;
        cout << "Rotation: RL (Right-Left Rotation)" << endl;
        cout << endl;

        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
}

void levelOrder(AVLNode* root, int size)
{
    if (root == nullptr)
        return;

    AVLNode** arr = new AVLNode*[size];

    int front = 0;
    int rear = 0;

    arr[rear++] = root;

    while (front < rear)
    {
        AVLNode* current = arr[front++];

        cout << current->key << " ";

        if (current->left != nullptr)
            arr[rear++] = current->left;

        if (current->right != nullptr)
            arr[rear++] = current->right;
    }

    delete[] arr;

    cout << endl;
}

int checkAVL(AVLNode* root, long long minVal, long long maxVal)
{
    if (root == nullptr)
        return 0;

    if (root->key <= minVal || root->key >= maxVal)
        return -1;

    int leftHeight = checkAVL(root->left, minVal, root->key);

    if (leftHeight == -1)
        return -1;

    int rightHeight = checkAVL(root->right, root->key, maxVal);

    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return 1 + max(leftHeight, rightHeight);
}

void runChecker(AVLNode* root)
{
    int result = checkAVL(
        root,
        -9223372036854775807LL - 1,
        9223372036854775807LL
    );

    if (result != -1)
        cout << "Task 1 Checker: PASS" << endl;
    else
        cout << "Task 1 Checker: FAIL" << endl;
}

int main()
{
    AVLNode* root = nullptr;

    cout << "========== FIRST TREE ==========\n";

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);

    cout << "\nDeleting key 30:\n\n";

    root = deleteNode(root, 30);

    cout << "Level Order: ";
    levelOrder(root, 4);

    runChecker(root);

    cout << "\n========== SECOND TREE ==========\n";

    AVLNode* root2 = nullptr;

    int keys[] = {8, 5, 11, 3, 6, 10, 12, 2, 4, 7, 9, 1};

    for (int i = 0; i < 12; i++)
        root2 = insert(root2, keys[i]);

    cout << "\nDeleting key 12:\n\n";

    root2 = deleteNode(root2, 12);

    cout << "Final Level Order: ";
    levelOrder(root2, 11);

    runChecker(root2);

    return 0;
}
