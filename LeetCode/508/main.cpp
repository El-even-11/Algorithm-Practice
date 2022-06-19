#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
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
    unordered_map<int, int> m;
    int _max = 0x80000000;

    int dfs(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            m[root->val]++;
            _max = max(_max, m[root->val]);
            return root->val;
        }

        int sum = root->val;
        if (root->left)
        {
            sum += dfs(root->left);
        }

        if (root->right)
        {
            sum += dfs(root->right);
        }

        m[sum]++;
        _max = max(_max, m[sum]);
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        dfs(root);
        vector<int> res;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second == _max)
            {
                res.push_back(it->first);
            }
        }

        return res;
    }
};