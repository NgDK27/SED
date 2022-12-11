#include <iostream>
#include <vector>

using namespace std;
class House
{
private:
    string location;
    string description;
    string listedStart;
    string listedEnd;
    string occupiedStart;
    string occupiedEnd;
    bool isListed;
    double requiredRating;
    int cosumingPoints;
    vector<int> scores;
    vector<string> comments;

public:
    House() {}
    House(string location, string description, int consumingPoints)
    {
        this->location = location;
        this->description = description;
        this->isListed = false;
        this->listedStart = "";
        this->listedEnd = "";
        this->occupiedStart = "";
        this->occupiedEnd = "";
        this->requiredRating = 0;
        this->cosumingPoints = consumingPoints;
    }

    House(string location, string description, bool isListed, string listedStart, string listedEnd, string occupiedStart, string occupiedEnd, double requiredRating, int cosumingPoints)
    {
        this->location = location;
        this->description = description;
        this->isListed = isListed;
        this->listedStart = listedStart;
        this->listedEnd = listedEnd;
        this->occupiedStart = occupiedStart;
        this->occupiedEnd = occupiedEnd;
        this->requiredRating = requiredRating;
        this->cosumingPoints = cosumingPoints;
    }

    friend class Member;
    friend class System;
};