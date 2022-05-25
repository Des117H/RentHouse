#ifndef MEMBER_H
#define MEMBER_H
#include "House.h"
#include "Request.h"

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
        vector<Request> requests;
    public:
        // Constructor
        Member(){};
        Member(string username,string password, string fullName, 
        string phoneNumber, int creditPoints, string address, string city, string description);

        // General function
        void displayInformation();
        void displayRequest();
        void acceptRequest();
        void returnHouse(); 
        void reduceCreditPoints(int points);
        void addCreditPoints(int points);
        void listHouse(int consumePoint, string startDay);
        void unListHouse();
        void cleanRequests();

        // Getter
        int getCreditPoints();
        string getUserName();
        string getPassword();
        string getFullName();
        string getPhoneNumber();
        House getOwnHouse();
        Member getRenter();
        Member getRentHouse();
        vector<Request> getRequests();

        // Setter
        void setCreditPoints(int creditPoints);
        void setRenter(Member *renter);
        void setRentHouse(Member *rentHouse);
        void addRequests(Request request);
};

#endif