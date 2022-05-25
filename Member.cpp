#include "Member.h"

#include <utility>

Member::Member(string username,string password, string fullName, 
        string phoneNumber, int creditPoints, string address, string city, string description)
{
    this->creditPoints = creditPoints;
    this->username = move(username);
    this->fullName = move(fullName);
    this->phoneNumber = move(phoneNumber);
    this->password = move(password);
    this->ownHouse = House(move(address), move(city), move(description));
}

void Member::displayInformation()
{
    string str = "[\n";
    str += "User name: " + this->username + "\n";
    str += "Full name: " + this->fullName + "\n";
    str += "Credit point: " + to_string(this->creditPoints) + "\n";
    str += "House:";
    cout << str << endl;
    
    this->ownHouse.showFullInformation();
    cout << "]" << endl;
}

void Member::displayRequest()
{
    cout << "Current requests: " << endl;
    int i = 1;
    // for(Request r: this->requests){
    //     cout << i << ". ";
    //     r.show_req();
    //     i++;
    // }
}

void Member::cleanRequests(){
    this->requests.clear();
}
void Member::reduceCreditPoints(int points)
{
    this->creditPoints -= points;
};

void Member::addCreditPoints(int points)
{
    this->creditPoints += points;
};

//getter method
int Member::getCreditPoints()
{
    return this->creditPoints;
}

string Member::getUserName()
{
    return this->username;
}

string Member::getPassword()
{
    return this->password;
}

string Member::getFullName()
{
    return this->fullName;
}

string Member::getPhoneNumber()
{
    return this->phoneNumber;
}

House Member::getOwnHouse()
{
    return this->ownHouse;
}

Member Member::getRenter()
{
    return *this->renter;
};

Member Member::getRentHouse()
{
    return *this->rentHouse;
};

vector<Request> Member:: getRequests(){
    return this->requests;
}

//setter
void Member::setCreditPoints(int creditPoints)
{
    this->creditPoints = creditPoints;
}

void Member::addRequests(Request request){
    this->requests.push_back(request);
}

void Member::setRenter(Member *renter)
{
    this->renter = renter;
};

void Member::setRentHouse(Member *rentHouse)
{
    this->rentHouse = rentHouse;
};

void Member::listHouse(int consumePoint, string startDay)
{
    this->ownHouse.setAvailable(true);
    this->ownHouse.setConsumePoint(consumePoint);
    this->ownHouse.setDayAvailable(startDay);
}

void Member::unListHouse()
{
    this->ownHouse.unList();
}


