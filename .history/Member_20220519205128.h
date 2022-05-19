#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <vector>
#include "Date.h"
using namespace std;

class House;

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
        Member(int creditPoints, string username, string fullName, 
        string phoneNumber, string password, House *ownHouse);

        // General function
        void displayInformation();
        void setHouseAvailable();
        void displayRequest();
        void AcceptRequest();
        void returnHouse();

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
        void getRenter(Member *renter);
        void getRentHouse(Member *rentHouse);
};

class House {
    private:
        double consumePoint = 0;
        string location;
        string description;
        bool available = false;
        Date startDay;
        Date endDay;
    public:
        // Constructor
        House() {};
        House(string location, string description);

        House& operator=(House other)
        {
            this->c
            this->location = other.location;
            return *this;
        }

        // General functions
        void showFullInformation();
        void showShortInformation();

        // Getter
        string getLocation();
        string getDescription();
        bool getAvailable();
        string getStartDay();
        string getEndDay();

        // Setter
        void setDayAvailable(string startDay, string endDay);
        void setLocation(string location);
        void setDescription(string des);
        void setAvailable(bool available);
};

#endif