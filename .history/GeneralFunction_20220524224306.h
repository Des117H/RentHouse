#ifndef GENERALFUNCTION_H
#define GENERALFUNCTION_H
#include <iostream>
#include <vector>
#include "Member.h"
using namespace std;

vector<Member> members;
Member *currentMember;

void getData(string path);

bool login();
#endif