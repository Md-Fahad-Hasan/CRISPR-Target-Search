cmake_minimum_required(VERSION 3.10)
project(CRISPR_Target_Search)

set(CMAKE_CXX_STANDARD 17)

# Include directory
include_directories(include)

# Source files
set(SOURCES
    src/Trie.cpp
    src/DNASequence.cpp
    src/CRISPRSearch.cpp
    src/main.cpp
)

# Create executable
add_executable(CRISPR_Target_Search ${SOURCES})

# Create data directory if it doesn't exist
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data)
