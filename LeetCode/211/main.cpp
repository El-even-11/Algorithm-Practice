#include <string>
using namespace std;

class WordDictionary
{
    class TrieNode
    {
    public:
        bool end = false;
        TrieNode *tns[26];
    };

    TrieNode *root;

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); i++)
        {
            int ch = word[i] - 'a';
            if (!p->tns[ch])
            {
                p->tns[ch] = new TrieNode();
            }
            p = p->tns[ch];
        }
        p->end = true;
    }

    bool search(string word)
    {
        return dfs(word, root, 0);
    }

    bool dfs(string word, TrieNode *p, int i)
    {
        if (word.length() == i)
        {
            return p->end;
        }

        if (word[i] == '.')
        {
            for (int ch = 0; ch < 26; ch++)
            {
                if (p->tns[ch] && dfs(word, p->tns[ch], i + 1))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            int ch = word[i] - 'a';
            if (!p->tns[ch])
            {
                return false;
            }
            return dfs(word, p->tns[ch], i + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */