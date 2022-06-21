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
    int maxDepth = 0;
    int res;

    int findBottomLeftValue(TreeNode *root)
    {
        dfs(root, 1);
        return res;
    }

    void dfs(TreeNode *root, int depth)
    {
        if (!root)
        {
            return;
        }

        if (depth > maxDepth)
        {
            maxDepth = depth;
            res = root->val;
        }

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};