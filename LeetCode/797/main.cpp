#include <vector>
using namespace std;

vector<vector<int>> ret;

vector<vector<int>> graph;

void dfs(int i, vector<int> path)
{
    if (i == graph.size())
    {
        ret.push_back(path);
        return;
    }

    for (int k : graph[i])
    {
        path.push_back(k);
        dfs(k, path);
        path.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &_graph)
{
    graph = _graph;
    vector<int> path;
    path.push_back(0);
    dfs(0, path);
    return ret;
}