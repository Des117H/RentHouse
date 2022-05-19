#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <vector>
#include "Date.h"
using namespace std;

class House;

class Member {
    private:
        int creditPoints;
        string username;
        string fullName;
        string phoneNumber;
        string password;
        double own_rating_score;
        House own_house;
        House rent_house;
    public:
        // Constructor
        Member(){};
        void Member(int creditPoints, string username, string fullName, 
        string phoneNumber, string password);

        // General function
        void show_info();
        void list_house();
        void show_requests();
        void show_house_ratings();
        void accept_request();

        // Getter
        int getCreditPoints();
        string getPassword();
        House getOwnerHouse();
        string getUserName();
        string getFullName();
        string getPhoneNumber();
        void returnHouse();

        // Setter
        void setCreditPoints(int creditPoints);
};

#endif