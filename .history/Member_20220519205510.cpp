#include "Member.h"

#include "Member.h"
#include <iostream>
#include <vector>
#include <sstream>
using std::string;
using std::cout;
using std::cin;
using std::vector;
void Member::displayInformation(){
    cout<< "[ User name: "<< this->username <<"\n"
        << "Full name: "<< this->fullName <<"\n"
        <<"Credit: "<< this->creditPoints << "\n"
        <<"\nHouse: ";
        // this->ownHouse.show_info();
}
Member::Member(int creditPoints, string username, string fullName, 
        string phoneNumber, string password, House *ownHouse){
        this->creditPoints = creditPoints;
        this->username = username;
        this->fullName = fullName;
        this->phoneNumber = phoneNumber;
        this->password = password;
        this->ownHouse = ownHouse;
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
void Member::set_credits(double creds){
    this->creditPoints = creds;
}

void Member::set_request(Request req){
    this->requests.push_back(req);
}



void Member::set_occupier(Member *mem){
    this->occupier = mem;
};
void Member::set_occupying(Member *mem){
    this->occupying = mem;
};

string Member::get_occupier_name(){
   
    return this->occupier_name;

};
string Member::get_occupying_name(){
        return this->occupying_name;
}
void Member::add_rating(Rating rate){
    this->ratings.push_back(rate);
}
void Member::add_house_rating(Rating rate){
    this->own_house.add_rating(rate);
};
void Member::minus_credit(double ammount){
    this->creditPoints -= ammount;
};
void Member::add_credit(double ammount){
    this->creditPoints += ammount;
};

void Member::set_house_available(bool available){
    this->own_house.set_house_available(available);
}
