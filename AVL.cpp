
#include <iostream>
using namespace std;

// Structure of an AVL Tree node
struct Node
{
    int data;
    int height;
    Node* left;
    Node* right;
};

// Get maximum of two integers
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

// Get height of a node
int getHeight(Node* node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

// Calculate balance factor
int getBalance(Node* node)
{
    if (node == NULL)
        return 0;

    return getHeight(node->left) -
           getHeight(node->right);
}

// Create a new node
Node* createNode(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Right Rotation
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(
        getHeight(y->left),
        getHeight(y->right)
    );

    x->height = 1 + max(
        getHeight(x->left),
        getHeight(x->right)
    );

    return x;
}

// Left Rotation
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(
        getHeight(x->left),
        getHeight(x->right)
    );

    y->height = 1 + max(
        getHeight(y->left),
        getHeight(y->right)
    );

    return y;
}

// Insert a node into AVL tree
Node* insert(Node* root, int value)
{
    // Normal BST insertion
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    else
        return root;

    // Update height
    root->height = 1 + max(
        getHeight(root->left),
        getHeight(root->right)
    );

    // Calculate balance factor
    int balance = getBalance(root);

    // Case 1: Left Left (LL)
    if (balance > 1 &&
        value < root->left->data)
    {
        return rightRotate(root);
    }

    // Case 2: Right Right (RR)
    if (balance < -1 &&
        value > root->right->data)
    {
        return leftRotate(root);
    }

    // Case 3: Left Right (LR)
    if (balance > 1 &&
        value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Case 4: Right Left (RL)
    if (balance < -1 &&
        value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Find the node with minimum value
Node* findMin(Node* root)
{
    Node* current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete a node from AVL tree
Node* deleteNode(Node* root, int value)
{
    // Normal BST deletion
    if (root == NULL)
        return root;

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }

    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }

    else
    {
        // Node has no child or one child
        if (root->left == NULL ||
            root->right == NULL)
        {
            Node* temp;

            if (root->left != NULL)
                temp = root->left;
            else
                temp = root->right;

            // No child
            if (temp == NULL)
            {
                delete root;
                return NULL;
            }

            // One child
            else
            {
                Node* oldRoot = root;
                root = temp;
                delete oldRoot;
            }
        }

        // Node has two children
        else
        {
            Node* temp = findMin(root->right);

            // Copy inorder successor's value
            root->data = temp->data;

            // Delete inorder successor
            root->right = deleteNode(
                root->right,
                temp->data
            );
        }
    }

    // If tree became empty
    if (root == NULL)
        return root;

    // Update height
    root->height = 1 + max(
        getHeight(root->left),
        getHeight(root->right)
    );

    // Calculate balance factor
    int balance = getBalance(root);

    // Case 1: Left Left
    if (balance > 1 &&
        getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    // Case 2: Left Right
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Case 3: Right Right
    if (balance < -1 &&
        getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    // Case 4: Right Left
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Display tree structure
void displayTree(Node* root, int space = 0)
{
    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->data << endl;

    displayTree(root->left, space);
}

// Check whether the tree fulfills AVL property
bool isAVL(Node* root)
{
    if (root == NULL)
        return true;

    int balance = getBalance(root);

    if (balance < -1 || balance > 1)
        return false;

    return isAVL(root->left) &&
           isAVL(root->right);
}

// Free allocated memory
void destroyTree(Node* root)
{
    if (root == NULL)
        return;

    destroyTree(root->left);
    destroyTree(root->right);

    delete root;
}

// Main function
int main()
{
    Node* root = NULL;

    int values[] = {10, 20, 30, 40, 50, 25};

    int n = 6;

    cout << "INSERTING NODES INTO AVL TREE\n";

    for (int i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
    }

    cout << "\nInorder Traversal:\n";
    inorder(root);

    cout << "\n\nAVL Tree Structure:\n";
    displayTree(root);

    cout << "\nAVL Verification: ";

    if (isAVL(root))
        cout << "Tree is AVL Balanced";
    else
        cout << "Tree is NOT AVL Balanced";

    // Deletion
    int value;

    cout << "\n\nEnter value to delete: ";
    cin >> value;

    root = deleteNode(root, value);

    cout << "\nTree After Deletion:\n";

    displayTree(root);

    cout << "\nInorder Traversal After Deletion:\n";
    inorder(root);

    cout << "\n\nAVL Verification After Deletion: ";

    if (isAVL(root))
        cout << "Tree is AVL Balanced";
    else
        cout << "Tree is NOT AVL Balanced";

    cout << endl;

    destroyTree(root);

    return 0;
}
