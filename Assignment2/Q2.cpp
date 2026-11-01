
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class BST
{
    Node* root;

    Node* insert(Node* root, int key)
    {
        if(root == nullptr)
        {
            Node* temp = new Node;
            temp->data = key;
            temp->left = nullptr;
            temp->right = nullptr;
            return temp;
        }

        if(key < root->data)
            root->left = insert(root->left, key);
        else if(key > root->data)
            root->right = insert(root->right, key);

        return root;
    }

    bool search(Node* root, int key)
    {
        if(root == nullptr)
            return false;

        if(root->data == key)
            return true;

        if(key < root->data)
            return search(root->left, key);

        return search(root->right, key);
    }

    Node* findMin(Node* root)
    {
        if(root == nullptr)
            return nullptr;

        while(root->left != nullptr)
            root = root->left;

        return root;
    }

    Node* findMax(Node* root)
    {
        if(root == nullptr)
            return nullptr;

        while(root->right != nullptr)
            root = root->right;

        return root;
    }

    Node* deleteNode(Node* root, int key)
    {
        if(root == nullptr)
            return nullptr;

        if(key < root->data)
            root->left = deleteNode(root->left, key);

        else if(key > root->data)
            root->right = deleteNode(root->right, key);

        else
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }

            else if(root->left == nullptr)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }

            else if(root->right == nullptr)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            else
            {
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        return root;
    }

    int height(Node* root)
    {
        if(root == nullptr)
            return -1;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(leftHeight > rightHeight)
            return leftHeight + 1;

        return rightHeight + 1;
    }

    Node* inorderSuccessor(Node* root, int key)
    {
        Node* curr = root;
        Node* successor = nullptr;

        while(curr != nullptr)
        {
            if(key < curr->data)
            {
                successor = curr;
                curr = curr->left;
            }
            else if(key > curr->data)
                curr = curr->right;
            else
                break;
        }

        if(curr == nullptr)
            return nullptr;

        if(curr->right != nullptr)
            return findMin(curr->right);

        return successor;
    }

    void inorder(Node* root)
    {
        if(root == nullptr)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

public:

    BST()
    {
        root = nullptr;
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

    bool search(int key)
    {
        return search(root, key);
    }

    void deleteKey(int key)
    {
        root = deleteNode(root, key);
    }

    int findMin()
    {
        Node* temp = findMin(root);

        if(temp == nullptr)
            return -1;

        return temp->data;
    }

    int findMax()
    {
        Node* temp = findMax(root);

        if(temp == nullptr)
            return -1;

        return temp->data;
    }

    int height()
    {
        return height(root);
    }

    int inorderSuccessor(int key)
    {
        Node* temp = inorderSuccessor(root, key);

        if(temp == nullptr)
            return -1;

        return temp->data;
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Inorder: ";
    tree.display();

    cout << "Search 30: " << tree.search(30) << endl;

    cout << "Minimum: " << tree.findMin() << endl;
    cout << "Maximum: " << tree.findMax() << endl;
    cout << "Height: " << tree.height() << endl;

    cout << "Successor of 20: " << tree.inorderSuccessor(20) << endl;

    tree.deleteKey(30);

    cout << "After deleting 30: ";
    tree.display();

    return 0;
}
