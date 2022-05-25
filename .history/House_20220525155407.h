#ifndef HOUSE_H
#define HOUSE_H
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class House {
    private:
        double consumePoint = 0;
        string location;
        string description;
        bool available = false;
        string startDay;
    public:
        // Constructor
        House();
        House(string location, string description);
        House(const House& t);

        // General functions
        void showFullInformation();
        void showShortInformation();
        void listHouse(int consumePoint, string startDay);

        // Getter
        string getLocation();
        string getDescription();
        bool getAvailable();
        string getStartDay();

        // Setter
        void setConsumePoint(int consumePoint);
        void setDayAvailable(string startDay);
        void setLocation(string location);
        void setDescription(string description);
        void setAvailable(bool available);
};

#endif