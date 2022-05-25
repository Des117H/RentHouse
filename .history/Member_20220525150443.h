#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <vector>
#include <sstream>
#include "House.h"
using namespace std;

class Member {
    private:
        string username;
        string password;
        string fullName;
        string phoneNumber;
        int creditPoints;
        House ownHouse;
        Member *renter;
        Member *rentHouse;
    public:
        // Constructor
        Member(){};
        Member(string username,string password, string fullName, 
        string phoneNumber, int creditPoints, string location, string description);

        // General function
        void displayInformation();
        void displayRequest();
        void acceptRequest();
        void returnHouse(); 
        void reduceCreditPoints(int points);
        void addCreditPoints(int points);

        // Getter
        int getCreditPoints();
        string getUserName();
        string getPassword();
        string getFullName();
        string getPhoneNumber();
        House getOwnHouse();
        Member getRenter();
        Member getRentHouse();

        // Setter
        void setCreditPoints(int creditPoints);
        void setRenter(Member *renter);
        void setRentHouse(Member *rentHouse);
        void setHouseAvailable(bool available);
};

#endif