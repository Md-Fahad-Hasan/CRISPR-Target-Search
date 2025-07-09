#include "Trie.h"
#include <iostream>

Trie::Trie() : root(new TrieNode()) {}

Trie::~Trie()
{
    delete root;
}

void Trie::insertSequence(const string &sequence)
{
    TrieNode *current = root;
    for (char nucleotide : sequence)
    {
        if (current->children.find(nucleotide) == current->children.end())
        {
            current->children[nucleotide] = new TrieNode();
        }
        current = current->children[nucleotide];
    }
    current->isEndOfSequence = true;
    current->sequences.push_back(sequence);
}

bool Trie::searchExact(const string &sequence) const
{
    TrieNode *current = root;
    for (char nucleotide : sequence)
    {
        if (current->children.find(nucleotide) == current->children.end())
        {
            return false;
        }
        current = current->children.at(nucleotide);
    }
    return current->isEndOfSequence;
}

vector<string> Trie::searchPrefix(const string &prefix) const
{
    vector<string> results;
    TrieNode *current = root;

    for (char nucleotide : prefix)
    {
        if (current->children.find(nucleotide) == current->children.end())
        {
            return results;
        }
        current = current->children.at(nucleotide);
    }

    collectSequences(current, results);
    return results;
}

void Trie::collectSequences(TrieNode *node, vector<string> &results) const
{
    if (node->isEndOfSequence)
    {
        results.insert(results.end(), node->sequences.begin(), node->sequences.end());
    }

    for (const auto &pair : node->children)
    {
        collectSequences(pair.second, results);
    }
}

vector<string> Trie::getAllSequences() const
{
    vector<string> allSequences;
    collectSequences(root, allSequences);
    return allSequences;
}