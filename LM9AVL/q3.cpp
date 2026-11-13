
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class BSTNode
{
public:
    int key;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

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

BSTNode* BSTinsert(BSTNode* root, int key)
{
    if (root == nullptr)
        return new BSTNode(key);

    if (key < root->key)
        root->left = BSTinsert(root->left, key);

    else if (key > root->key)
        root->right = BSTinsert(root->right, key);

    return root;
}

int countNodes(BSTNode* root)
{
    if (root == nullptr)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

void inorder(BSTNode* root, int arr[], int& index)
{
    if (root == nullptr)
        return;

    inorder(root->left, arr, index);
    arr[index++] = root->key;
    inorder(root->right, arr, index);
}

BSTNode* buildBalancedBST(int arr[], int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;

    BSTNode* root = new BSTNode(arr[mid]);

    root->left = buildBalancedBST(arr, start, mid - 1);
    root->right = buildBalancedBST(arr, mid + 1, end);

    return root;
}

BSTNode* rebuildBST(BSTNode* root)
{
    int size = countNodes(root);

    int* arr = new int[size];

    int index = 0;

    inorder(root, arr, index);

    BSTNode* newRoot = buildBalancedBST(arr, 0, size - 1);

    delete[] arr;

    return newRoot;
}

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

void levelOrderBST(BSTNode* root, int size)
{
    if (root == nullptr)
        return;

    BSTNode** arr = new BSTNode*[size];

    int front = 0;
    int rear = 0;

    arr[rear++] = root;

    while (front < rear)
    {
        BSTNode* current = arr[front++];

        cout << current->key << " ";

        if (current->left != nullptr)
            arr[rear++] = current->left;

        if (current->right != nullptr)
            arr[rear++] = current->right;
    }

    delete[] arr;

    cout << endl;
}

void levelOrderAVL(AVLNode* root, int size)
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

int checkBST(BSTNode* root, long long minVal, long long maxVal)
{
    if (root == nullptr)
        return 0;

    if (root->key <= minVal || root->key >= maxVal)
        return -1;

    int leftHeight = checkBST(root->left, minVal, root->key);

    if (leftHeight == -1)
        return -1;

    int rightHeight = checkBST(root->right, root->key, maxVal);

    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return 1 + max(leftHeight, rightHeight);
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

void runExperiment(int start, int end)
{
    BSTNode* bstRoot = nullptr;
    AVLNode* avlRoot = nullptr;

    int size = end - start + 1;

    cout << "\n================================\n";
    cout << "Testing keys " << start << " to " << end;
    cout << "\n================================\n";

    for (int i = start; i <= end; i++)
    {
        bstRoot = BSTinsert(bstRoot, i);
        avlRoot = insert(avlRoot, i);
    }

    bstRoot = rebuildBST(bstRoot);

    cout << "\nRebuilt BST Level Order: ";
    levelOrderBST(bstRoot, size);

    cout << "AVL Level Order: ";
    levelOrderAVL(avlRoot, size);

    int bstCheck = checkBST(
        bstRoot,
        -9223372036854775807LL - 1,
        9223372036854775807LL
    );

    int avlCheck = checkAVL(
        avlRoot,
        -9223372036854775807LL - 1,
        9223372036854775807LL
    );

    cout << "\nRebuilt BST Checker: ";

    if (bstCheck != -1)
        cout << "PASS";
    else
        cout << "FAIL";

    cout << "\nAVL Checker: ";

    if (avlCheck != -1)
        cout << "PASS";
    else
        cout << "FAIL";

    cout << endl;
}

int main()
{
    runExperiment(10, 70);

    runExperiment(1, 15);

    runExperiment(1, 20);

    return 0;
}
