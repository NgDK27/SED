#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../House/House.cpp"

class Member
{
private:
    std::string userName;
    std::string fullName;
    std::string phoneNumber;
    int creditPoints;
    double ocupierRatingScores;
    House house;

public:
    Member() {}

    Member(std::string userName, std::string fullName, std::string phoneNumber, int creditPoints, double ocupierRatingScores, House house)
    {
        this->userName = userName;
        this->fullName = fullName;
        this->phoneNumber = phoneNumber;
        this->creditPoints = creditPoints;
        this->ocupierRatingScores = ocupierRatingScores;
        this->house = house;
    }

    void listHouse()
    {
        std::string startDate;
        std::string endDate;
        std::cout << "Please enter the start date of the listing (DD/MM/YY): ";
        std::getline(std::cin >> std::ws, startDate);
        std::cout << "Please enter the end date of the listing (DD/MM/YY): ";
        std::getline(std::cin >> std::ws, endDate);
        this->house.listedStart = startDate;
        this->house.listedEnd = endDate;
        std::cout << "Do you want to set the minimum required occupier rating (Y/N) ? ";
        char userInput;
        std::cin >> userInput;
        this->house.isListed = true;
        if (userInput == 'N')
        {
            this->house.requiredRating = -10;
        }
        else
        {
            std::cout << "Please enter the minimum required occupier rating: ";
            double requiredRating;
            std::cin >> requiredRating;
            this->house.requiredRating = requiredRating;
        }
        std::cout << std::endl;
        std::cout << "Successfully list your house during: " << this->house.listedStart << " - " << this->house.listedEnd << std::endl;
        if (userInput == 'Y')
        {
            std::cout << "With the the minimum required occupier rating: " << this->house.requiredRating << std::endl;
        }
    }

    void unlistHouse()
    {
        if (this->house.isListed)
        {
            std::cout << "Are you sure to unlist your house during " << this->house.listedStart << " - " << this->house.listedEnd << " (Y/N) ? ";
            char userInput;
            std::cin >> userInput;
            if (userInput == 'Y')
            {
                this->house.listedStart = "";
                this->house.listedEnd = "";
                this->house.isListed = false;
                std::cout << "Successfully unlisted your house" << std::endl;
            }
            return;
        }
        std::cout << "Your house has not been listed to be unlisted" << std::endl;
    }
};