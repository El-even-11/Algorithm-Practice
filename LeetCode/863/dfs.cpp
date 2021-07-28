#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<int, TreeNode *> fa;
vector<int> ret;

void getFa(TreeNode *node)
{
    if (!node)
    {
        return;
    }

    if (node->left)
    {
        fa[node->left->val] = node;
    }

    if (node->right)
    {
        fa[node->right->val] = node;
    }

    getFa(node->left);
    getFa(node->right);
}

void dfs(TreeNode *node, int pos, int k, TreeNode *from)
{
    if (!node)
    {
        return;
    }

    if (pos == k)
    {
        ret.push_back(node->val);
        return;
    }

    if (fa[node->val] != from)
    {
        dfs(fa[node->val], pos + 1, k, node);
    }

    if (node->left != from)
    {
        dfs(node->left, pos + 1, k, node);
    }

    if (node->right != from)
    {
        dfs(node->right, pos + 1, k, node);
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    getFa(root);

    dfs(target, 0, k, NULL);

    return ret;
}

int main()
{
    TreeNode *root = new TreeNode(0);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->left->right = new TreeNode(3);
    root->right->left->right->right = new TreeNode(4);

    vector<int> ret = distanceK(root, root->right->left, 2);

    for (int i : ret)
    {
        cout << i << " ";
    }

    return 0;
}