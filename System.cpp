#include "System.h"

bool System::login()
{
    while (true)
    {
        string username;
        string password;
        cout << "Enter username: ";
        fflush(stdin);
        cin >> username;
        for (Member member: members)
            if (username == member.getUserName())
            {
                cout << "Enter password: ";
                fflush(stdin);
                cin >> password;
                if (password == member.getPassword())
                {
                    cout << "Log in success." << endl;
                    return true;
                }
                else
                {
                    currentMember = nullptr;
                    cout << "Wrong password!!!" << endl;
                    cout << "Log in failed!!!" << endl;
                    return false;
                }
            }
        cout << "No user found." << endl;
    }
}

bool System::adminLogin()
{
    while (true)
    {
        string username;
        string password;
        cout << "Enter username: ";
        fflush(stdin);
        cin >> username;
        for (Admin admin: admins)
            if (username == admin.getUsername())
            {
                cout << "Enter password: ";
                fflush(stdin);
                cin >> password;
                if (password == admin.getPassword())
                {
                    cout << "Log in success." << endl;
                    return true;
                }
                else
                {
                    currentMember = nullptr;
                    cout << "Wrong password!!!" << endl;
                    cout << "Log in failed!!!" << endl;
                    return false;
                }
            }
    }
}

bool System::signup()
{
    bool isValid = true;
    string username;

    while (true)
    {
        cout << "Enter username: ";
        fflush(stdin);
        cin >> username;

        for (Member member: members)
        {
            if (username == member.getUserName())
            {
                isValid = false;
                break;
            }
        }
        if (isValid)
            break;
    }

    Member member = Member();

    if (isValid)
    {
        string password = getUserData("Password", false);
        string fullName = getUserData("Full Name", false);
        string phoneNumber = getUserData("Phone Number", false);
        string address = getUserData("Address", true);
        string city = getUserData("City", true);
        string description = getUserData("Description", true);

        member = Member(username, password, fullName, phoneNumber, 500, address, city, description);
        members.push_back(member);
        currentMember = &members.back();
    }

    return isValid;
}

string System::getUserData(const string &type, bool isHouse)
{
    string data;
    do
    {
        if (!isHouse)
            cout << "Enter " + type + ": ";
        else
            cout << "Enter house's " + type + ": ";

        fflush(stdin);
        getline(cin, data);
        if (data.empty())
        {
            cout << type << " cannot be empty." << endl;
            cout << "Please enter again." << endl;
        }
        else if (type == "City")
        {
            if (!data.compare("Ho Chi Minh") || !data.compare("Da Nang") || !data.compare("Ha Noi"))
                break;

            cout << "We support no city but Ho Chi Minh, Ha Noi and Da Nang." << endl;
            cout << "Please enter again." << endl;
        }
        else
            break;
    }
    while (true);

    return data;
}

void System::showHouseShort()
{
    if (members.empty())
    {
        cout << "There is no house." << endl;
        return;
    }
    for (Member member: members)
    {
        member.getOwnHouse().showShortInformation();
    }
}

void System::showHouseFull()
{
    if (members.empty())
    {
        cout << "There is no house." << endl;
        return;
    }
    int i = 1;
    for (Member member: members)
    {
        cout << "House " << i << "th: " << endl;
        i++;
        member.getOwnHouse().showFullInformation();
    }
}

void System::listHouse()
{
    string startDay = getDay();
    int consumePoint;
    cout << "Consume point: ";
    cin >> consumePoint;
    currentMember->listHouse(consumePoint, startDay);
}

void System::unListHouse()
{
    currentMember->unListHouse();
}

bool System::isLeapYear(int year)
{
    if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
        return true;

    return false;
}

void System::findHouse()
{
    string currentUserName = currentMember->getUserName();
    string city;

    cout << "Enter city you want to stay: ";
    fflush(stdin);
    getline(cin, city);

    string dayStay = getDay();

    for (Member member: members)
        if (currentUserName != member.getUserName())
            if (member.getOwnHouse().getCity() == city)
                if (member.getOwnHouse().getStartDay() == dayStay)
                    if (member.getOwnHouse().getConsumePoint() <= currentMember->getCreditPoints())
                        member.getOwnHouse().showShortInformation();
}

void System::sendRequest()
{
    showHouseFull();

    if (this->members.empty())
        return;

    int houseChoice;
    cout << "Enter the house's number: ";
    cin >> houseChoice;

    Request request = Request(currentMember->getUserName(), members[houseChoice - 1].getOwnHouse().getStartDay());
    members[houseChoice - 1].addRequests(request);
}

void System::viewRequest()
{
    if (currentMember->getRequests().empty())
    {
        cout << "No requests currently available." << endl;
        return;
    }

    int i = 0;
    for (Request request: currentMember->getRequests())
    {
        cout << "Request " << i << "th: " << endl;
        i++;
        request.showRequest();
    }
}

void System::acceptRequest()
{
    viewRequest();

    if (currentMember->getRequests().empty())
        return;

    int requestChoice;
    cout << "Enter the house's number: ";
    cin >> requestChoice;

    Request temp = currentMember->getRequests()[requestChoice];
    temp.setStatus(1);
    currentMember->cleanRequests();
    currentMember->addRequests(temp);
    for (auto &member: this->members)
    {
        if (temp.getRenterName() == member.getUserName())
        {
            int points = currentMember->getOwnHouse().getConsumePoint();
            currentMember->setRenter(&member);
            currentMember->addCreditPoints(points);
            member.setRentHouse(currentMember);
            member.addCreditPoints(0 - points);
        }
    }
}

