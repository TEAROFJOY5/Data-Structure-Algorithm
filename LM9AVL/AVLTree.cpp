#include <iostream>
#include <algorithm>

using namespace std;

class AVLNode
{
public:
    int key;
    int height; // height of the subtree rooted at this node
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k)
    {
        key = k;
        height = 1; // a new node is a leaf
        left = nullptr;
        right = nullptr;
    }
};

// height of a subtree (height of an empty tree is 0)
int height(AVLNode* n)
{
    return n ? n->height : 0;
}

// balance factor = height(left) - height(right)
// positive => left-heavy, negative => right-heavy
int getBalance(AVLNode* n)
{
    return n ? height(n->left) - height(n->right) : 0;
}

void updateHeight(AVLNode* n)
{
    n->height = 1 + max(height(n->left), height(n->right));
}

// Lab Manual 09

// function to perform a right rotation on a subtree
AVLNode* rightRotate(AVLNode* y)
{
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights (y is now lower, so update it first)
    updateHeight(y);
    updateHeight(x);

    // Return new root
    return x;
}
// function to perform a left rotation on a subtree
AVLNode* leftRotate(AVLNode* x)
{
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights (x is now lower, so update it first)
    updateHeight(x);
    updateHeight(y);

    // Return new root
    return y;
}

AVLNode* insert(AVLNode* node, int key)
{
    // Perform the normal BST insertion
    if (node == nullptr)
        return new AVLNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        // Equal keys are not allowed in BST
        return node;

    // Update height of this ancestor node
    updateHeight(node);

    // Get the balance factor of this ancestor node
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
    {
        cout << " [LL case at " << node->key << ": right rotation]\n";
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key)
    {
        cout << " [RR case at " << node->key << ": left rotation]\n";
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        cout << " [LR case at " << node->key
             << ": left rotation on " << node->left->key
             << ", then right rotation]\n";

        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        cout << " [RL case at " << node->key
             << ": right rotation on " << node->right->key
             << ", then left rotation]\n";

        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}
// Smallest key in a subtree (leftmost node)
AVLNode* minValueNode(AVLNode* node)
{
    while (node->left != nullptr)
        node = node->left;

    return node;
}

// Recursive function to delete a node with given key from subtree
// with given root. It returns root of the modified subtree.
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
        // Node with zero or one child
        if (root->left == nullptr || root->right == nullptr)
        {
            AVLNode* child = root->left ? root->left : root->right;

            delete root;
            return child; // may be nullptr (leaf case)
        }

        // Node with two children: copy the inorder successor,
        // then delete the successor from the right subtree
        AVLNode* succ = minValueNode(root->right);

        root->key = succ->key;
        root->right = deleteNode(root->right, succ->key);
    }

    updateHeight(root);

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        cout << " [LL case at " << root->key << ": right rotation]\n";
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        cout << " [LR case at " << root->key << ": double rotation]\n";

        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        cout << " [RR case at " << root->key << ": left rotation]\n";
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        cout << " [RL case at " << root->key << ": double rotation]\n";

        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool AVLsearch(AVLNode* root, int key)
{
    // If root is NULL
    if (root == nullptr)
        return false;

    // If found, return true
    else if (root->key == key)
        return true;

    // Recur to the left subtree if
    // the current node's value is greater than key
    else if (root->key > key)
    {
        bool val = AVLsearch(root->left, key);
        return val;
    }

    // Otherwise, recur to the right subtree
    else
    {
        bool val = AVLsearch(root->right, key);
        return val;
    }
}

int main()
{
    
    return 0;
}
