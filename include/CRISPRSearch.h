#ifndef CRISPR_SEARCH_H
#define CRISPR_SEARCH_H

#include "Trie.h"
#include <string>
#include <vector>

using namespace std;

class CRISPRSearch
{
private:
    Trie dnaTrie;
    vector<string> allSequences;

public:
    void loadDNASequences(const vector<string> &sequences);

    vector<string> findExactMatches(const string &guideRNA) const;
    vector<string> findPrefixMatches(const string &prefix) const;
    vector<string> findSubstringMatches(const string &substring) const;

    vector<string> getAllSequences() const;
};

#endif
