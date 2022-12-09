#include <iostream>
class House
{
private:
    std::string location;
    std::string description;
    double houseRatingScores;
    std::string listedStart;
    std::string listedEnd;
    bool isListed = false;
    double requiredRating;
    int cosumingPoints;

public:
    House() {}
    House(std::string location, std::string description, double houseRatingScores)
    {
        this->location = location;
        this->description = description;
        this->houseRatingScores = houseRatingScores;
    }
    friend class Member;
};