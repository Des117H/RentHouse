#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class House;

class Member {
    private:
        string username;
        string password;
        string fullName;
        string phoneNumber;
        int creditPoints;
        House ownHouse = ;
        Member *renter;
        Member *rentHouse;
    public:
        // Constructor
        Member(){};
        Member(string username,string password, string fullName, 
        string phoneNumber, int creditPoints, House ownHouse);

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
        string startDay;
        string endDay;
    public:
        // Constructor
        House() {};
        House(string location, string description);
        House(const House& t)
        {
            this->location = t.location;
            this->description = t.description;
            this->available = t.available;
            this->consumePoint = t.consumePoint;
            this->startDay = t.startDay;
            this->endDay = t.endDay;
        }
 

        // General functions
        void showFullInformation();
        void showShortInformation();
        void listHouse(int consumePoint, string startDay, string endDay);

        // Getter
        string getLocation();
        string getDescription();
        bool getAvailable();
        string getStartDay();
        string getEndDay();

        // Setter
        void setDayAvailable(string startDay, string endDay);
        void setLocation(string location);
        void setDescription(string description);
        void setAvailable(bool available);
};

#endif