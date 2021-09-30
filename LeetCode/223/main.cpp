#include <iostream>
#include <algorithm>
using namespace std;

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    int x = max(0, min(bx2, ax2) - max(ax1, bx1));
    int y = max(0, min(by2, ay2) - max(ay1, by1));
    return (bx2 - bx1) * (by2 - by1) + (ax2 - ax1) * (ay2 - ay1) - x * y;
}