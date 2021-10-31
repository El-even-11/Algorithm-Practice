#include <string.h>
using namespace std;

// You can add any members in the class.
// The following 4 functions will be called in test program.
class Trie
{
private:
    class TrieNode
    {
    public:
        TrieNode *tns[26];
        bool end;
    };

    TrieNode *root;

public:
    Trie()
    {
        // TODO
        root = new TrieNode();
    }

    void insert(char *word)
    {
        // TODO
        TrieNode *p = root;
        int n = strlen(word);
        for (int i = 0; i < n; i++)
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

    bool search(char *word)
    {
        // TODO
        TrieNode *p = root;
        int n = strlen(word);
        for (int i = 0; i < n; i++)
        {
            int ch = word[i] - 'a';
            if (!p->tns[ch])
            {
                return false;
            }
            p = p->tns[ch];
        }
        return p->end;
    }

    bool startsWith(char *prefix)
    {
        // TODO
        TrieNode *p = root;
        int n = strlen(prefix);
        for (int i = 0; i < n; i++)
        {
            int ch = prefix[i] - 'a';
            if (!p->tns[ch])
            {
                return false;
            }
            p = p->tns[ch];
        }
        return true;
    }
};