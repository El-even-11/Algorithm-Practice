#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> ret;

        int x = arr.size();

        while (x > 0)
        {
            int ix = 0;
            for (int i = 0; i < x; i++)
            {
                if (arr[i] == x)
                {
                    ix = i;
                    break;
                }
            }
            if (ix + 1 == x)
            {
                x--;
                continue;
            }
            if (ix + 1 > 1)
            {
                ret.push_back(ix + 1);
                reverse(arr, ix + 1);
            }
            if (x > 1)
            {
                ret.push_back(x);
                reverse(arr, x);
            }

            x--;
        }

        return ret;
    }

    void reverse(vector<int> &arr, int k)
    {
        for (int i = 0; i < k / 2; i++)
        {
            int t = arr[i];
            arr[i] = arr[k - i - 1];
            arr[k - i - 1] = t;
        }
    }
};