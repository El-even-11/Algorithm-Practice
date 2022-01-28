#include <iostream>
using namespace std;

int main()
{
    char s[50] = "sadhuwgfvhaiobfoafa";
    short *p1 = (short *)(s + 4);
    short *p2 = (short *)(s + 20);

    cout << p2 - p1;
}