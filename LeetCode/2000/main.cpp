#include <iostream>
using namespace std;

string reversePrefix(string word, char ch)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == ch)
        {
            for (int j = 0; j < (i + 1) / 2; j++)
            {
                char temp = word[j];
                word[j] = word[i - j];
                word[i - j] = temp;
            }
            break;
        }
    }

    return word;
}