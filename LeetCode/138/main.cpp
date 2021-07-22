#include <map>
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *ret = new Node(head->val);

    Node *p = head->next;
    Node *q = ret;

    map<Node *, Node *> m;

    m[head] = ret;

    for (; p != NULL; p = p->next, q = q->next)
    {
        q->next = new Node(p->val);
        m[p] = q->next;
    }

    p = head;
    q = ret;

    for (; p != NULL; p = p->next, q = q->next)
    {
        q->random = m[p->random];
    }

    return ret;
}
