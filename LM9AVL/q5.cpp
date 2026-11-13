
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

class Rotation
{
public:
    int node;
    int balance;
    int child;
    int childBalance;
    char type[3];
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

AVLNode* buildBalanced(int arr[], int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;

    AVLNode* root = new AVLNode(arr[mid]);

    root->left = buildBalanced(arr, start, mid - 1);
    root->right = buildBalanced(arr, mid + 1, end);

    updateHeight(root);

    return root;
}

AVLNode* copyTree(AVLNode* root)
{
    if (root == nullptr)
        return nullptr;

    AVLNode* newNode = new AVLNode(root->key);

    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    newNode->height = root->height;

    return newNode;
}

AVLNode* minValueNode(AVLNode* node)
{
    while (node->left != nullptr)
        node = node->left;

    return node;
}

void addRotation(
    Rotation events[],
    int& count,
    AVLNode* root,
    int balance,
    AVLNode* child,
    int childBalance,
    const char* type
)
{
    events[count].node = root->key;
    events[count].balance = balance;
    events[count].child = child->key;
    events[count].childBalance = childBalance;

    events[count].type[0] = type[0];
    events[count].type[1] = type[1];
    events[count].type[2] = '\0';

    count++;
}

AVLNode* deleteNode(
    AVLNode* root,
    int key,
    Rotation events[],
    int& count
)
{
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key, events, count);

    else if (key > root->key)
        root->right = deleteNode(root->right, key, events, count);

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

        root->right = deleteNode(
            root->right, succ->key, events, count
        );
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
            addRotation(
                events, count, root, balance,
                root->left, childBalance, "LL"
            );

            return rightRotate(root);
        }

        addRotation(
            events, count, root, balance,
            root->left, childBalance, "LR"
        );

        root->left = leftRotate(root->left);

        return rightRotate(root);
    }

    if (balance < -1)
    {
        int childBalance = getBalance(root->right);

        if (childBalance <= 0)
        {
            addRotation(
                events, count, root, balance,
                root->right, childBalance, "RR"
            );

            return leftRotate(root);
        }

        addRotation(
            events, count, root, balance,
            root->right, childBalance, "RL"
        );

        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
}

void printLog(Rotation events[], int count)
{
    if (count == 0)
    {
        cout << "No rotation occurred." << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << "Unbalanced node: "
             << events[i].node << endl;

        cout << "Balance factor: "
             << events[i].balance << endl;

        cout << "Heavy child: "
             << events[i].child << endl;

        cout << "Heavy child balance factor: "
             << events[i].childBalance << endl;

        if (events[i].type[0] == 'L' &&
            events[i].type[1] == 'L')
            cout << "Rotation: LL (Right Rotation)" << endl;

        else if (events[i].type[0] == 'R' &&
                 events[i].type[1] == 'R')
            cout << "Rotation: RR (Left Rotation)" << endl;

        else if (events[i].type[0] == 'L')
            cout << "Rotation: LR (Left-Right Rotation)" << endl;

        else
            cout << "Rotation: RL (Right-Left Rotation)" << endl;

        cout << endl;
    }
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

    int leftHeight = checkAVL(
        root->left, minVal, root->key
    );

    if (leftHeight == -1)
        return -1;

    int rightHeight = checkAVL(
        root->right, root->key, maxVal
    );

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

bool used[16];
int sequence[3];
int answer[3];
bool found = false;

int order[15] = {
    1, 3, 2, 4, 5,
    6, 7, 8, 9, 10,
    11, 12, 13, 14, 15
};

bool searchSequence(
    AVLNode* root,
    int depth,
    int targetDepth
)
{
    for (int i = 0; i < 15; i++)
    {
        int key = order[i];

        if (used[key])
            continue;

        AVLNode* temp = copyTree(root);

        Rotation events[30];
        int count = 0;

        temp = deleteNode(temp, key, events, count);

        sequence[depth] = key;

        used[key] = true;

        if (count > 0)
        {
            if (depth == targetDepth - 1)
            {
                for (int j = 0; j < targetDepth; j++)
                    answer[j] = sequence[j];

                found = true;

                return true;
            }
        }
        else if (depth < targetDepth - 1)
        {
            if (searchSequence(temp, depth + 1, targetDepth))
                return true;
        }

        used[key] = false;
    }

    return false;
}

int main()
{
    int arr[15];

    for (int i = 0; i < 15; i++)
        arr[i] = i + 1;

    AVLNode* root = buildBalanced(arr, 0, 14);

    cout << "========== INITIAL TREE ==========\n";

    cout << "Level Order: ";
    levelOrder(root, 15);

    cout << "\n========== SEARCHING MINIMUM DELETIONS ==========\n";

    for (int depth = 1; depth <= 3; depth++)
    {
        found = false;

        for (int i = 0; i < 16; i++)
            used[i] = false;

        if (searchSequence(root, 0, depth))
        {
            cout << "Minimum deletions required: "
                 << depth << endl;

            cout << "Deletion sequence: ";

            for (int i = 0; i < depth; i++)
                cout << answer[i] << " ";

            cout << endl;

            AVLNode* temp = copyTree(root);

            for (int i = 0; i < depth; i++)
            {
                Rotation events[30];
                int count = 0;

                temp = deleteNode(
                    temp, answer[i], events, count
                );

                if (count > 0)
                {
                    cout << "\nRotation after deleting "
                         << answer[i] << ":\n";

                    printLog(events, count);
                }
            }

            cout << "Final Level Order: ";
            levelOrder(temp, 15);

            runChecker(temp);

            break;
        }
    }

    cout << "\n========== MIRROR SEQUENCE ==========\n";

    AVLNode* mirror = copyTree(root);

    int mirrorKeys[] = {9, 11, 10};

    for (int i = 0; i < 3; i++)
    {
        Rotation events[30];
        int count = 0;

        mirror = deleteNode(
            mirror, mirrorKeys[i], events, count
        );

        if (count > 0)
        {
            cout << "\nRotation after deleting "
                 << mirrorKeys[i] << ":\n";

            printLog(events, count);
        }
    }

    cout << "Final Level Order: ";
    levelOrder(mirror, 15);

    runChecker(mirror);

    cout << "\n========== TWO-LEVEL ROTATION SEARCH ==========\n";

    bool twoLevelFound = false;

    for (int i = 1; i <= 15; i++)
    {
        AVLNode* temp = copyTree(root);

        Rotation events[30];
        int count = 0;

        temp = deleteNode(temp, i, events, count);

        if (count >= 2)
        {
            cout << "Deleting " << i
                 << " causes two-level rotations.\n";

            printLog(events, count);

            twoLevelFound = true;
            break;
        }
    }

    if (!twoLevelFound)
        cout << "No two-level rotation found in 1..15 tree."
             << endl;

    cout << "\n========== TASK 4 TREE ==========\n";

    AVLNode* root2 = nullptr;

    int keys[] = {
        8, 5, 11, 3, 6, 10,
        12, 2, 4, 7, 9, 1
    };

    for (int i = 0; i < 12; i++)
        root2 = insert(root2, keys[i]);

    cout << "Initial Level Order: ";
    levelOrder(root2, 12);

    Rotation events[30];
    int count = 0;

    cout << "\nDeleting 12:\n\n";

    root2 = deleteNode(root2, 12, events, count);

    printLog(events, count);

    cout << "Final Level Order: ";
    levelOrder(root2, 11);

    runChecker(root2);

    return 0;
}
