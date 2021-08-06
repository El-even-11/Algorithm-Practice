#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{

    if (!head || !head->next)
    {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != slow)
    {
        if (!fast->next || !fast->next->next)
        {
            return false;
        }

        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}