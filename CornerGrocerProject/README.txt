Corner Grocer Item‑Tracking Program
-----------------------------------

Files:
- main.cpp            : program entry and menu handling
- GroceryTracker.h    : class declaration
- GroceryTracker.cpp  : class implementation

How to build (g++ example):
    g++ main.cpp GroceryTracker.cpp -o CornerGrocer

Program expects CS210_Project_Three_Input_File.txt to be in the same directory.
At startup it loads the file, builds a frequency map, and writes a backup file named frequency.dat.

Menu:
1. Search for an item's frequency
2. Print all item frequencies with numbers
3. Print histogram (** item count shown as asterisks **)
4. Exit