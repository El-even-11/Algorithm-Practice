#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getKthFromEnd(ListNode *head, int k)
{
    int len = 0;
    ListNode *p = head;
    while (p)
    {
        len++;
        p = p->next;
    }
    p = head;
    int cnt = len - k;
    while (cnt--)
    {
        p = p->next;
    }
    return p;
}