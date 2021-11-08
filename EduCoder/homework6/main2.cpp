#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<string> findNext(int x, int y, int cur, int len, vector<vector<int>> &mat, string &X)
{
    if (cur == len)
    {
        set<string> a;
        a.insert("");
        return a;
    }

    int m = mat.size() - 1;
    int n = mat[0].size() - 1;
    set<string> ret;
    ret.insert("");
    for (int i = x; i <= m; i++)
    {
        for (int j = y; j <= n; j++)
        {
            if (mat[i][j - 1] == cur && mat[i - 1][j] == cur && mat[i][j] == cur + 1)
            {
                string s;
                s.push_back(X[i - 1]);
                set<string> next = findNext(i + 1, j + 1, cur + 1, len, mat, X);
                for (auto &ss : next)
                {
                    if (ss.length() == len - cur - 1)
                    {
                        ret.insert(s + ss);
                    }
                }
            }
        }
    }

    return ret;
}

set<string> LCS(string X, string Y)
{
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> mat(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            mat[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        char a = X[i - 1];
        for (int j = 1; j <= n; j++)
        {
            char b = Y[j - 1];
            if (a == b)
            {
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            else
            {
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            }
        }
    }

    // cout << "    ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << Y[i] << " ";
    // }
    // cout << endl;

    // for (int i = 0; i <= m; i++)
    // {
    //     if (i > 0)
    //     {
    //         cout << X[i - 1] << " ";
    //     }
    //     else
    //     {
    //         cout << "  ";
    //     }

    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int len = mat[m][n];
    set<string> ret;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mat[i][j - 1] == 0 && mat[i - 1][j] == 0 && mat[i][j] == 1)
            {
                string s;
                s.push_back(X[i - 1]);
                set<string> next = findNext(i + 1, j + 1, 1, len, mat, X);
                for (auto &ss : next)
                {
                    if (ss.length() == len - 1)
                    {
                        ret.insert(s + ss);
                    }
                }
            }
        }
    }

    return ret;
}

// 2 3

int main()
{
    string X, Y;
    cin >> X;
    cin >> Y;

    set<string> lcs = LCS(X, Y);

    // print set elements
    for (string str : lcs)
        cout << str << endl;

    return 0;
}