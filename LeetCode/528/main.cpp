#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Solution
{
private:
    int sum[10010] = {0};
    int n;

public:
    Solution(vector<int> &w)
    {
        n = w.size();
        for (int i = 1; i <= w.size(); i++)
        {
            sum[i] = sum[i - 1] + w[i - 1];
        }
    }

    int pickIndex()
    {
        int random = rand() % sum[n];
        int l = 0;
        int r = n - 1;
        int index = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (random >= sum[mid])
            {
                index = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return index;
    }
};