#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int nthUglyNumber(int n)
{
    long factors[3] = {2L, 3L, 5L};
    priority_queue<long, vector<long>, greater<long>> q;
    unordered_set<long> set;
    q.push(1L);
    set.insert(1L);

    long ret = 0;

    for (int i = 0; i < n; i++)
    {
        ret = q.top();
        q.pop();
        for (int x : factors)
        {
            if (!set.count(ret * x))
            {
                q.push(ret * x);
                set.insert(ret * x);
            }
        }
    }

    return ret;
}