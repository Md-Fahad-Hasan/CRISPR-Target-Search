# CRISPR Target Search Simulation

A Trie-based implementation simulating how the CRISPR-Cas9 system finds matching DNA sequences using guide RNA.

## Project Description

This project implements a Trie (prefix tree) data structure to efficiently store and search DNA sequences, simulating how the CRISPR-Cas9 system uses guide RNA to locate target sequences in a genome. The system supports:

- Exact sequence matching (simulating perfect guide RNA matches)
- Prefix matching (simulating partial matches)
- Bulk loading of DNA sequences from files
- Random sequence generation for testing

## Features

- Efficient Trie-based DNA sequence storage
- Exact match search (simulating perfect guide RNA matching)
- Prefix search (simulating partial matching)
- Input validation for DNA sequences (only A,T,G,C allowed)
- File loading and random sequence generation

## Project Structure

CRISPR-Target-Search/
├── include/ # Header files
│ ├── Trie.h # Trie data structure
│ ├── DNASequence.h # DNA sequence utilities
│ └── CRISPRSearch.h # Main search functionality
├── src/ # Implementation files
│ ├── Trie.cpp # Trie implementation
│ ├── DNASequence.cpp # DNA sequence functions
│ ├── CRISPRSearch.cpp # Search implementation
│ └── main.cpp # Main program
├── data/ # Sample DNA sequences
│ ├── sequences.txt # Example sequences
│ └── test_sequences.txt
└── CMakeLists.txt # Build configuration

## Requirements

- C++17 compatible compiler
- CMake (version 3.10 or higher)
