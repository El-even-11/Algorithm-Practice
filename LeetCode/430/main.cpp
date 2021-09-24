#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

vector<Node *> nodes;

void dfs(Node *p)
{
    if (!p)
    {
        return;
    }

    nodes.push_back(p);

    dfs(p->child);
    dfs(p->next);
}

Node *flatten(Node *head)
{
    if (!head)
    {
        return head;
    }

    dfs(head);

    for (int i = 0; i < nodes.size(); i++)
    {
        nodes[i]->child = nullptr;
    }
    nodes[0]->next = nodes[1];
    for (int i = 1; i < nodes.size() - 1; i++)
    {
        nodes[i]->next = nodes[i + 1];
        nodes[i]->prev = nodes[i - 1];
    }
    nodes[nodes.size() - 1]->prev = nodes[nodes.size() - 2];
    return nodes[0];
}