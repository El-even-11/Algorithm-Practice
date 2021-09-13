#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int numberOfBoomerangs(vector<vector<int>> &points)
{
    int n = points.size();
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> map;
        for (int j = 0; j < n; j++)
        {
            int len = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
            map[len]++;
        }
        for (auto it = map.begin(); it != map.end(); it++)
        {
            int k = it->second;
            ret += (k - 1) * k;
        }
    }
    return ret;
}