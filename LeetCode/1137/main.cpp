#include <iostream>
using namespace std;

int a[40];

int f(int i)
{
    if (a[i] != -1)
    {
        return a[i];
    }
    a[i] = f(i - 1) + f(i - 2) + f(i - 3);
    return a[i];
}

int tribonacci(int n)
{
    for (int i = 0; i < 40; i++)
    {
        a[i] = -1;
    }
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    return f(n);
}