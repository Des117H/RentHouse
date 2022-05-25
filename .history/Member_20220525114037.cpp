#include "Member.h"

Member::Member(string username, string fullName, string phoneNumber, 
string password,int creditPoints, House *ownHouse)
{
    this->creditPoints = creditPoints;
    this->username = username;
    this->fullName = fullName;
    this->phoneNumber = phoneNumber;
    this->password = password;
    this->ownHouse = ownHouse;
}

void Member::displayInformation()
{
    string tr = "[\n";
    str += "Location: " + this->username + "\n";
    str += "Location: " + this->fullName + "\n";
    str += "Location: " + this->creditPoints + "\n";
    str += "Location: " + this->location + "\n";
    cout << "[ User name: "<< this->username << endl
        << "Full name: "<< this->fullName << endl
        <<"Credit: "<< this->creditPoints << endl
        <<"House: ";
        this->ownHouse->showFullInformation();
}

void Member::displayRequest(){
    cout << "Current requests: " << endl;
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
    return *this->ownHouse;
}

Member Member::getRenter(){
    return *this->renter;
};

Member Member::getRentHouse(){
    return *this->rentHouse;
};

// vector <Request>Member:: get_req_list(){
//     return this->requests;
// }

//setter
void Member::setCreditPoints(int creditPoints){
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
    this->ownHouse->setAvailable(available);
}
