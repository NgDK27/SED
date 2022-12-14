#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../House/House.cpp"
#include "../Utils/Time.cpp"
#include "../Request/Request.cpp"

#ifndef MEMBER
#define MEMBER
using namespace std;

class Member
{
private:
    string userName;
    string fullName;
    string password;
    string phoneNumber;
    int creditPoints;
    int numberOfTimeRated;
    double ratingScore;
    House house;

    vector<Member> *allMembers;
    vector<Request> *allRequests;

public:
    Member() {}

    Member(string userName, string fullName, string password, string phoneNumber, int creditPoints, int numberOfTimeRated, double ratingScore, House house)
    {
        this->userName = userName;
        this->fullName = fullName;
        this->password = password;
        this->phoneNumber = phoneNumber;
        this->creditPoints = creditPoints;
        this->numberOfTimeRated = numberOfTimeRated;
        this->ratingScore = ratingScore;
        this->house = house;
    }

    string toString()
    {
        return this->userName + "," + this->fullName + "," + this->password + "," + this->phoneNumber + "," + to_string(this->creditPoints) + "," + this->house.location + "," + this->house.description + "," + to_string(this->house.isListed) + "," + this->house.listedStart + "," + this->house.listedEnd + "," + this->house.occupiedStart + "," + this->house.occupiedEnd + "," + this->house.occupierUsername + "," + to_string(this->house.requiredRating) + "," + to_string(this->house.cosumingPoints) + "," + to_string(this->ratingScore) + "," + to_string(this->numberOfTimeRated) + "," + to_string(this->house.ratingScore) + "," + to_string(this->house.numberOfTimeRated);
    }

    Member *memberExist(string usernameInput)
    {
        for (Member &member : *this->allMembers)
        {
            if (member.userName == usernameInput)
            {
                return &member;
            }
        }
        return nullptr;
    }

    string getFullName()
    {
        return this->fullName;
    }

    bool verifyPassword(string password)
    {
        if (password == this->password)
        {
            return true;
        }
        cout << "Incorrect password, try again" << endl
             << endl;
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
    }

