#include <vector>
#include <iostream>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int l = 0;
    int r = arr.size() - 1;
    int ret = l;
    while (l <= r) // 24, 69, 100, 99, 79, 78, 67, 36, 26, 19
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] > arr[mid - 1])
        {
            ret = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ret;
}

int main()
{
    vector<int> test = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    cout << peakIndexInMountainArray(test) << endl;

    return 0;
}