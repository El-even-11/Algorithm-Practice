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

    vector<int> postorder(Node *root)
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
        for (auto child : root->children)
        {
            dfs(child);
        }
        ret.push_back(root->val);
    }
};