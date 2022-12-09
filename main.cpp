#include <iostream>
#include <vector>
#include "./User/Member.cpp"
#include "./Rating/Rating.cpp"

using namespace std;
class System
{
public:
    vector<Member> allMembers;
    vector<Rating> allRating;

    System() {}

    void registerNewMember()
    {
        string userName;
        string fullName;
        string phoneNumber;
        string password;
        string location;
        string description;
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
        cout << endl;
        char userInput;
        cin >> userInput;
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
        }

        Member newMemeber(userName, fullName, password, phoneNumber, 500, House(location, description));
        this->allMembers.push_back(newMemeber);
        cout << "Successfully register a member ( " << userName << " )" << endl;
        cout << endl;
    }
    void readData() {}
    void saveData()
    {
        // Save userData
        fstream fs;
        fs.open("./Data/user.txt", ios::app);
        if (fs.is_open())
        {
            for (Member member : allMembers)
            {
                fs << member.toString() << endl;
            }
        }
        fs.close();
    }
};

int main()
{
    System app;
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

        cout << "Use the app as 1. Guest   2. Member   3. Admin   0. Quit" << endl
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
                cout << "2: View all houses" << endl;
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