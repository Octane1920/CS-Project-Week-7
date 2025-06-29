//Author: Kyle Altemeyer Date: 6/22/2025
#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <string>
#include <map>

class GroceryTracker {
public:
    GroceryTracker(const std::string& filename);

    int GetFrequency(const std::string& item) const;
    void PrintFrequencies() const;
    void PrintHistogram() const;
    void WriteBackup(const std::string& outFile) const;

private:
    std::map<std::string, int> frequencyMap;
    void LoadFile(const std::string& filename);
};

#endif