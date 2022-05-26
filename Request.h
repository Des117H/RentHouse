#include <iostream>
#ifndef REQUEST_H
#define REQUEST_H
using namespace std;
class Request{
    //status -1: reject, 0: Pending, 1:Accepted
    int status{};
    string renterName;
    string startDay;
    public:

    Request() {};
    Request(string renterName, string startDay);
    //getter
    string getRenterName();
    string getStartDay();
    int getStatus();

    //setter
    void setRenterName(string renterName);
    void setStartDay(string startDay);
    void setStatus(int status);
    
    void showRequest();
};

#endif