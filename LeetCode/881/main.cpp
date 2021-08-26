#include <vector>
#include <algorithm>
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int l = 0;
    int r = people.size() - 1;
    int cnt = 0;
    while (l <= r)
    {
        if (people[l] + people[r] <= limit)
        {
            l++;
            r--;
        }
        else
        {
            r--;
        }
        cnt++;
    }

    return cnt;
}