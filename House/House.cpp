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
    bool isListed;
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
        this->isListed = false;
        this->listedStart = "";
        this->listedEnd = "";
        this->requiredRating = 0;
        this->cosumingPoints = 0;
    }
    friend class Member;
};