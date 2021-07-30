#include <string>
#include <cmath>
using namespace std;

int titleToNumber(string columnTitle)
{
    int ret = 0;
    int pos = 0;
    for (int i = columnTitle.length() - 1; i >= 0; i--)
    {
        ret += (columnTitle.at(i) - 'A' + 1) * pow(26, pos);
        pos++;
    }

    return ret;
}