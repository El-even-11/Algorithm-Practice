#include <iostream>
#include <vector>
using namespace std;

int sumOddLengthSubarrays(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int lcnt = i;
        int rcnt = n - i - 1;
        int lodd = (lcnt + 1) / 2;
        int rodd = (rcnt + 1) / 2;
        int leven = lcnt / 2 + 1;
        int reven = rcnt / 2 + 1;
        sum += (lodd * rodd + leven * reven)*arr[i];
    }
    return sum;
}