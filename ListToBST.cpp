#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

ListNode* curr = nullptr;

TreeNode* treeify(int i, int j)
{
    if(j < i)
        return nullptr;

    int mid = (i + j) / 2;

    TreeNode* node = new TreeNode();

    node->left = treeify(i, mid - 1);

    node->val = curr->val;
    curr = curr->next;

    node->right = treeify(mid + 1, j);

    return node;
}

TreeNode* sortedListToBST(ListNode* head)
{
    int count = 0;

    curr = head;

    while(curr)
    {
        curr = curr->next;
        count++;
    }

    curr = head;

    return treeify(1, count);
}
