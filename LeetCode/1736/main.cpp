#include <string>
using namespace std;

string maximumTime(string time)
{
    char chars[4];
    chars[0] = time.at(0);
    chars[1] = time.at(1);
    chars[2] = time.at(3);
    chars[3] = time.at(4);

    string ret;

    if (chars[0] == '?' || chars[1] == '?')
    {
        if (chars[0] == '?' && chars[1] == '?')
        {
            ret.append("23");
        }
        else if (chars[0] == '?')
        {
            if (chars[1] <= '3')
            {
                ret.append("2").push_back(chars[1]);
            }
            else
            {
                ret.append("1").push_back(chars[1]);
            }
        }
        else
        {
            if (chars[0] == '2')
            {
                ret.append("23");
            }
            else
            {
                ret.push_back(chars[0]);
                ret.append("9");
            }
        }
    }
    else
    {
        ret.push_back(chars[0]);
        ret.push_back(chars[1]);
    }

    ret.push_back(':');

    if (chars[2] == '?' || chars[3] == '?')
    {
        if (chars[2] == '?' && chars[3] == '?')
        {
            ret.append("59");
        }
        else if (chars[2] == '?')
        {
            ret.append("5").push_back(chars[3]);
        }
        else
        {
            ret.push_back(chars[2]);
            ret.append("9");
        }
    }
    else
    {
        ret.push_back(chars[2]);
        ret.push_back(chars[3]);
    }

    return ret;
}