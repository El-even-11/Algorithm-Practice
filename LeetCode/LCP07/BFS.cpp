#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int numWays(int n, vector<vector<int>> &relation, int k)
{
    vector<vector<int>> edges(n);
    for (int i = 0; i < relation.size(); i++)
    {
        edges[relation[i][0]].push_back(relation[i][1]);
    }

    queue<vector<int>> q;
    q.push(edges[0]);
    int pre = 1;
    int cnt = 0;
    int ways = 0;

    while (!q.empty())
    {
        int now = pre;
        pre = 0;
        cnt++;
        //当前层有now个节点

        if (cnt > k)
        {
            break;
        }

        if (cnt == k)
        {
            while (!q.empty())
            {
                vector<int> Now = q.front();
                q.pop();
                for (int i : Now)
                {
                    if (i == n - 1)
                    {
                        ways++;
                    }
                }
            }
            break;
        }

        for (int k = 0; k < now; k++)
        {
            vector<int> Now = q.front();
            q.pop();
            pre += Now.size();
            for (int i : Now)
            {
                q.push(edges[i]);
            }
        }
    }

    return ways;
}

int main()
{
    int n, k, edges;
    cin >> n >> k >> edges;
    vector<vector<int>> relation(edges);
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        relation[i].push_back(a);
        relation[i].push_back(b);
    }

    cout << numWays(n, relation, k);
    return 0;
}