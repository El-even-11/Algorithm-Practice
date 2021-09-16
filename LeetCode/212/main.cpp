#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

vector<string> ret;
vector<vector<char>> board;
unordered_set<string> set;
string chars;
bool vis[12][12];
int m;
int n;
int D[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void backtrack(int i, int j)
{
    if (chars.size() > 10)
    {
        return;
    }

    if (set.find(chars)!=set.end())
    {
        ret.push_back(chars);
        set.erase(chars);
        return;
    }

    for (auto &d : D)
    {
        int di = i + d[0];
        int dj = j + d[1];
        if (di >= 0 && di < m && dj >= 0 && dj < n && !vis[di][dj])
        {
            vis[di][dj] = true;
            chars.push_back(board[di][dj]);
            backtrack(di, dj);
            vis[di][dj] = false;
            chars.pop_back();
        }
    }
}

vector<string> findWords(vector<vector<char>> &_board, vector<string> &words)
{
    board = _board;

    m = board.size();
    n = board[0].size();

    for (auto &s : words)
    {
        set.insert(s);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            chars.push_back(board[i][j]);
            vis[i][j] = true;
            backtrack(i, j);
            chars.pop_back();
            vis[i][j] = false;
        }
    }

    return ret;
}