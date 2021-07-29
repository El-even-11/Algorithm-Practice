#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> pathInZigZagTree(int label)
{

    int cnt = 0;
    while (true)
    {
        if (label >= pow(2, cnt) && label <= pow(2, cnt + 1) - 1)
        {
            break;
        }
        cnt++;
    }

    int t;
    if (cnt % 2 == 0)
    {
        t = label;
    }
    else
    {
        t = pow(2, cnt) + pow(2, cnt + 1) - 1 - label;
    }

    vector<int> ret;
    while (t > 0)
    {
        ret.push_back(t);
        t /= 2;
    }

    for (int i = 0; i < ret.size() / 2; i++)
    {
        int tmp = ret[i];
        ret[i] = ret[ret.size() - 1 - i];
        ret[ret.size() - 1 - i] = tmp;
    }

    for (int i = 1; i < ret.size(); i += 2)
    {
        int sum = pow(2, i) + pow(2, i + 1) - 1;
        ret[i] = sum - ret[i];
    }

    return ret;
}

int main()
{
    vector<int> ret = pathInZigZagTree(14);
    for (int i : ret)
    {
        cout << i << " ";
    }
    return 0;
}