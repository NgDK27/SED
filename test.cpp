#include <iostream>
#include "./Utils/Time.cpp"

int main()
{
    Time time;
    cout << time.checkDifTime("01/01/2022", "01/02/2022") << endl;
}