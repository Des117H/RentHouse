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
        string getUserData(string type, bool isHouse);
        bool login();
        bool signup();
        void showHouseData();
        void list
};

#endif