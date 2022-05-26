#include "Request.h"

Request::Request(string renterName, string startDay)
{
    this->status = 0;
    this->renterName = renterName;
    this->startDay = startDay;
}
//getter
string Request::getRenterName()
{
    return this->renterName;
}
string Request::getStartDay()
{
    return this->startDay;
}
int Request::getStatus()
{
    return this->status;
}

//setter
void Request::setRenterName(string renterName)
{
    this->renterName = renterName;
}
void Request::setStartDay(string startDay)
{
    this->startDay = startDay;
}
void Request::setStatus(int status)
{
    this->status = status;
}

void Request::showRequest()
{
    string str = "[";
    str += "Start day: " + this->startDay + ", ";
    str += "Renter's name: " + this->renterName + ", ";
    str += "Status: ";
    if (this->status < 0)
        str += "Rejected";
    else if (this->status > 0)
        str += "Accepted" ;
    else
        str += "Pending";
    str += "]";

    cout << str << endl;
}

string Request::to_string()
{
    string str = this->startDay + ", ";
    str += this->renterName + ", ";
    if (this->status < 0)
        str += "-1";
    else if (this->status > 0)
        str += "1" ;
    else
        str += "0";

    return str;
}
