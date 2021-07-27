#include <iostream>
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

int rootvalue;
int ans = -1;

void dfs(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    if (ans != -1 && node->val >= ans)
    {
        return;
    }
    if (node->val > rootvalue)
    {
        ans = node->val;
    }
    dfs(node->left);
    dfs(node->right);
}

int findSecondMinimumValue(TreeNode *root)
{
    rootvalue = root->val;
    dfs(root);
    return ans;
}