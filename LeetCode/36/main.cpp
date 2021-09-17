#include <vector>
using namespace std;

bool row[9][10];
bool col[9][10];
bool box[9][10];

bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int r = i;
            int c = j;
            int b = i / 3 + j / 3 * 3;
            char x = board[i][j];
            if (x != '.')
            {
                if (row[r][x - '0'] || col[c][x - '0'] || box[b][x - '0'])
                {
                    return false;
                }
                row[r][x - '0'] = true;
                col[c][x - '0'] = true;
                box[b][x - '0'] = true;
            }
        }
    }

    return true;
}