#include <iostream>
#include <vector>

#ifndef HOUSE
#define HOUSE
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
    string occupierUsername;
    bool isListed;
    double requiredRating;
    int cosumingPoints;
    int numberOfTimeRated;
    double ratingScore;
    vector<string> comments;

public:
    House() {}
    House(string location, string description, int consumingPoints, int numberOfTimeRated, double ratingScore)
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
        this->numberOfTimeRated = numberOfTimeRated;
        this->ratingScore = ratingScore;
    }

    House(string location, string description, bool isListed, string listedStart, string listedEnd, string occupiedStart, string occupiedEnd, string occupierUsername, double requiredRating, int cosumingPoints, int numberOfTimeRated, double ratingScore)
    {
        this->location = location;
        this->description = description;
        this->isListed = isListed;
        this->listedStart = listedStart;
        this->listedEnd = listedEnd;
        this->occupiedStart = occupiedStart;
        this->occupiedEnd = occupiedEnd;
        this->occupierUsername = occupierUsername;
        this->requiredRating = requiredRating;
        this->cosumingPoints = cosumingPoints;
        this->numberOfTimeRated = numberOfTimeRated;
        this->ratingScore = ratingScore;
    }

    friend class Member;
    friend class System;
};

#endif