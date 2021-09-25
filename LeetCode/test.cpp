#include <cstdint>
#include <iostream>
using namespace std;

int main()
{
    uint32_t isn = (1 << 32) - 2;
    cout << isn << endl;
    uint64_t n = (1 << 32) + 2;
    isn += n;
    cout << isn << endl;
    return 0;
}