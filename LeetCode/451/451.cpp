#include <string>
#include <queue>
#include <iostream>
using namespace std;

class c
{
public:
    int cnt;
    char ch;

    c(int cnt, char ch)
    {
        this->cnt = cnt;
        this->ch = ch;
    }

    bool operator>(const c &x) const
    {
        return this->cnt >= x.cnt;
    }

    bool operator<(const c &x) const
    {
        return this->cnt < x.cnt;
    }
};

string frequencySort(string s)
{
    int cnt[128] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        cnt[s.at(i)]++;
    }

    priority_queue<c> queue;

    for (int i = 0; i < 128; i++)
    {
        if (cnt[i] != 0)
        {
            c x(cnt[i], (char)(i));
            queue.push(x);
        }
    }

    string ret;
    while (!queue.empty())
    {
        int cnt = queue.top().cnt;
        char ch = queue.top().ch;
        for (int i = 0; i < cnt; i++)
        {
            ret.push_back(ch);
        }
        queue.pop();
    }

    return ret;
}

int main()
{
    string s;
    cin >> s;
    cout << frequencySort(s);
}