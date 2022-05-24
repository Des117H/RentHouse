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
        House *ownHouse;
        Member *renter;
        Member *rentHouse;
    public:
        // Constructor
        Member(){};
        Member(int creditPoints, string username, string fullName, 
        string phoneNumber, string password, House *ownHouse);

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

        // General functions
        void showFullInformation();
        void showShortInformation();

        // Getter
        string getLocation();
        string getDescription();
        bool getAvailable();
        Date getStartDay();
        Date getEndDay();

        // Setter
        void setDayAvailable(Date startDay, Date endDay);
        void setLocation(string location);
        void setDescription(string description);
        void setAvailable(bool available);
};

#endif