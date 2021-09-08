#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Pair
{
public:
    int profit;
    int capital;
    Pair(int profit, int capital)
    {
        this->profit = profit;
        this->capital = capital;
    }

    bool operator>(const Pair &pair) const
    {
        return this->profit > pair.profit;
    }

    bool operator<(const Pair &pair) const
    {
        return this->profit < pair.profit;
    }
};

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    priority_queue<Pair> queue;
    for (int i = 0; i < profits.size(); i++)
    {
        queue.push(Pair(profits[i], capital[i]));
    }

    vector<Pair> list;

    while (k--)
    {
        if (queue.empty())
        {
            return w;
        }
        Pair pair = queue.top();
        while (pair.capital > w)
        {
            list.push_back(pair);
            queue.pop();
            if (queue.empty())
            {
                return w;
            }
            pair = queue.top();
        }
        w += pair.profit;
        queue.pop();
        for (auto &p : list)
        {
            queue.push(p);
        }
        list.clear();
    }
    return w;
}

int main()
{
    vector<int> profits({1, 2, 3});
    vector<int> capital({0, 1, 2});
    cout << findMaximizedCapital(10, 0, profits, capital);
    return 0;
}