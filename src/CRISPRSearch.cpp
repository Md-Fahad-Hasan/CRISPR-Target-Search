#include "CRISPRSearch.h"
#include "DNASequence.h"

void CRISPRSearch::loadDNASequences(const vector<string> &sequences)
{
    allSequences.clear();

    for (const auto &seq : sequences)
    {
        dnaTrie.insertSequence(seq);
        allSequences.push_back(seq);
    }
}

vector<string> CRISPRSearch::findExactMatches(const string &guideRNA) const
{
    if (dnaTrie.searchExact(guideRNA))
    {
        return {guideRNA};
    }
    return {};
}

vector<string> CRISPRSearch::findPrefixMatches(const string &prefix) const
{
    return dnaTrie.searchPrefix(prefix);
}

vector<string> CRISPRSearch::findSubstringMatches(const string &substring) const
{
    return DNASequence::findSubstringMatches(allSequences, substring);
}

vector<string> CRISPRSearch::getAllSequences() const
{
    return allSequences;
}