#ifndef GENERALFUNCTION_H
#define GENERALFUNCTION_H
#include <fstream>
#include "Member.h"
using namespace std;

void getData(string path);
Member splitData(string data);
string getUserData(string data, string type, bool isHouse);
bool login();
bool signup();
#endif