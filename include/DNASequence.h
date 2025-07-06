#ifndef DNA_SEQUENCE_H
#define DNA_SEQUENCE_H

#include <string>

using namespace std;

bool isValidDNA(string seq)
{
    for (char c : seq)
    {
        c = toupper(c);
        if (c != 'A' && c != 'T' && c != 'G' && c != 'C')
        {
            return false;
        }
    }
    return !seq.empty();
}

#endif