#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int divide(vector<int> &s, int l, int r)
{
    int i = l, j = r, x = s[l];
    while (i < j)
    {
        while (i < j && s[j] >= x)
            j--;
        if (i < j)
            s[i++] = s[j];
        while (i < j && s[i] <= x)
            i++;
        if (i < j)
            s[j--] = s[i];
    }
    s[i] = x;
    return i;
}

void quickSort(vector<int> &s, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int pivot = divide(s, l, r);
    quickSort(s, l, pivot - 1);
    quickSort(s, pivot + 1, r);
}

int hIndex(vector<int> &citations)
{
    int n = citations.size();
    quickSort(citations, 0, n - 1);

    int h = 0;
    for (int i = 0; i < n; i++)
    {
        h = max(h, min(citations[i], n - i));
    }

    return h;
}

int main()
{
    // Process input line
    string s;
    getline(cin, s);
    stringstream str(s);
    int a;
    vector<int> citations;
    while (str >> a)
    {
        citations.push_back(a);
    }

    cout << hIndex(citations);
    // Return the result

    return 0;
}
