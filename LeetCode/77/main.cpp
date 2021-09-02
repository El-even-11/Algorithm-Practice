#include <vector>
using namespace std;

vector<int> cur;
vector<vector<int>> ret;

void backtrack(int i, int n, int k)
{
    if (cur.size() + n - i + 1 < k)
    {
        return;
    }

    if (cur.size() == k)
    {
        ret.push_back(cur);
        return;
    }

    cur.push_back(i);
    backtrack(i + 1, n, k);
    cur.pop_back();
    backtrack(i + 1, n, k);
}

vector<vector<int>> combine(int n, int k)
{
    backtrack(1, n, k);
    return ret;
}