#include <unordered_map>
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

class Solution
{
public:
    int sum;
    unordered_map<int, int> targets;
    bool dfs(TreeNode *root)
    {
        if (!root)
        {
            cout << "false ";
            return false;
        }
        int val = root->val;
        if (targets[val])
        {
            cout << "true ";
            return true;
        }
        targets[sum - val] = 1;
        bool ret = dfs(root->left) || dfs(root->right);
        cout << (ret ? "true " : "false ");
        return ret;
    }

    bool findTarget(TreeNode *root, int k)
    {
        sum = k;
        return dfs(root);
    }
};