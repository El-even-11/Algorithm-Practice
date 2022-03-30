#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
    {
        set<int> available;
        for (int i = 0; i < k; i++)
        {
            available.insert(i);
        }

        vector<int> requests(k);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;

        int n = arrival.size();
        for (int i = 0; i < n; i++)
        {
            while (!busy.empty() && busy.top().first <= arrival[i])
            {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty())
            {
                continue;
            }

            auto p = available.lower_bound(i % k);
            if (p == available.end())
            {
                p = available.begin();
            }

            requests[*p]++;
            busy.push(pair(arrival[i] + load[i], *p));
            available.erase(p);
        }

        int max = -1;
        for (int i = 0; i < k; i++)
        {
            if (requests[i] > max)
            {
                max = requests[i];
            }
        }

        vector<int> ret;

        for (int i = 0; i < k; i++)
        {
            if (requests[i] == max)
            {
                ret.push_back(i);
            }
        }

        return ret;
    }
};