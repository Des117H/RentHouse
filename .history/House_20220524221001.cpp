#include "Member.h"

House::House(string location, string description){
    this->location = location;
    this->description = description;
}

// General functions
void House::showFullInformation(){
    string str = "[\n";
    str += "Location: " + this->location + "\n";
    str += "Description: " + this->description + "\n";
    str += "Available: " + to_string(this->available) + "\n";
    str += "Consuming points: " + to_string(this->consumePoint) + "\n";
    if (this->available)
    {
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

void House::listHouse(bool available, int consumePoint, string startDay, string endDay){
    setAvailable(available);
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