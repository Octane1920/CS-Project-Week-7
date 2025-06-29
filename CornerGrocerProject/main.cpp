#include <iostream>
#include <fstream>
#include <string>
//Author: Kyle Altemeyer Date: 6/22/2025
#include <map>
#include <iomanip>
#include "GroceryTracker.h"

using namespace std;

void PrintMenu() {
    cout << "\n====== Corner Grocer Menu ======\n";
    cout << "1 - Search for item frequency\n";
    cout << "2 - Print all item frequencies\n";
    cout << "3 - Print histogram\n";
    cout << "4 - Exit program\n";
    cout << "Choose an option: ";
}

int main() {
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt");

    // create backup file at program start
    tracker.WriteBackup("frequency.dat");

    bool running = true;
    while (running) {
        PrintMenu();
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }
        cin.ignore(); // consume newline
        switch (choice) {
            case 1: {
                cout << "Enter item to look up: ";
                string item;
                getline(cin, item);
                int freq = tracker.GetFrequency(item);
                cout << item << " appears " << freq << " time(s).\n";
                break;
            }
            case 2:
                tracker.PrintFrequencies();
                break;
            case 3:
                tracker.PrintHistogram();
                break;
            case 4:
                running = false;
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Please select 1-4.\n";
        }
    }
    return 0;
}