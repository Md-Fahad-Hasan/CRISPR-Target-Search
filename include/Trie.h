#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <vector>
#include <string>

using namespace std;

class TrieNode
{
public:
    map<char, TrieNode *> children;
    bool isEnd;

    TrieNode()
    {
        isEnd = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            if (current->children.count(c) == 0)
            {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            if (current->children.count(c) == 0)
            {
                return false;
            }
            current = current->children[c];
        }
        return current->isEnd;
    }
};

#endif