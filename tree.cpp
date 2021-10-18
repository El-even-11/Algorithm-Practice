#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int no;        // number
    int val;       // value
    Node *parent;  // pointer to parent
    Node *left;    // pointer to left child
    Node *sibling; // pointer to the first right sibling
    Node(int no, int val, Node *parent = nullptr, Node *left = nullptr, Node *sibling = nullptr)
    {
        this->no = no;
        this->val = val;
        this->parent = parent;
        this->left = left;
        this->sibling = sibling;
    }

    void print()
    {
        cout << "no " << no << ", val" << val << endl;
    }
};

class Tree
{
private:
    Node *root;

    Node *getNode(int i)
    {
        return getNode(root, i);
    }

    Node *getNode(Node *node, int i)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (node->no == i)
        {
            return node;
        }

        Node *ret = getNode(node->left, i);
        if (ret)
        {
            return ret;
        }
        return getNode(node->sibling, i);
    }

public:
    Tree(Node *root)
    {
        this->root = root;
    }

    Node *getParent(int i)
    {
        return getNode(i)->parent;
    }

    vector<Node *> getAllParents(int i)
    {
        vector<Node *> parents;
        Node *node = getParent(i);
        while (node)
        {
            parents.push_back(node);
            node = getParent(node->no);
        }
        return parents;
    }

    vector<Node *> getChildren(int i)
    {
        vector<Node *> children;
        Node *node = getNode(i)->left;
        while (node)
        {
            children.push_back(node);
            node = node->sibling;
        }
        return children;
    }

    vector<Node *> getAllChildren(int i)
    {
        vector<Node *> allChildren;
        Node *node = getNode(i)->left;
        queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            Node *p = q.front();
            q.pop();
            allChildren.push_back(p);

            if (p->sibling)
            {
                q.push(p->sibling);
            }
            if (p->left)
            {
                q.push(p->left);
            }
        }
        return allChildren;
    }
};

int main()
{
    Node *root = new Node(0, 0);
    root->left = new Node(1, 1, root);
    root->left->sibling = new Node(2, 2, root);
    root->left->sibling->sibling = new Node(3, 3, root);
    root->left->left = new Node(4, 4, root->left);
    root->left->sibling->left = new Node(5, 5, root->left->sibling);
    root->left->sibling->left->sibling = new Node(6, 6, root->left->sibling);
    root->left->sibling->sibling->left = new Node(7, 7, root->left->sibling->sibling);
    root->left->sibling->left->left = new Node(8, 8, root->left->sibling->left);

    Tree test(root);

    // get parent
    Node *parent = test.getParent(5);
    // expect : no 2, val 2
    cout << "get parent: " << endl;
    parent->print();
    cout << endl;

    // get all parents
    vector<Node *> parents = test.getAllParents(8);
    // expect : no 5, val 5
    //          no 2, val 2
    //          no 0, val 0
    cout << "get all parents: " << endl;
    for (auto node : parents)
    {
        node->print();
    }
    cout << endl;

    // get children
    vector<Node *> childen = test.getChildren(0);
    // expect : no 1, val 1
    //          no 2, val 2
    //          no 3, val 3
    cout << "get children: " << endl;
    for (auto node : childen)
    {
        node->print();
    }
    cout << endl;

    // get all children
    vector<Node *> allchilden = test.getAllChildren(2);
    // expect : no 5, val 5
    //          no 6, val 6
    //          no 8, val 8
    cout << "get all children: " << endl;
    for (auto node : allchilden)
    {
        node->print();
    }
    cout << endl;

    // get all children
    allchilden = test.getAllChildren(0);
    // expect : no 1, val 1
    //          no 2, val 2
    //          no 3, val 3
    //          no 4, val 4
    //          no 5, val 5
    //          no 6, val 6
    //          no 7, val 7
    //          no 8, val 8
    cout << "get all children: " << endl;
    for (auto node : allchilden)
    {
        node->print();
    }
    cout << endl;
}