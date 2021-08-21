#include <vector>
#include <cmath>
using namespace std;

int getDis(int x, int y, vector<int> &target)
{
    return abs(x - target[0]) + abs(y - target[1]);
}

bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
{
    int yourDis = getDis(0, 0, target);
    vector<int> ghostsDis(ghosts.size());
    for (int i = 0; i < ghosts.size(); i++)
    {
        ghostsDis[i] = getDis(ghosts[i][0], ghosts[i][1], target);
    }
    for (int dis : ghostsDis)
    {
        if (yourDis >= dis)
        {
            return false;
        }
    }

    return true;
}
