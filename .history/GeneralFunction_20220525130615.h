#ifndef GENERALFUNCTION_H
#define GENERALFUNCTION_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Member.h"
using namespace std;

vector<Member> members;
Member *currentMember;

void getData(string path);
Member splitData(string data);
string getUserData(string data, string type, bool isHouse);
bool login();
bool login();
#endif