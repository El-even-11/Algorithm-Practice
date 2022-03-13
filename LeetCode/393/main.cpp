#include <vector>
#include <iostream>
using namespace std;

bool validUtf8(vector<int> &data)
{
    int i = 0;
    int n = data.size();
    while (i < n)
    {
        int a = (data[i] >> 7) & 1;
        if (a == 0)
        {                              
            i++;
            continue;
        }
        int b = (data[i] >> 6) & 1;
        if (b == 0)
        {
            return false;
        }
        int c = (data[i] >> 5) & 1;
        if (c == 0)
        {
            // 110
            if (i + 1 >= n)
            {
                return false;
            }
            int x = (data[i + 1] >> 7) & 1;
            int y = (data[i + 1] >> 6) & 1;
            if (x != 1 || y != 0)
            {
                return false;
            }
            i += 2;
            continue;
        }
        int d = (data[i] >> 4) & 1;
        if (d == 0)
        {
            // 1110
            if (i + 2 >= n)
            {
                return false;
            }
            int x1 = (data[i + 1] >> 7) & 1;
            int y1 = (data[i + 1] >> 6) & 1;
            int x2 = (data[i + 2] >> 7) & 1;
            int y2 = (data[i + 2] >> 6) & 1;
            if (!(x1 == 1 && y1 == 0 && x2 == 1 && y2 == 0))
            {
                return false;
            }
            i += 3;
            continue;
        }
        int e = (data[i] >> 3) & 1;
        if (e == 0)
        {
            // 11110
            if (i + 3 >= n)
            {
                return false;
            }
            int x1 = (data[i + 1] >> 7) & 1;
            int y1 = (data[i + 1] >> 6) & 1;
            int x2 = (data[i + 2] >> 7) & 1;
            int y2 = (data[i + 2] >> 6) & 1;
            int x3 = (data[i + 3] >> 7) & 1;
            int y3 = (data[i + 3] >> 6) & 1;
            if (!(x1 == 1 && y1 == 0 && x2 == 1 && y2 == 0 && x3 == 1 && y3 == 0))
            {
                return false;
            }
            i += 4;
            continue;
        }
        return false;
    }
    return true;
}

int main()
{
    vector<int> nums = {115, 100, 102, 231, 154, 132, 13, 10};
    cout << validUtf8(nums) << endl;
    return 0;
}

// 01110011 01100100 01100110 11100111 10011010 10000100 00001101 00001010