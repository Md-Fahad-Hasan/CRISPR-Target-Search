#include <iostream>
#include "Trie.h"

using namespace std;

void showMenu()
{
    cout << "\nCRISPR Target Finder\n";
    cout << "1. Add DNA sequence\n";
    cout << "2. Check exact match\n";
    cout << "3. Exit\n";
    cout << "Choose option: ";
}

int main()
{
    Trie dnaDB;
    int choice;
    string sequence;

    while (true)
    {
        showMenu();
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter DNA sequence to add (A,T,G,C only): ";
            cin >> sequence;
            dnaDB.insert(sequence);
            cout << "Added!\n";
        }
        else if (choice == 2)
        {
            cout << "Enter sequence to search: ";
            cin >> sequence;
            if (dnaDB.search(sequence))
            {
                cout << "Match found!\n";
            }
            else
            {
                cout << "No match found.\n";
            }
        }
        else if (choice == 3)
        {
            cout << "Goodbye!\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}