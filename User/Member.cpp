#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../House/House.cpp"

using namespace std;

class Member
{
private:
    string userName;
    string fullName;
    string phoneNumber;
    int creditPoints;
    double ocupierRatingScores;
    House house;

public:
    Member() {}

    Member(string userName, string fullName, string phoneNumber, int creditPoints, double ocupierRatingScores, House house)
    {
        this->userName = userName;
        this->fullName = fullName;
        this->phoneNumber = phoneNumber;
        this->creditPoints = creditPoints;
        this->ocupierRatingScores = ocupierRatingScores;
        this->house = house;
    }

    void memberMenu()
    {
        while (true)
        {
            cout << "0: Exit" << endl;
            cout << "Enter your choice: ";
            int userInput;
            cin >> userInput;
            if (userInput == 0)
            {
                return;
            }
        }
    }

    void listHouse()
    {
        string startDate;
        string endDate;
        cout << "Please enter the start date of the listing (DD/MM/YY): ";
        getline(cin >> ws, startDate);
        cout << "Please enter the end date of the listing (DD/MM/YY): ";
        getline(cin >> ws, endDate);
        this->house.listedStart = startDate;
        this->house.listedEnd = endDate;
        cout << "Do you want to set the minimum required occupier rating (Y/N) ? ";
        char userInput;
        cin >> userInput;
        this->house.isListed = true;
        if (userInput == 'N')
        {
            this->house.requiredRating = -10;
        }
        else
        {
            cout << "Please enter the minimum required occupier rating: ";
            double requiredRating;
            cin >> requiredRating;
            this->house.requiredRating = requiredRating;
        }
        cout << endl;
        cout << "Successfully list your house during: " << this->house.listedStart << " - " << this->house.listedEnd << endl;
        if (userInput == 'Y')
        {
            cout << "With the the minimum required occupier rating: " << this->house.requiredRating << endl;
        }
    }

    void unlistHouse()
    {
        if (this->house.isListed)
        {
            cout << "Are you sure to unlist your house during " << this->house.listedStart << " - " << this->house.listedEnd << " (Y/N) ? ";
            char userInput;
            cin >> userInput;
            if (userInput == 'Y')
            {
                this->house.listedStart = "";
                this->house.listedEnd = "";
                this->house.isListed = false;
                cout << "Successfully unlisted your house" << endl;
            }
            return;
        }
        cout << "Your house has not been listed to be unlisted" << endl;
    }

    void viewAvailableHouse()
    {
    }
};