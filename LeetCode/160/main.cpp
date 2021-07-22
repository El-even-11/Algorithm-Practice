#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    ListNode *p = headA;
    ListNode *q = headB;

    while (p != q)
    {
        p = p == NULL ? headB : p->next;
        q = q == NULL ? headA : q->next;
    }

    return p;
}