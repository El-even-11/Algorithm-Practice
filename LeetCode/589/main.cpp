#include <vector>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> ret;

    vector<int> preorder(Node *root)
    {
        dfs(root);
        return ret;
    }

    void dfs(Node *root)
    {
        if (!root)
        {
            return;
        }

        ret.push_back(root->val);

        for (auto node : root->children)
        {
            dfs(node);
        }
    }
};