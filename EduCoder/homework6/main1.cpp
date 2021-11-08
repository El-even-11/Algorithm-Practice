// Add any standard library if needed.
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// Implement your minimum spinning tree algorithm

int minSpinning(vector<vector<int>> &g)
{
    int n = g.size();
    vector<bool> visited(n);
    visited[0] = true;
    for (int i = 1; i < n; i++)
    {
        visited[i] = false;
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = 2147483647;
        int min_i = -1;
        for (int k = 0; k < n; k++)
        {
            if (visited[k])
            {
                for (int j = 0; j < n; j++)
                {
                    if (g[k][j] > 0 && !visited[j] && g[k][j] < min)
                    {
                        min = g[k][j];
                        min_i = j;
                    }
                }
            }
        }
        sum += min;
        visited[min_i] = true;
    }

    return sum;
}

// Test your implementation
int main()
{
    vector<stringstream> strs;
    string str;
    while (!cin.eof())
    {
        getline(cin, str);
        strs.push_back(stringstream(str));
    }

    vector<vector<int>> g;
    double a;
    for (int i = 0; i < strs.size(); i++)
    {
        g.push_back(vector<int>());
        while (strs[i] >> a)
        {
            g[i].push_back(a);
        }
    }

    cout << minSpinning(g);

    return 0;
}