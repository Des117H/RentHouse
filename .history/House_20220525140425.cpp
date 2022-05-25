#include "Member.h"

House::House(string location, string description){
    this->location = location;
    this->description = description;
    this->available = false;
}

// General functions
void House::showFullInformation(){
    cout << "in show full information" << endl;
    string str = ;
    cout << "[\nLocation: " + this->location + "\n";
    cout << str << endl;
    str += "Description: " + this->description + "\n";
    cout << str << endl;
    str += "Available: " + to_string(this->available) + "\n";
    cout << str << endl;
    if (this->available)
    {
        str += "Consuming points: " + to_string(this->consumePoint) + "\n";
        str += "Start day:" + this->startDay + "\n";
        str += "End day:" + this->endDay + "\n";
    }
    str += "]";
    cout << str << endl;
}

void House::showShortInformation(){
    string str = "[\n";
    str += "Location: " + this->location + "\n";
    str += "Description: " + this->description + "\n";
    str += "Available: " + to_string(this->available) + "\n";
    str += "]";
    cout << str << endl;
}

void House::listHouse(int consumePoint, string startDay, string endDay){
    setAvailable(true);
    setDayAvailable(startDay, endDay);
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

string House::getEndDay(){
    return this->endDay;
}

// Setter
void House::setDayAvailable(string startDay, string endDay){
    this->startDay = startDay;
    this->endDay = endDay;
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