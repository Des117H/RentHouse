#ifndef SYSTEM_H
#define SYSTEM_H
#include <fstream>
#include "Member.h"

class System {
    public:
        vector<Member> members;
        Member *currentMember;
        void getData(string path);
        Member splitData(string data);
        string getUserData(string data, string type, bool isHouse);
        bool login();
        bool signup();
};

#endif