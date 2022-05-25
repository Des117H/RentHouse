#ifndef HOUSE_H
#define HOUSE_H
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class House {
    private:
        int consumePoint = 0;
        string address;
        string city;
        string description;
        bool available = false;
        string startDay;
    public:
        // Constructor
        House();
        House(string address, string city, string description);
        House(const House& t);

        // General functions
        void showFullInformation();
        void showShortInformation();
        void listHouse(int consumePoint, string startDay);
        void unList();

        // Getter
        int getConsumePoint();
        string getAddress();
        string getCity();
        string getDescription();
        bool getAvailable();
        string getStartDay();

        // Setter
        void setConsumePoint(int consumePoint);
        void setDayAvailable(string startDay);
        void setAddress(string address);
        void setCity(string city);
        void setDescription(string description);
        void setAvailable(bool available);
};

#endif