#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    vector<ListNode *> ret;
    if (!head)
    {
        for (int i = 0; i < k; i++)
        {
            ret.push_back({});
        }
        return ret;
    }

    int size = 1;
    ListNode *tmp = head;
    while (tmp->next)
    {
        size++;
        tmp = tmp->next;
    }

    int len = size / k;
    int plus = size % k;

    tmp = head;
    for (int i = 0; i < k; i++)
    {
        ret.push_back(tmp);
        if (tmp)
        {
            if (i < plus)
            {
                for (int pos = 0; pos < len; pos++)
                {
                    tmp = tmp->next;
                }
            }
            else
            {
                for (int pos = 0; pos < len - 1; pos++)
                {
                    tmp = tmp->next;
                }
            }
            ListNode *now = tmp;
            tmp = tmp->next;
            now->next = nullptr;
        }
    }

    return ret;
}