#include <iostream>
#include <vector>
#include "./User/Member.cpp"

using namespace std;
class System
{
public:
    vector<Member> allMembers;
    System() {}
    void registerNewMember()
    {
        string userName;
        string fullName;
        string password;
        string location;
        cout << "Enter your username: ";
    }
    void readData() {}
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
            cout << "Goodbye" << endl;
            return -1;
        }

        else
        {
            cout << "Invalid input, try one of the above" << endl;
        }
    }
}