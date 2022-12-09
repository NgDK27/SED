#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include "../House/House.cpp"

using namespace std;

class Member
{
private:
    string userName;
    string fullName;
    string password;
    string phoneNumber;
    int creditPoints;
    vector<int> scores;
    House house;

public:
    Member() {}

    Member(string userName, string fullName, string password, string phoneNumber, int creditPoints, House house)
    {
        this->userName = userName;
        this->fullName = fullName;
        this->password = password;
        this->phoneNumber = phoneNumber;
        this->creditPoints = creditPoints;
        this->house = house;
    }

    string toString()
    {
        return this->userName + "," + this->fullName + "," + this->password + "," + this->phoneNumber + "," + to_string(this->creditPoints) + "," + this->house.location + "," + this->house.description + "," + to_string(this->house.isListed) + "," + this->house.listedStart + "," + this->house.listedEnd + "," + this->house.occupiedStart + "," + this->house.occupiedEnd + "," + to_string(this->house.requiredRating) + "," + to_string(this->house.cosumingPoints);
    }

    bool verifyUser()
    {
        if (this->fullName.length() > 0)
        {
            return true;
        }
        return false;
    }

    bool haveHouse()
    {
        if (this->house.location.length() == 0)
        {
            return false;
        }

        return true;
    }

    void memberMenu()
    {
        while (true)
        {
            cout << "1: List/ Unlist your house" << endl;
            cout << "2: Search for houses" << endl;
            if (!this->haveHouse())
            {
                cout << "3: Add your house" << endl;
            }
            else
            {
                cout << "3: Update your house info" << endl;
            }
            cout << "0: Exit" << endl;
            cout << "Enter your choice: ";
            int userInput;
            cin >> userInput;
            cout << endl;
            if (userInput == 0)
            {
                return;
            }
            else if (userInput == 1)
            {
                if (this->house.isListed)
                {
                    this->unlistHouse();
                }
                else
                {
                    this->listHouse();
                }
            }
            else if (userInput == 3)
            {
                if (!this->haveHouse())
                {
                    this->addHouse();
                }
            }
        }
    }

    void addHouse()
    {
        string location;
        string description;
        int consumingPoints;
        cout << "1: Ha Noi   2: Sai Gon   3: Hue" << endl;
        cout << "Enter the location of your house: ";
        int locationInput;
        cin >> locationInput;
        if (locationInput == 1)
        {
            location = "Ha Noi";
        }
        else if (locationInput == 2)
        {
            location = "Sai Gon";
        }
        else if (locationInput == 3)
        {
            location = "Hue";
        }
        cout << endl;

        cout << "Enter the description of your house: ";
        getline(cin >> ws, description);
        cout << endl;

        cout << "Set consuming points for your house: ";
        cin >> consumingPoints;

        this->house.location = location;
        this->house.description = description;
        this->house.cosumingPoints = consumingPoints;

        cout << endl;
        cout << "Successfully add a house to " << this->userName << endl
             << endl;
        cout << this->toString() << endl;
    }

    void listHouse()
    {
        if (this->house.location.length() == 0)
        {
            cout << "You have not added a house yet, try adding one" << endl
                 << endl;
            return;
        }
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
        cout << endl;
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
                cout << endl;
            }
            return;
        }
        cout << "Your house has not been listed to be unlisted" << endl;
        cout << endl;
    }

    void viewAvailableHouse()
    {
    }

    friend class System;
};