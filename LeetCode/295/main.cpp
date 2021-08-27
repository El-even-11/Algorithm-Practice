#include <queue>
using namespace std;

class MedianFinder
{
public:
    /** initialize your data structure here. */
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (l.size() == r.size())
        {
            if (l.empty() || num <= r.top())
            {
                l.push(num);
            }
            else
            {
                r.push(num);
                int temp = r.top();
                r.pop();
                l.push(temp);
            }
        }
        else
        {
            if (num >= l.top())
            {
                r.push(num);
            }
            else
            {
                l.push(num);
                int temp = l.top();
                l.pop();
                r.push(temp);
            }
        }
    }

    double findMedian()
    {
        if (l.size() == r.size())
        {
            return (l.top() + r.top()) / 2.0;
        }
        else
        {
            return l.top();
        }
    }
};