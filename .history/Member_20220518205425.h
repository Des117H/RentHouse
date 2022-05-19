#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <vector>
#include "Date.h"
using namespace std;

class Member;

class House {
    private:
        double consumptPoint = 0;
        string location;
        string description;
        bool available = false;
        Date startDay;
        Date endDay;
        vector<Member> occupiers;
    public:
        House() {};
        House(string location, string description);
        void show_info();
        void set_available();
        void show_ratings();
        void show_short_info();

        //getter method
        string getLocation();
        string getDescription();
        bool getAvailable();
        string getStartDay();
        string get_enddate();
        int get_start_day_rata();
        int get_end_day_rata();
        vector <Member> get_occupiers();

        //setter method
        void set_info(double houserate,double min_occ_rate, 
        string loca, string des, bool avail,string startdate,string enddate);
        void set_location(string location);
        void set_descrition(string des);
        void add_occupier(Member occupier);
};

class Member {
    private:
        int creditPoints;
        string userName;
        string fullName;
        string phoneNumber;
        string pwd;
        double own_rating_score;
        House own_house;
        House rent_house;
    public:
        Member(){};
        //methods
        void show_info();
        void set_info(int creditPoints, string userName, string fullName, 
        string phoneNumber, string pwd);
        void list_house();
        void show_requests();
        void show_house_ratings();

        //getter methods
        int getCreditPoints();
        string getPassword();
        House getOwnerHouse();
        string getUserName();
        string getFullName();
        string getPhoneNumber();
        bool get_house_avail();
        void return_house();

        //setter
        void setCreditPoints(int creditPoints);
        void accept_request();
};

#endif