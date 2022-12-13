#include <iostream>
#ifndef REQUEST
#define REQUEST

using namespace std;
class Request
{
private:
    string usernameOfOwner;
    string usernameOfOccupier;
    string requestStartDate;
    string requestEndDate;

public:
    Request(string usernameOfOwner, string usernameOfOccupier, string requestStartDate, string requestEndDate)
    {
        this->usernameOfOwner = usernameOfOwner;
        this->usernameOfOccupier = usernameOfOccupier;
        this->requestStartDate = requestStartDate;
        this->requestEndDate = requestEndDate;
    }
    string toString()
    {
        return "request: " + this->usernameOfOccupier + ":" + requestStartDate + ":" + requestEndDate;
    }
    friend class System;
    friend class Member;
};

#endif