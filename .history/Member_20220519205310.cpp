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
void Member::get_full_house_info(){
    this->own_house.show_info();
}
double Member::get_own_rating_score(){
    return this->own_rating_score;
}
double Member::get_house_cons_point(){
    return this->own_house.get_conspoint();
};
int Member::get_start_value(){
    return this->own_house.get_start_day_rata();
}
int Member::get_end_value(){
    return this->own_house.get_end_day_rata();
}

vector<Rating> Member::get_ratings(){
    return this->ratings;
}
Member* Member::get_occupier(){
    return this->occupier;
};
Member* Member::get_occupying(){
    return this->occupying;
};

vector <Request>Member:: get_req_list(){
    return this->requests;
}
void Member::list_house(){
    int state = this->own_house.set_available();
    if(state == 1){
        this->requests.clear();
    }
}
//setter
void Member::set_own_rating_score(double score){
    this->own_rating_score = score;
}
void Member::set_house_rating_score(double score){
    this->own_house.set_house_rating_score(score);
};

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
