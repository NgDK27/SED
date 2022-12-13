#include <iostream>
#include <vector>
#include <string>
#include "./User/Member.h"
#include "./Request/Request.h"

using namespace std;

class System
{
public:
    vector<Member> allMembers;
    vector<Request> allRequests;

    System() {}

    void registerNewMember()
    {
        string userName;
        string fullName;
        string phoneNumber;
        string password;
        string location;
        string description;
        int consumingPoints;
        cout << "Enter your username: ";
        getline(cin >> ws, userName);
        cout << endl;
        cout << "Enter your fullname: ";
        getline(cin >> ws, fullName);
        cout << endl;
        cout << "Enter your password: ";
        getline(cin >> ws, password);
        cout << endl;
        cout << "Enter your phone number: ";
        getline(cin >> ws, phoneNumber);
        cout << endl;
        cout << "Do you have a house to exchange (Y/N) ? ";
        char userInput;
        cin >> userInput;
        cout << endl;
        if (userInput == 'Y')
        {
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
        }

        Member newMemeber(userName, fullName, password, phoneNumber, 500, 0, 0, House(location, description, consumingPoints, 0, 0));
        this->allMembers.push_back(newMemeber);
        cout << "Successfully register a member ( " << userName << " )" << endl;
        cout << endl;
    }

    vector<string> extractDataByLine(string line, char specifer = ',')
    {
        vector<string> data;
        string field = "";
        line += specifer;
        for (char ch : line)
        {
            if (ch == specifer)
            {
                data.push_back(field);
                field = "";
                continue;
            }
            field += ch;
        }
        return data;
    }

    void readData()
    {
        // Read user and their house data
        fstream fs;
        fs.open("./Data/user.txt", ios::in);
        if (fs.is_open())
        {
            string line;
            while (getline(fs, line))
            {
                if (line == "")
                {
                    break;
                }
                vector<string> extractedData = extractDataByLine(line);
                string username = extractedData.at(0);
                string fullname = extractedData.at(1);
                string password = extractedData.at(2);
                string phoneNumber = extractedData.at(3);
                int creditPoints = stoi(extractedData.at(4));
                string location = extractedData.at(5);
                string description = extractedData.at(6);
                int isListedInt = stoi(extractedData.at(7));
                bool isListed = false;
                if (isListedInt == 1)
                {
                    isListed = true;
                }
                string listedStart = extractedData.at(8);
                string listedEnd = extractedData.at(9);
                string occupiedStart = extractedData.at(10);
                string occupiedEnd = extractedData.at(11);
                string occupierUsername = extractedData.at(12);
                double requiredRating = stod(extractedData.at(13));
                int consumingPoint = stoi(extractedData.at(14));
                double ratingScoreOwner = stod(extractedData.at(15));
                int numberOfRatedTimeOwner = stoi(extractedData.at(16));
                double ratingScoreHouse = stod(extractedData.at(17));
                int numberOfRatedTimeHouse = stoi(extractedData.at(18));
                Member member(username, fullname, password, phoneNumber, creditPoints, numberOfRatedTimeOwner, ratingScoreOwner, House(location, description, isListed, listedStart, listedEnd, occupiedStart, occupiedEnd, occupierUsername, requiredRating, consumingPoint, numberOfRatedTimeHouse, ratingScoreHouse));
                for (int i = 19; i < extractedData.size(); i++)
                {
                    string prefix = extractedData.at(i).substr(0, 7);
                    if (prefix == "review:")
                    {
                        string comment = extractedData.at(i).substr(8, extractedData.at(i).length());
                        member.house.comments.push_back(comment);
                    }
                    else
                    {
                        string prefix = extractedData.at(i).substr(0, 8);
                        if (prefix == "request:")
                        {
                            string request = extractedData.at(i).substr(9, extractedData.at(i).length());
                            vector<string> requestField = extractDataByLine(request, ':');
                            Request newRequest(member.userName, requestField.at(0), requestField.at(1), requestField.at(2));
                            this->allRequests.push_back(newRequest);
                        }
                    }
                }

                this->allMembers.push_back(member);
            }
        }
    }

    void saveData()
    {
        // Save userData
        fstream fs;
        fs.open("./Data/user.txt", ios::out);
        if (fs.is_open())
        {
            for (Member member : this->allMembers)
            {
                fs << member.toString();
                for (Request request : this->allRequests)
                {
                    if (request.usernameOfOwner == member.userName)
                    {
                        string eachRequest = ",request: " + request.usernameOfOccupier + ":" + request.requestStartDate + ":" + request.requestEndDate;
                        fs << eachRequest;
                    }
                }
                fs << endl;
            }
        }
        fs.close();
    }

    void viewHousesForNonMember()
    {
        for (Member member : allMembers)
        {
            if (member.house.location.length() == 0)
            {
                continue;
            }
            printf("%s have a house in %s \n", member.fullName.c_str(), member.house.location.c_str());
            cout << "Description: " << member.house.description << endl;
            cout << endl;
        }
    }

    int findMemberIndex(string username)
    {
        for (int i = 0; i < this->allMembers.size(); i++)
        {
            Member currentMember = this->allMembers.at(i);
            if (currentMember.userName == username)
            {
                return i;
            }
        }

        cout << "Username not found" << endl
             << endl;
        return -1;
    }

    friend class Member;
    friend class Time;
};

int main()
{
    System app;
    app.readData();
    cout << "EEET2482/COSC2082 ASSIGNMENT" << endl;
    cout << "VACATION HOUSE EXCHANGE APPLICATION" << endl
         << endl;
    cout << "Instructors: Mr. Linh Tran & Phong Ngo" << endl;
    cout << "Group: Deo Nho" << endl;
    cout << "sXXXXXXX, Student Name" << endl;
    cout << "sXXXXXXX, Student Name" << endl;
    cout << "sXXXXXXX, Student Name" << endl;
    cout << "sXXXXXXX, Student Name" << endl;
    cout << endl;
    while (true)
    {
        cout << "Use the app as 1. Guest   2. Member   3. Admin   0. Quit (Must use this for the program to update data)" << endl
             << endl;
        cout << "Enter your choice: ";
        int userInput;
        cin >> userInput;
        cout << endl;
        if (userInput == 1)
        {
            while (true)
            {
                cout << "1: Register" << endl;
                cout << "2: View houses" << endl;
                cout << "0: Back" << endl
                     << endl;
                cout << "Enter your choice: ";
                cin >> userInput;
                cout << endl;
                if (userInput == 0)
                {
                    break;
                }
                else if (userInput == 1)
                {
                    app.registerNewMember();
                }
                else if (userInput == 2)
                {
                    app.viewHousesForNonMember();
                }
            }
        }

        else if (userInput == 2)
        {
            string userName;
            string password;
            cout << "Enter your username: ";
            getline(cin >> ws, userName);
            cout << "Enter your password: ";
            getline(cin >> ws, password);
            cout << endl;
            int existedMemberIndex = app.findMemberIndex(userName);
            if (existedMemberIndex >= 0)
            {
                if (app.allMembers.at(existedMemberIndex).verifyPassword(password))
                {
                    cout << "Welcome, " << app.allMembers.at(existedMemberIndex).getFullName() << endl;
                    app.allMembers.at(existedMemberIndex)
                        .memberMenu(app.allMembers, app.allRequests);
                }
            }
        }

        else if (userInput == 3)
        {
            cout << "Admin stuff" << endl;
        }

        else if (userInput == 0)
        {
            app.saveData();
            cout << "Goodbye" << endl;
            return -1;
        }

        else
        {
            cout << "Invalid input, try one of the above" << endl;
        }
    }
}