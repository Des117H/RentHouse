#include "House.h"


House::House()
{
    this->address = "";
    this->city = "";
    this->description = "";
    this->available = false;
    this->startDay = "";
    this->consumePoint = -1;
}

House::House(string address, string city, string description)
{
    this->address = move(address);
    this->city = move(city);
    this->description = move(description);
    this->available = false;
    this->startDay = "";
    this->consumePoint = -1;
}

House::House(const House& t)
{
    this->address = t.address;
    this->city = t.city;
    this->description = t.description;
    this->available = t.available;
    this->consumePoint = t.consumePoint;
    this->startDay = t.startDay;
}
// General functions
void House::showFullInformation()
{
    string str = "[";
    str += "Address: " + this->address + "\n";
    str += "City: " + this->city + "\n";
    str += "Description: " + this->description + "\n";
    str += "Available: ";
    if (this->available)
    {
        str += "yes\n";
        str += "Consuming points: " + to_string(this->consumePoint) + "\n";
        str += "Start day:" + this->startDay;
    }
    else
        str += "no";
    str += "]";
    cout << str << endl;
}

void House::showShortInformation()
{
    string str = "[\n";
    str += "Address: " + this->address + "\n";
    str += "City: " + this->city + "\n";
    str += "Description: " + this->description + "\n";
    str += "]";
    cout << str << endl;
}

void House::listHouse(int consumePoint, string startDay)
{
    setAvailable(true);
    setDayAvailable(move(startDay));
    setConsumePoint(consumePoint);
}

void House::unList()
{
    this->setAvailable(false);
    this->setDayAvailable("");
    this->setConsumePoint(-1);
}

// Getter
string House::getAddress()
{
    return this->address;
}

string House::getCity()
{
    return this->city;
}

string House::getDescription()
{
    return this->description;
}

bool House::getAvailable()
{
    return this->available;
}

string House::getStartDay()
{
    return this->startDay;
}

// Setter
void House::setConsumePoint(int consumePoint)
{
    this->consumePoint = consumePoint;
}

void House::setDayAvailable(string startDay)
{
    this->startDay = startDay;
}

void House::setAddress(string address)
{
    this->address = address;
}

void House::setCity(string city)
{
    this->city = city;
}

void House::setDescription(string description)
{
    this->description = description;
}

void House::setAvailable(bool available)
{
    this->available = available;
}

int House::getConsumePoint()
{
    return this->consumePoint;
}
