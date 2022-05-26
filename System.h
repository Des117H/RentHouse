#ifndef SYSTEM_H
#define SYSTEM_H
#include <fstream>
#include "Member.h"
#include "Admin.h"

class System {
    public:
        vector<Member> members;
        vector<Admin> admins;
        Member *currentMember;
        System(string path);
        void initialize(string path);
        void getData(string path);
        Member splitData(string data);
        string getUserData(const string& type, bool isHouse);
        bool login();
        bool adminLogin();
        bool signup();
        void logout();
        void showHouseShort();
        void showHouseFull();
        void displayUsersInformation();
        void listHouse();
        void unListHouse();
        void houseList();
        bool isLeapYear(int year);
        bool findHouse();
        void sendRequest();
        void viewRequest();
        void acceptRequest();
        void mainPage();
        void guestPage();
        void memberPage();
        void adminPage();
        string getDay();
        void saveData();
};

bool isNumber(const string& str);

#endif