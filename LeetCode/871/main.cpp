#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
	{
		stations.push_back(vector<int>{target, 0});
		int n = stations.size();
		priority_queue<int> fuels;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			while (startFuel < stations[i][0])
			{
				if (fuels.empty())
				{
					return -1;
				}
				startFuel += fuels.top();
				fuels.pop();
				ans++;
			}
			fuels.push(stations[i][1]);
		}

		return ans;
	}
};