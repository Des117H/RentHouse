#include "Member.h"
House::
House(string location, string description);

// General functions
void House::showFullInformation();
void House::showShortInformation();

// Getter
string House::getLocation();
string House::getDescription();
bool House::getAvailable();
string House::getStartDay();
string House::getEndDay();

// Setter
void House::setDayAvailable(string startDay, string endDay);
void House::setLocation(string location);
void setDescription(string des);
void setAvailable(bool available);