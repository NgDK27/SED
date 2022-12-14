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
    string status;

public:
    Request(string usernameOfOwner, string usernameOfOccupier, string requestStartDate, string requestEndDate, string status)
    {
        this->usernameOfOwner = usernameOfOwner;
        this->usernameOfOccupier = usernameOfOccupier;
        this->requestStartDate = requestStartDate;
        this->requestEndDate = requestEndDate;
        this->status = status;
    }
    string toString()
    {
        return "request: " + this->usernameOfOccupier + ":" + requestStartDate + ":" + requestEndDate + ":" + status;
    }
    friend class System;
    friend class Member;
};

#endif