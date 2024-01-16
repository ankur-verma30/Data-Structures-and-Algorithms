#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
#define INF 1e18 + 1

struct Node
{
    Node *links[26];
    bool flag = false;

    // check if the reference trie is present or not
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    // creating reference trie
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // to get the next node for traversal
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // setting the flag to true at the end of the word
    void setEnd()
    {
        flag = true;
    }

    // checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        // creating new object
        root = new Node();
    }

    void insert(string words)
    {
        // initializing dummy node pointing to the root
        Node *node = root;

        for (int i = 0; i < words.length(); i++)
        {
            if (!node->containsKey(words[i]))
            {
                node->put(words[i], new Node());
            }

            // moves to refrence trie
            node = node->get(words[i]);
        }
        node->setEnd();
    }

    // searching in trie
    bool searching(string words)
    {
        Node *node = root;
        for (int i = 0; i < words.length(); i++)
        {
            if (!node->containsKey(words[i]))
                return false;
            node = node->get(words[i]);
        }
        return node->isEnd();
    }

    bool StartsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main()
{
    int n = 5;
    vector<int> type = {1, 1, 2, 3, 2};
    vector<string> values = {"hello", "help", "help", "hel", "hel"};
    Trie trie;

    for (int i = 0; i < n; i++)
    {
        if (type[i] == 1)
            trie.insert(values[i]);

        if (type[i] == 2)
        {
            if (trie.searching(values[i]))
                cout << "true " << endl;
            else
                cout << "false " << endl;
        }
        if(type[i]==3)
        {
            if (trie.StartsWith(values[i]))
                cout << "true " << endl;
            else
                cout << "false " << endl;
        }
    }
    return 0;
}