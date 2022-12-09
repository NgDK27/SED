#include <iostream>

using namespace std;
class House
{
private:
    string location;
    string description;
    string listedStart;
    string listedEnd;
    bool isListed = false;
    double requiredRating;
    int cosumingPoints;
    vector<int> scores;
    vector<string> comments;

public:
    House() {}
    House(string location, string description)
    {
        this->location = location;
        this->description = description;
    }
    friend class Member;
};