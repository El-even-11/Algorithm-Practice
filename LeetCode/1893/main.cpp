#include <vector>
using namespace std;

bool covered(vector<vector<int>> &ranges, int i)
{
    for (vector<int> range : ranges)
    {
        if (i >= range[0] && i <= range[1])
        {
            return true;
        }
    }

    return false;
}

bool isCovered(vector<vector<int>> &ranges, int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        if (!covered(ranges, i))
        {
            return false;
        }
    }

    return true;
}