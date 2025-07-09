#include "DNASequence.h"
#include <fstream>
#include <stdexcept>
#include <random>
#include <algorithm>

bool DNASequence::isValidSequence(const string &sequence)
{
    const string validNucleotides = "ATGC";
    return !sequence.empty() &&
           all_of(sequence.begin(), sequence.end(), [&validNucleotides](char c)
                  { return validNucleotides.find(toupper(c)) != string::npos; });
}

vector<string> DNASequence::loadSequencesFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        throw runtime_error("Could not open file: " + filename);
    }

    vector<string> sequences;
    string line;

    while (getline(file, line))
    {
        if (line.empty() || line[0] == '>')
            continue;

        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
        transform(line.begin(), line.end(), line.begin(), ::toupper);

        if (isValidSequence(line))
        {
            sequences.push_back(line);
        }
    }

    return sequences;
}

string DNASequence::generateRandomSequence(size_t length)
{
    static const char nucleotides[] = {'A', 'T', 'G', 'C'};
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis(0, 3);

    string sequence;
    sequence.reserve(length);

    for (size_t i = 0; i < length; ++i)
    {
        sequence += nucleotides[dis(gen)];
    }

    return sequence;
}

vector<string> DNASequence::generateRandomSequences(size_t count, size_t minLength, size_t maxLength)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<size_t> lenDis(minLength, maxLength);

    vector<string> sequences;
    sequences.reserve(count);

    for (size_t i = 0; i < count; ++i)
    {
        sequences.push_back(generateRandomSequence(lenDis(gen)));
    }

    return sequences;
}

vector<string> DNASequence::findSubstringMatches(const vector<string> &sequences, const string &substring)
{
    vector<string> matches;
    string upperSubstring = substring;
    transform(upperSubstring.begin(), upperSubstring.end(), upperSubstring.begin(), ::toupper);

    for (const auto &seq : sequences)
    {
        if (seq.find(upperSubstring) != string::npos)
        {
            matches.push_back(seq);
        }
    }

    return matches;
}