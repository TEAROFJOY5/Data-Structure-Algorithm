
#include<iostream>
#include<algorithm>
using namespace std;

struct tree {
    int data;
    tree* left;
    tree* right;

    tree(int val) : data(val), left(NULL), right(NULL) {}
};

class AVL {
public:
    tree* newTree;
    int height;

    AVL(int key) {
        newTree = new tree(key);
        height = 1;
    }
};

int heightOf(tree* n) {
    if (n == NULL)
        return 0;

    return 1;
}

int getBalance(AVL* n) {
    return n ? heightOf(n->newTree->left) -
               heightOf(n->newTree->right) : 0;
}

void updateHeight(AVL* n) {
    n->height = 1 + max(heightOf(n->newTree->left),
                        heightOf(n->newTree->right));
}

// Right Rotation
AVL* rightRotate(AVL* y) {

    tree* x = y->newTree->left;
    tree* T2 = x->right;

    x->right = y->newTree;
    y->newTree->left = T2;

    y->newTree = x;

    updateHeight(y);

    return y;
}
// Left Rotate
AVL* leftRotate(AVL* x) {

    tree* y = x->newTree->right;
    tree* T2 = y->left;

    y->left = x->newTree;
    x->newTree->right = T2;

    x->newTree = y;

    updateHeight(x);

    return x;
}

int main() {

    AVL* n = new AVL(30);

    cout << "Root: " << n->newTree->data << endl;
    cout << "Height: " << n->height << endl;

    delete n->newTree;
    delete n;

    return 0;
}
