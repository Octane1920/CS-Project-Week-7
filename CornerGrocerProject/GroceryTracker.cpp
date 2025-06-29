//Author: Kyle Altemeyer Date: 6/22/2025
#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>

GroceryTracker::GroceryTracker(const std::string& filename) {
    LoadFile(filename);
}

void GroceryTracker::LoadFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening " << filename << "\n";
        return;
    }
    std::string item;
    while (inFile >> item) {
        ++frequencyMap[item];
    }
    inFile.close();
}

int GroceryTracker::GetFrequency(const std::string& item) const {
    auto it = frequencyMap.find(item);
    if (it != frequencyMap.end())
        return it->second;
    return 0;
}

void GroceryTracker::PrintFrequencies() const {
    std::cout << "\nItem Frequencies\n";
    for (const auto& pair : frequencyMap) {
        std::cout << std::left << std::setw(15) << pair.first << " " << pair.second << "\n";
    }
}

void GroceryTracker::PrintHistogram() const {
    std::cout << "\nHistogram\n";
    for (const auto& pair : frequencyMap) {
        std::cout << std::left << std::setw(15) << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void GroceryTracker::WriteBackup(const std::string& outFile) const {
    std::ofstream out(outFile);
    if (!out) {
        std::cerr << "Could not write backup file.\n";
        return;
    }
    for (const auto& pair : frequencyMap) {
        out << pair.first << " " << pair.second << "\n";
    }
    out.close();
}