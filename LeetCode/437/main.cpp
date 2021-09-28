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

int ans = 0;
unordered_map<int, int> map;
int t;

void dfs(TreeNode *node, int sum)
{
    if (!node)
    {
        return;
    }
    sum += node->val;

    if (map.count(sum - t))
    {
        ans += map[sum - t];
    }
    map[sum]++;
    dfs(node->left, sum);
    dfs(node->right, sum);
    map[sum]--;
}

int pathSum(TreeNode *root, int targetSum)
{
    map[0]++;
    t = targetSum;
    dfs(root, 0);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->left->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(-1);
    root->right = new TreeNode(-3);
    root->right->left = new TreeNode(-2);
    cout << pathSum(root, 3) << endl;

    return 0;
}