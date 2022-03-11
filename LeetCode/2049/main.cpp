#include <vector>
#include <iostream>
using namespace std;

int getNum(vector<vector<int>> &g, vector<int> &f, int root)
{
    if (root == -1)
    {
        return 0;
    }
    int a, b;

    if (g[root][1] != -1)
    {
        if (f[g[root][1]] == -1)
        {
            f[g[root][1]] = getNum(g, f, g[root][1]);
        }
        a = f[g[root][1]];
    }
    else
    {
        a = 0;
    }

    if (g[root][2] != -1)
    {
        if (f[g[root][2]] == -1)
        {
            f[g[root][2]] = getNum(g, f, g[root][2]);
        }
        b = f[g[root][2]];
    }
    else
    {
        b = 0;
    }

    return a + b + 1;
}

int countHighestScoreNodes(vector<int> &parents)
{
    int n = parents.size();
    vector<vector<int>> g(n, vector<int>(3));
    vector<int> f(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            g[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (parents[i] == -1)
        {
            continue;
        }
        g[i][0] = parents[i];
        if (g[parents[i]][1] == -1)
        {
            g[parents[i]][1] = i;
        }
        else
        {
            g[parents[i]][2] = i;
        }
    }

    f[0] = getNum(g, f, 0);

    long long max = -1;
    int cnt = 1;

    for (int i = 0; i < n; i++)
    {
        int a = (n - f[i]) == 0 ? 1 : (n - f[i]);
        int b = g[i][1] == -1 ? 1 : f[g[i][1]];
        int c = g[i][2] == -1 ? 1 : f[g[i][2]];
        if (max < (long long)a * (long long)b * (long long)c)
        {
            cnt = 1;
            max = (long long)a * (long long)b * (long long)c;
        }
        else if (max == (long long)a * (long long)b * (long long)c)
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    vector<int> p = {-1, 2, 0,2,0};
    cout << countHighestScoreNodes(p) << endl;
    return 0;
}