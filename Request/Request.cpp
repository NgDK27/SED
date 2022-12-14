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
    int consumingPointPerDay;

public:
    Request(string usernameOfOwner, string usernameOfOccupier, string requestStartDate, string requestEndDate, string status, int consumingPointPerDay)
    {
        this->usernameOfOwner = usernameOfOwner;
        this->usernameOfOccupier = usernameOfOccupier;
        this->requestStartDate = requestStartDate;
        this->requestEndDate = requestEndDate;
        this->status = status;
        this->consumingPointPerDay = consumingPointPerDay;
    }
    string toString()
    {
        return "request: " + this->usernameOfOccupier + ":" + requestStartDate + ":" + requestEndDate + ":" + status;
    }
    friend class System;
    friend class Member;
};

#endif