void System::logout()
{
    this->currentMember == nullptr;
}

void System::mainPage()
{
    while (true)
    {
        string choice;
        cout << "Do you want to use as:\n" << "1. Guest\t2. Member\t3. Admin\t4. Exit" << endl;
        cout << "Enter your choice: ";
        fflush(stdin);
        getline(cin, choice);

        try
        {
            switch (stoi(choice))
            {
                case 1:
                    this->guestPage();
                    break;
                case 2:
                    this->memberPage();
                    break;
                case 3:
                    this->adminPage();
                    return;
                case 4:
                    this->saveData();
                    return;
                default:
                    cout << "Invalid input!!!" << endl;
                    break;
            }
        }
        catch (...)
        {
            cout << "Invalid input!!!" << endl;
        }
    }
}

void System::guestPage()
{
    while (true)
    {
        string choice;
        cout << "Do you want to:\n" << "1. View houses\t2. Sign up\t3. Exit" << endl;
        cout << "Enter your choice: ";
        fflush(stdin);
        getline(cin, choice);

        try
        {
            switch (stoi(choice))
            {
                case 1:
                    this->showHouseShort();
                    break;
                case 2:
                    this->signup();
                    this->memberPage();
                    break;
                case 3:
                    return;
                default:
                    cout << "Invalid input!!!" << endl;
                    break;
            }
        }
        catch (...)
        {
            cout << "Invalid input!!!" << endl;
        }


    }
}

void System::memberPage()
{
    if (!this->login())
        return;

    while (true)
    {
        string choice;
        this->currentMember->displayInformation();

        cout << "Do you want to:\n" << "1. View request\t2. Accept request\t3. Log out" << endl;
        cout << "Enter your choice: ";
        fflush(stdin);
        getline(cin, choice);

        try
        {
            switch (stoi(choice))
            {
                case 1:
                    this->currentMember->displayInformation();
                    break;
                case 2:
                    this->acceptRequest();
                    break;
                case 3:
                    return;
                default:
                    cout << "Invalid input!!!" << endl;
                    break;
            }
        }
        catch (...)
        {
            cout << "Invalid input!!!" << endl;
        }
    }


}

void System::adminPage()
{
    if (!this->adminLogin())
        return;

    while (true)
    {
        string choice;

        cout << "Do you want to:\n" << "1. View users\t2. Log out" << endl;
        cout << "Enter your choice: ";
        fflush(stdin);
        getline(cin, choice);

        try
        {
            switch (stoi(choice))
            {
                case 1:
                    this->displayUsersInformation();
                    break;
                case 2:
                    return;
                default:
                    cout << "Invalid input!!!" << endl;
                    break;
            }
        }
        catch (...)
        {
            cout << "Invalid input!!!" << endl;
        }
    }
}

void System::displayUsersInformation()
{
    if (members.empty())
    {
        cout << "There are no users." << endl;
        return;
    }

    int index = 0;
    for (Member member: members)
    {
        cout << "Member " << index << "th: " << endl;
        member.displayInformation();
        cout << "________________________________________" << endl;
    }
}

string System::getDay()
{
    int day, month, year;
    while (true)
    {
        cout << "Enter year (1980 - 2022): ";
        cin >> year;
        if (year >= 1980 && year <= 2022)
            break;
        else
            cout << "Wrong year!!!" << endl;
    }

    while (true)
    {
        cout << "Enter month (1 - 12): ";
        cin >> month;
        if (month >= 1 && month <= 12)
            break;
        else
            cout << "Wrong month!!!" << endl;
    }

    while (true)
    {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear(year) && month == 2)
            cout << "Enter day (1 - 29): ";
        else
            cout << "Enter day (1 - " + to_string(days[month - 1]) + "): ";
        cin >> day;
        if (isLeapYear(year) && month == 2)
            if (day >= 1 && day <= 29)
                break;
        if (day >= 1 && day <= days[month - 1])
            break;
        else
            cout << "Wrong day!!!" << endl;
    }

    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

void System::saveData()
{
    fstream fileout;
    fileout.open("output.txt", ios::out);
    if (!fileout)
    {
        cout << "Cannot open File";
        return;
    }

    for (Member member: members)
    {
        string str = member.getUserName() + ",";
        str += member.getFullName() + ",";
        str += to_string(member.getCreditPoints()) + ",";
        cout << "]" << endl;

        str += member.getOwnHouse().getAddress() + ",";
        str += member.getOwnHouse().getCity() + ",";
        str += member.getOwnHouse().getDescription() + ",";
        if (member.getOwnHouse().getAvailable())
        {
            str += "1";
            str += to_string(member.getOwnHouse().getConsumePoint()) + ",";
            str += member.getOwnHouse().getStartDay();
            if (!member.getRequests().empty())
                for (Request request: member.getRequests())
                    str += request.to_string() + ",";
        }
        else
            str += "0";

        fileout << str << endl;
    }

}


