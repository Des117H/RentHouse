#include "Member.h"

House(string location, string description);

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