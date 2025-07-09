#ifndef DNA_SEQUENCE_H
#define DNA_SEQUENCE_H

#include <string>
#include <vector>

using namespace std;

namespace DNASequence
{
    bool isValidSequence(const string &sequence);

    vector<string> loadSequencesFromFile(const string &filename);

    string generateRandomSequence(size_t length);

    vector<string> generateRandomSequences(size_t count, size_t minLength, size_t maxLength);

    vector<string> findSubstringMatches(const vector<string> &sequences, const string &substring);
}

#endif
