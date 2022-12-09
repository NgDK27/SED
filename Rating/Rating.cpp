#include <iostream>

using namespace std;
class Rating
{
    string houseOwnerUsername;
    string raterUsername;
    int scores;
    string comments;
    bool houseRating;

    Rating(string houseOwnerUsername, string raterUsername, int scores, string comments, bool houseRating)
    {
        this->houseOwnerUsername = houseOwnerUsername;
        this->raterUsername = raterUsername;
        this->scores = scores;
        this->comments = comments;
        this->houseRating = false;
    }

    string toString()
    {
        return this->houseOwnerUsername + "," + this->raterUsername + "," + to_string(scores) + "," + this->comments + "," + to_string(houseRating);
    }
};