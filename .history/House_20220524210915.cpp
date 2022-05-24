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
string getStartDay();
string getEndDay();

// Setter
void setDayAvailable(string startDay, string endDay);
void setLocation(string location);
void setDescription(string des);
void setAvailable(bool available);