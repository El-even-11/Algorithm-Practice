#include <algorithm>
using namespace std;

class Solution
{
public:
    int getStep(int cur, long n)
    {
        int step = 0;
        long first = cur;
        long last = cur;
        while (first <= n)
        {
            step += min(last, n) - first + 1;
            first *= 10;
            last = last * 10 + 9;
        }

        return step;
    }

    int findKthNumber(int n, int k)
    {
        int cur = 1;
        k--;
        while (k > 0)
        {
            int step = getStep(cur, n);
            if (step <= k)
            {
                k -= step;
                cur++;
            }
            else
            {
                k--;
                cur *= 10;
            }
        }

        return cur;
    }
};