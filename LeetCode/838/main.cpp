#include <string>
#include <queue>
using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        queue<int> q;

        int n = dominoes.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] != '.')
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            if (dominoes[i] == 'L')
            {
                if (i - 1 < 0 || dominoes[i - 1] == 'L' || dominoes[i - 1] == 'R' && time[i - 1] <= time[i])
                {
                    continue;
                }
                else if (dominoes[i - 1] == 'R')
                {
                    dominoes[i - 1] = '.';
                }
                else
                {
                    dominoes[i - 1] = 'L';
                    time[i - 1]++;
                    q.push(i - 1);
                }
            }
            else
            {
                if (i + 1 >= n || dominoes[i + 1] == 'R' || dominoes[i + 1] == 'L' && time[i + 1] <= time[i])
                {
                    continue;
                }
                else if (dominoes[i + 1] == 'L')
                {
                    dominoes[i + 1] = '.';
                }
                else
                {
                    dominoes[i + 1] = 'R';
                    time[i + 1]++;
                    q.push(i + 1);
                }
            }
        }

        return dominoes;
    }
};