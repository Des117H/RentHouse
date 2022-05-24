#include "Member.h"

House::House(string location, string description){
    this->location = location;
    this->description = description;
}

// General functions
void House::showFullInformation(){

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

Date House::getStartDay(){
    return this->startDay;
}

Date House::getEndDay(){
    return this->endDay;
}

// Setter
void House::setDayAvailable(Date startDay, Date endDay){
    this->startDay = startDay;
    this->endDay = endDay;
}

void House::setLocation(string location){
    this->location = location;
}

void House::setDescription(string des){
    this->description = description
}

void House::setAvailable(bool available){

}