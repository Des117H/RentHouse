#include "Member.h"

House::House(){
    this->location = "";
    this->description = "";
    this->available = false;
    this->startDay = "";
    this->consumePoint = -1;
}

House::House(string location, string description){
    this->location = location;
    this->description = description;
    this->available = false;
    this->startDay = "";
    this->consumePoint = -1;
}

House::House(const House& t)
{
    this->location = t.location;
    this->description = t.description;
    this->available = t.available;
    this->consumePoint = t.consumePoint;
    this->startDay = t.startDay;
}
// General functions
void House::showFullInformation(){
    string str = "[";
    str += "Location: " + this->location + "\n";
    str += "Description: " + this->description + "\n";
    str += "Available: ";
    if (this->available)
    {
        str += "yes\n";
        str += "Consuming points: " + to_string(this->consumePoint) + "\n";
        str += "Start day:" + this->startDay + "\n";
    }
    else
        str += "no";
    str += "]";
    cout << str << endl;
}

void House::showShortInformation(){
    string str = "[\n";
    str += "Location: " + this->location + "\n";
    str += "Description: " + this->description + "\n";
    str += "]";
    cout << str << endl;
}

void House::listHouse(int consumePoint, string startDay){
    setAvailable(true);
    setDayAvailable(startDay);
    setC
}

// Getter
string House::getLocation(){
    return this->location;
}

string House::getDescription(){
    return this->description;
}

bool House::getAvailable(){
    return this->available;
}

string House::getStartDay(){
    return this->startDay;
}

// Setter
void
void House::setDayAvailable(string startDay)
{
    this->startDay = startDay;
}

void House::setLocation(string location){
    this->location = location;
}

void House::setDescription(string description){
    this->description = description;
}

void House::setAvailable(bool available){
    this->available = available;
}