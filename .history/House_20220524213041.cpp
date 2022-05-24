#include "Member.h"

House::House(string location, string description){
    this->location = location;
    this->description = description;
}

// General functions
void House::showFullInformation(){
    string str = "Location: " + this->location;
    str+= 
}

void House::showShortInformation(){

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