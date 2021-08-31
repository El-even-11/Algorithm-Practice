#include <vector>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> gap(n + 1);
    for (auto &b : bookings)
    {
        gap[b[0] - 1] += b[2];
        gap[b[1]] -= b[2];
    }
    vector<int> ret(n);
    ret[0] = gap[0];
    for (int i = 1; i < n; i++)
    {
        ret[i] = ret[i - 1] + gap[i];
    }
    return ret;
}