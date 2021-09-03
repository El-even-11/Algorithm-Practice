#include <queue>
#include <vector>
using namespace std;

vector<int> smallestK(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i : arr)
    {
        q.push(i);
    }

    vector<int> ret;
    while (k--)
    {
        ret.push_back(q.top());
        q.pop();
    }
    return ret;
}