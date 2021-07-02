#include <vector>
#include <algorithm>
using namespace std;

int maxIceCream(vector<int> &costs, int coins)
{
    sort(costs.begin(), costs.end());
    int cnt = 0;
    while (coins > 0)
    {
        coins -= costs[cnt];
        if (coins >= 0)
        {
            cnt++;
        }

        if (cnt == costs.size())
        {
            break;
        }
    }

    return cnt;
}