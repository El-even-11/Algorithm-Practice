#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        bool exist[100000];
        for (int i = 0; i <= edges.size(); i++)
        {
            exist[i] = false;
        }

        for (int i = 0; i <= edges.size(); i++)
        {
            if (exist[edges[i][0]])
            {
                return edges[i][0];
            }
            if (exist[edges[i][1]])
            {
                return edges[i][1];
            }
            exist[edges[i][0]] = true;
            exist[edges[i][1]] = true;
        }

        return 0;
    }
};