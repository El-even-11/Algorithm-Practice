#include <vector>
#include <iostream>
using namespace std;

int prefix[110];

int sumOddLengthSubarrays(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    int ans = 0;
    for (int len = 1; len <= n; len += 2)
    {
        for (int l = 0; l + len - 1 < n; l++)
        {
            int r = l + len - 1;
            ans += prefix[r + 1] - prefix[l];
        }
    }
    return ans;
}

int main()
{
    vector<int> arr({1, 3, 5, 3, 1, 5, 6, 2, 7, 4, 4, 3, 5, 6, 7});
    cout << sumOddLengthSubarrays(arr) << endl;
    return 0;
}