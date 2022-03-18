#include <string>
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
    string ret;

    void dfs(TreeNode *root)
    {
        ret.push_back('(');
        ret.append(to_string(root->val));
        if (!root->left && !root->right)
        {
            ret.push_back(')');
            return;
        }
        if (!root->left)
        {
            ret.append("()");
            dfs(root->right);
            ret.push_back(')');
            return;
        }
        if (!root->right)
        {
            dfs(root->left);
            ret.push_back(')');
            return;
        }

        dfs(root->left);
        dfs(root->right);
        ret.push_back(')');
    }

    string tree2str(TreeNode *root)
    {
        dfs(root);
        return ret.substr(1, ret.size() - 2);
    }
};