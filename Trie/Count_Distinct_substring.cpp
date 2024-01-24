#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *links[26];

    bool containsKey(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

int CountDistinctString(string words)
{
    Node *root = new Node();
    int count = 0;

    for (int i = 0; i < words.length(); i++)
    {
        Node *node = root;
        for (int j = i; j < words.length(); j++)
        {
            if (!node->containsKey(words[i]))
            {
                count++;
                node->put(words[i], new Node());
            }
            node = node->get(words[i]);
        }
    }
    return count + 1;
}

int main()
{
    string words = "abab";
    cout << "the distinct substring present in the string is " << CountDistinctString(words) << endl;
    return 0;
}