    void updateHouse()
    {
        cout << "1: Location" << endl;
        cout << "2: Description" << endl;
        cout << "0: Back" << endl;
        cout << endl;
        cout << "Note: to update listing date, you can unlist your current one and list it again" << endl;
        cout << endl;
        cout << "Select a field to update: ";
        int userInput;
        cin >> userInput;
        cout << endl;
        if (userInput == 0)
        {
            return;
        }
        else if (userInput == 1)
        {
            string location;
            cout << "1: Ha Noi   2: Sai Gon   3: Hue" << endl;
            cout << "Enter the new location of your house: ";
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
            this->house.location = location;
        }
        else if (userInput == 2)
        {
            string description;
            cout << "Enter the new description: ";
            getline(cin >> ws, description);
            this->house.description = description;
        }
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

    void viewMyHouseInfo()
    {
        Time time;
        if (!this->haveHouse())
        {
            cout << "You have not added a house yet, try adding one" << endl;
            return;
        }
        cout << "YOUR HOUSE INFO" << endl;
        cout << "Location: " << this->house.location << endl;
        cout << "Description: " << this->house.description << endl;
        cout << "House rating score: " << this->house.ratingScore << " ";
        if (this->numberOfTimeRated == 0)
        {
            cout << "(This is because you have not been rated yet, so don't worry)" << endl;
        }
        else
        {
            cout << endl;
        }
        cout << "Available time: ";
        if (this->house.isListed)
        {
            cout << this->house.listedStart << " - " << this->house.listedEnd << endl;
            cout << "Days available: " << time.checkDifTime(this->house.listedStart, this->house.listedEnd) << endl;
        }
        else
        {
            cout << "None";
        }
        cout << endl
             << endl;
    }

    void viewMyInfo()
    {
        cout << "YOUR INFO" << endl;
        cout << "Name: " << this->fullName << endl;
        cout << "Phone number: " << this->phoneNumber << endl;
        cout << "Credit points: " << this->creditPoints << endl;
        cout << "Rating scores: " << this->ratingScore << " ";
        if (this->numberOfTimeRated == 0)
        {
            cout << "(This is because you have not been rated yet, so don't worry)" << endl;
        }
        else
        {
            cout << endl;
        }
        cout << "Location: " << this->house.location << endl;
        cout << endl;
    }

    void viewCommentsOfMyHouse()
    {
        if (this->house.comments.size() == 0)
        {
            cout << "You have no reviews" << endl
                 << endl;
            return;
        }
        cout << "REVIEWS OF YOUR HOUSE: " << endl;
        for (int i = 0; i < this->house.comments.size(); i++)
        {
            string currentComment = this->house.comments.at(i);
            cout << currentComment << endl;
        }
        cout << endl;
    }

    void searchForSuitableHouses()
    {
        string location;
        cout << "1: Ha Noi   2: Sai Gon   3: Hue" << endl;
        cout << "Enter the location you want to search: ";
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
        bool found = false;
        Time time;
        for (Member member : (*this->allMembers))
        {

            if (member.userName == this->userName)
            {
                continue;
            }
            if (member.house.location == location && member.house.isListed && (this->ratingScore >= member.house.requiredRating || this->numberOfTimeRated == 0))
            {
                printf("%s have a house in %s \n", member.fullName.c_str(), member.house.location.c_str());
                cout << "Description: " << member.house.description << endl;
                printf("Available time range: %s - %s \n", member.house.listedStart.c_str(), member.house.listedEnd.c_str());
                cout << "Days available: " << time.checkDifTime(member.house.listedStart, member.house.listedEnd) << endl;
                cout << "House rating score: ";
                if (member.house.numberOfTimeRated == 0)
                {
                    cout << "this house has never been rated" << endl;
                }
                else
                {
                    cout << member.house.ratingScore << endl;
                }
                cout << "His/her username: " << member.userName << endl;
                cout << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "There is no house available for your criteria" << endl
                 << endl;
        }
    }

    void makeARequest()
    {
        cout << "To make a request, you must know the username of the owner, your start date and end date" << endl;
        cout << "You should also make sure that you have verified the information of the owner (Location or maybe check their review)" << endl;
        cout << "If you do not have the required information, it is recommended that you go back and select Search for houses (6)" << endl;
        cout << endl;
        cout << "1: I would like to proceed" << endl;
        cout << "2: Go back" << endl;
        cout << endl;
        cout << "Your choices: ";
        int userInput;
        cin >> userInput;
        cout << endl;
        if (userInput == 2)
        {
            return;
        }
        if (userInput != 1)
        {
            cout << "Invalid input, try again" << endl;
            return;
        }
        string ownerUsername;
        string startDate;
        string endDate;
        cout << "Username of the owner: ";
        getline(cin >> ws, ownerUsername);
        cout << endl;

        Member *owner = memberExist(ownerUsername);

        if (owner == nullptr)
        {
            cout << "User not found, please check your input again !" << endl
                 << endl;
            return;
        }

        // Check if request already been made

        for (Request request : *allRequests)
        {
            if (request.usernameOfOccupier == this->userName && request.usernameOfOwner == ownerUsername)
            {
                cout << "You already made a request to this owner !!!" << endl
                     << endl;
                return;
            }
        }

        // Check if this house is listed

        bool isReallyListed = owner->house.isListed;

        if (!isReallyListed)
        {
            cout << "This user did not list their house for exchange" << endl
                 << endl;
            return;
        }

        cout << "Their house is available during: " << owner->house.listedStart << " - " << owner->house.listedEnd << endl;
        cout << "Start date (DD/MM/YYYY): " << endl;
        getline(cin >> ws, startDate);
        cout << endl;
        cout << "End date (DD/MM/YYYY): " << endl;
        getline(cin >> ws, endDate);
        cout << endl;

        Time time;
        string listedStartDate = owner->house.listedStart;
        string listedEndDate = owner->house.listedEnd;

        if (!(time.checkDifTime(startDate, listedStartDate) <= 0 && time.checkDifTime(endDate, listedEndDate) >= 0))
        {
            cout << "Invalid time range" << endl
                 << endl;
            return;
        }

        (*(this->allRequests)).push_back(Request(ownerUsername, this->userName, startDate, endDate, "pending"));
        cout << "Successfully make a request to " << ownerUsername << endl
             << endl;
    }

    void checkForMyRequest()
    {
        bool found = false;
        for (Request request : *this->allRequests)
        {
            if (request.usernameOfOwner == this->userName && request.status == "pending")
            {
                cout << "Request from: " << request.usernameOfOccupier << endl;
                cout << "Date: " << request.requestStartDate << " - " << request.requestEndDate << endl
                     << endl;
                found = true;
            }
        }

        if (!found)
        {
            cout << "There is no request coming to you" << endl
                 << endl;
        }
    }

    void acceptRequest()
    {
        cout << "To accept a request, you must enter the username of the one you want to accept" << endl;
        cout << "If you do not have it, please check your incoming request by using (8)" << endl
             << endl;
        cout << "1: I would like to proceed (reject all others)" << endl;
        cout << "2: Go back" << endl
             << endl;
        cout << "Your choice: ";
        int userInput;
        cin >> userInput;
        cout << endl;
        if (userInput == 2)
        {
            return;
        }
        if (userInput != 1)
        {
            cout << "Invalid input, please check again" << endl
                 << endl;
        }

        string usernameOfRequest;
        cout << "Enter the username of whom you want to accept: ";
        getline(cin >> ws, usernameOfRequest);

        bool found = false;
        for (Request &request : *allRequests)
        {
            if (request.usernameOfOccupier == usernameOfRequest && request.usernameOfOwner == this->userName)
            {
                this->house.occupierUsername = usernameOfRequest;
                this->house.occupiedStart = request.requestStartDate;
                this->house.occupiedEnd = request.requestEndDate;
                request.status = "accepted";
                found = true;
                cout << "Successfully accept request of: " << usernameOfRequest << endl
                     << endl;

                // Reject other request to this owner
                for (Request &request : *allRequests)
                {
                    if (request.usernameOfOwner == this->userName && request.status != "accepted")
                    {
                        this->house.occupierUsername = usernameOfRequest;
                        this->house.occupiedStart = request.requestStartDate;
                        this->house.occupiedEnd = request.requestEndDate;
                        request.status = "rejected";
                        break;
                    }
                }
                break;
            }
        }

        if (!found)
        {
            cout << "No request of: " << usernameOfRequest << " found" << endl;
            cout << "Please check again" << endl;
        }
    }

    void memberMenu(vector<Member> &allMembers, vector<Request> &allRequests)
    {
        this->allMembers = &allMembers;
        this->allRequests = &allRequests;
        while (true)
        {
            cout << "1: List/ Unlist your house" << endl;
            cout << "2: View your info" << endl;
            cout << "3: View your house info" << endl;
            cout << "4: View your house reviews" << endl;
            if (!this->haveHouse())
            {
                cout << "5: Add your house" << endl;
            }
            else
            {
                cout << "5: Update your house info" << endl;
            }
            cout << "6: Search for houses" << endl;
            cout << "7: Request for a house" << endl;
            cout << "8: Check request of your house" << endl;
            cout << "9: Accept a request" << endl;
            cout << "0: Exit" << endl;
            cout << "Enter your choice: ";
            int userInput;
            cin >> userInput;
            cout << endl;
            if (userInput == 0)
            {
                cin.clear();
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
            else if (userInput == 2)
            {
                this->viewMyInfo();
            }
            else if (userInput == 3)
            {
                this->viewMyHouseInfo();
            }
            else if (userInput == 4)
            {
                this->viewCommentsOfMyHouse();
            }
            else if (userInput == 5)
            {
                if (!this->haveHouse())
                {
                    this->addHouse();
                }
                else
                {
                    this->updateHouse();
                }
            }
            else if (userInput == 6)
            {
                this->searchForSuitableHouses();
            }
            else if (userInput == 7)
            {
                this->makeARequest();
            }
            else if (userInput == 8)
            {
                this->checkForMyRequest();
            }
            else if (userInput == 9)
            {
                this->acceptRequest();
            }
        }
    }
    friend class System;
};
#endif