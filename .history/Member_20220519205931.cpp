#include "Member.h"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

Member::Member(int creditPoints, string username, string fullName, 
        string phoneNumber, string password, House *ownHouse){
        this->creditPoints = creditPoints;
        this->username = username;
        this->fullName = fullName;
        this->phoneNumber = phoneNumber;
        this->password = password;
        this->ownHouse = ownHouse;
    }

void Member::displayInformation(){
    cout<< "[ User name: "<< this->username <<"\n"
        << "Full name: "<< this->fullName <<"\n"
        <<"Credit: "<< this->creditPoints << "\n"
        <<"\nHouse: ";
        // this->ownHouse.show_info();
}
void Member::displayRequest(){
    cout << "\nCurrent requests: " << std::endl;
    int i = 1;
    // for(Request r: this->requests){
    //     cout << i << ". ";
    //     r.show_req();
    //     i++;
    // }
}
// void Member::reset_requests(){
//     this->requests.clear();
// }
void Member::reduceCreditPoints(int points){
    this->creditPoints -= points;
};
void Member::addCreditPoints(int points){
    this->creditPoints += points;
};

//getter method
int Member::getCreditPoints(){
    return this->creditPoints;
}
string Member::getUserName(){
    return this->username;
}
string Member::getPassword(){
    return this->password;
}
string Member::getFullName(){
    return this->fullName;
}
string Member::getPhoneNumber(){
    return this->phoneNumber;
}
House Member::getOwnHouse(){
    return this->ownHouse;
}
Member* Member::getRenter(){
    return this->renter;
};
Member* Member::getRentHouse(){
    return this->rentHouse;
};

// vector <Request>Member:: get_req_list(){
//     return this->requests;
// }
void Member::list_house(){
    if(this->ownHouse.get_available() == 1){
        this->requests.clear();
    }
}

//setter
void Member::setCreditPoints(double creditPoints){
    this->creditPoints = creditPoints;
}
// void Member::set_request(Request req){
//     this->requests.push_back(req);
// }
void Member::setRenter(Member *renter){
    this->renter = renter;
};
void Member::setRentHouse(Member *rentHouse){
    this->rentHouse = rentHouse;
};
void Member::setHouseAvailable(bool available){
    this->own_house.set_house_available(available);
}
