#include <iostream>
#include "./User/Member.cpp"

int main()
{
    std::cout << "EEET2482/COSC2082 ASSIGNMENT" << std::endl;
    std::cout << "VACATION HOUSE EXCHANGE APPLICATION" << std::endl
              << std::endl;
    std::cout << "Instructors: Mr. Linh Tran & Phong Ngo" << std::endl;
    std::cout << "Group: Deo Nho" << std::endl;
    std::cout << "sXXXXXXX, Student Name" << std::endl;
    std::cout << "sXXXXXXX, Student Name" << std::endl;
    std::cout << "sXXXXXXX, Student Name" << std::endl;
    std::cout << "sXXXXXXX, Student Name" << std::endl
              << std::endl;
    while (true)
    {
        std::cout << "Use the app as 1. Guest   2. Member   3. Admin   0. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        int userInput;
        std::cin >> userInput;
        if (userInput == 1)
        {
            std::cout << "Guest stuff" << std::endl;
        }

        else if (userInput == 2)
        {
            std::cout << "Member stuff" << std::endl;
        }

        else if (userInput == 3)
        {
            std::cout << "Admin stuff" << std::endl;
        }

        else if (userInput == 0)
        {
            std::cout << "Goodbye" << std::endl;
            return -1;
        }

        else
        {
            std::cout << "Invalid input, try one of the above" << std::endl;
        }
    }
}