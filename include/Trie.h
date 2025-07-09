#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfSequence;
    vector<string> sequences;

    TrieNode() : isEndOfSequence(false) {}
};

class Trie
{
private:
    TrieNode *root;

    void collectSequences(TrieNode *node, vector<string> &results) const;

public:
    Trie();
    ~Trie();

    void insertSequence(const string &sequence);
    bool searchExact(const string &sequence) const;
    vector<string> searchPrefix(const string &prefix) const;
    vector<string> getAllSequences() const;
};

#endif
