#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

priority_queue<int, vector<int>, greater<int>> q;

void inOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    q.push(root->val);

    inOrder(root->left);
    inOrder(root->right);
}

int findSecondMinimumValue(TreeNode *root)
{
    inOrder(root);
    int min = q.top();
    while (!q.empty() && q.top() == min)
    {
        q.pop();
    }

    if (q.empty())
    {
        return -1;
    }

    return q.top();
}