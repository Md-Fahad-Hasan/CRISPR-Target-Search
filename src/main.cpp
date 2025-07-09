#include <iostream>
#include "CRISPRSearch.h"
#include "DNASequence.h"

using namespace std;

void displayMenu()
{
    cout << "\nCRISPR Target Search System\n";
    cout << "1. Load DNA sequences from file\n";
    cout << "2. Generate random DNA sequences\n";
    cout << "3. Search for exact match (CRISPR perfect match)\n";
    cout << "4. Search for prefix match (CRISPR partial match)\n";
    cout << "5. Search for substring match (General DNA search)\n";
    cout << "6. Display all loaded sequences\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

void printResults(const vector<string> &results, const string &searchType)
{
    if (results.empty())
    {
        cout << "No " << searchType << " matches found.\n";
        return;
    }

    cout << "Found " << results.size() << " " << searchType << " match(es):\n";
    for (size_t i = 0; i < results.size(); ++i)
    {
        cout << i + 1 << ". " << results[i] << "\n";
    }
}

int main()
{
    CRISPRSearch searchSystem;
    int choice;
    string input;

    do
    {
        displayMenu();
        cin >> choice;
        cin.ignore();

        try
        {
            switch (choice)
            {
            case 1:
            {
                cout << "Enter filename (in data/ directory): ";
                string filename;
                getline(cin, filename);
                auto sequences = DNASequence::loadSequencesFromFile("data/" + filename);
                searchSystem.loadDNASequences(sequences);
                cout << "Loaded " << sequences.size() << " valid DNA sequences.\n";
                break;
            }

            case 2:
            {
                int count, minLen, maxLen;
                cout << "Number of sequences to generate: ";
                cin >> count;
                cout << "Minimum length: ";
                cin >> minLen;
                cout << "Maximum length: ";
                cin >> maxLen;

                auto sequences = DNASequence::generateRandomSequences(count, minLen, maxLen);
                searchSystem.loadDNASequences(sequences);
                cout << "Generated and loaded " << sequences.size() << " random DNA sequences.\n";
                break;
            }

            case 3:
            {
                cout << "Enter guide RNA for exact match: ";
                getline(cin, input);
                printResults(searchSystem.findExactMatches(input), "exact");
                break;
            }

            case 4:
            {
                cout << "Enter prefix for partial match: ";
                getline(cin, input);
                printResults(searchSystem.findPrefixMatches(input), "prefix");
                break;
            }

            case 5:
            {
                cout << "Enter substring to search: ";
                getline(cin, input);
                printResults(searchSystem.findSubstringMatches(input), "substring");
                break;
            }

            case 6:
            {
                auto allSeqs = searchSystem.getAllSequences();
                printResults(allSeqs, "loaded sequence");
                break;
            }

            case 7:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << "\n";
        }
    } while (choice != 7);

    return 0;
}