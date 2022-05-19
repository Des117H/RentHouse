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

class House {
    private:
        double consumingPoint = 0;
        string location;
        string description;
        bool available = false;
        Date startDay;
        Date endDay;
        Member occupiers;
    public:
        // Constructor
        House() {};
        House(string location, string description);

        // General functions
        void showInformation();
        void setAvailable();
        void show_ratings();
        void show_short_info();

        // Getter
        string getLocation();
        string getDescription();
        bool getAvailable();
        string getStartDay();
        string getEndDay();
        Member get_occupiers();

        // Setter
        void set_info(string location, string description, bool available, 
        string startDay, string endDay);
        void setLocation(string location);
        void setDescription(string des);
        void addOccupier(Member occupier);
};

#endif