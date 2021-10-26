#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

class Solution
{
public:
    int kthLargestElement(vector<int> &arr, int k)
    {
        // Find the k-th largest element in the array
        srand(time(NULL));
        int n = arr.size();
        int l = 0, r = n - 1;
        while (true)
        {
            int i = l, j = r;
            int p = rand() % (r - l + 1) + l;
            swap(arr[l], arr[p]);
            while (i < j)
            {
                while (i < j && arr[j] >= arr[l])
                    j--;
                while (i < j && arr[i] <= arr[l])
                    i++;
                swap(arr[i], arr[j]);
            }
            swap(arr[i], arr[l]);

            if (i == n - k)
                return arr[i];
            else if (i > n - k)
                r = i - 1;
            else
                l = i + 1;
        }
    }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main()
{
    // Input processing
    string sarr;
    getline(cin, sarr);
    stringstream ssarr(sarr);
    int a;
    vector<int> arr;
    while (ssarr >> a)
        arr.push_back(a);
    int k;
    cin >> k;

    // Return the result
    Solution s;
    cout << s.kthLargestElement(arr, k);

    return 0;
}
