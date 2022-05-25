#ifndef SYSTEM_H
#define SYSTEM_H
#include <fstream>
#include "Member.h"

class System {
    public:
        vector<Member> members;
        Member *currentMember;
        System() {};
        void getData(string path);
        Member splitData(string data);
        string getUserData(const string& type, bool isHouse);
        bool login();
        bool signup();
        void showHouseShort();
        void showHouseFull();
        void listHouse();
        void unListHouse();
        bool isLeapYear(int year);
        void findHouse();
        void sendRequest();
        void viewRequest();
        void acceptRequest();
};

#endif