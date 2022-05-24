#include "Member.h"

House(string location, string description);

House& operator=(House other)
{
    this->consumePoint = other.consumePoint;
    this->location = other.location;
    this->description = other.description;
    this->available = other.available;
    this->startDay = other.startDay;
    this->endDay = other.endDay;
    return *this;
}

// General functions
void showFullInformation();
void showShortInformation();

// Getter
string getLocation();
string getDescription();
bool getAvailable();
string getStartDay();
string getEndDay();

// Setter
void setDayAvailable(string startDay, string endDay);
void setLocation(string location);
void setDescription(string des);
void setAvailable(bool available);