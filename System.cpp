#include "System.h"

bool System::login()
{
    cout << "_______________________Login_______________________" << endl;

    if (members.empty())
    {
        cout << "There is no member's data" << endl;
        return false;
    }

    while (true)
    {
        string username;
        string password;
        cout << "Enter username: ";
        fflush(stdin);
        cin >> username;
        Member *memberPointer = members.data();
        for (int i = 0; i < members.size(); i++, memberPointer++)
            if (username == memberPointer->getUserName())
            {
                cout << "Enter password: ";
                fflush(stdin);
                cin >> password;
                if (password == memberPointer->getPassword())
                {
                    currentMember = memberPointer;
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
    cout << "_______________________Admin login_______________________" << endl;
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
    cout << "_______________________Signup_______________________" << endl;
    bool isValid;
    string username;

    while (true)
    {
        isValid = true;
        cout << "Enter username: ";
        fflush(stdin);
        cin >> username;

        for (Member member: members)
        {
            if (username == member.getUserName())
            {
                isValid = false;
                cout << "User name already exists!" << endl;
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

        cout << "Sign up success!!!" << endl;
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
        else if (type == "Phone Number")
        {
            if (!isNumber(data))
                cout << "Only input number" << endl;
            else
                break;
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

void System::houseList()
{
    if (this->currentMember->getOwnHouse().getAvailable())
    {
        string list;
        cout << "Do you want to unlisted your house? (Yes/No)" << endl;
        getline(cin, list);
        if (list == "Yes")
            this->unListHouse();
    }
    else
        this->listHouse();
}

bool System::isLeapYear(int year)
{
    if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
        return true;

    return false;
}

bool System::findHouse()
{
    if (this->members.empty())
    {
        cout << "There is no house." << endl;
        return false;
    }
    string currentUserName = currentMember->getUserName();
    string city;

    cout << "Enter city you want to stay: ";
    fflush(stdin);
    getline(cin, city);

    string dayStay = getDay();

    int index = 0;
    bool found = false;
    for (Member member: members)
        if (currentUserName != member.getUserName())
            if (member.getOwnHouse().getCity() == city)
                if (member.getOwnHouse().getStartDay() == dayStay)
                    if (member.getOwnHouse().getConsumePoint() <= currentMember->getCreditPoints())
                    {
                        cout << "House " << index << "th: " << endl;
                        index++;
                        member.getOwnHouse().showShortInformation();
                        found = true;
                    }
    if (index == 0)
        cout << "There is no house suitable for you." << endl;

    return found;
}

void System::sendRequest()
{
    if(!findHouse())
        return;

    int houseChoice;
    cout << "Enter the house's number: ";
    cin >> houseChoice;

    Request request = Request(currentMember->getUserName(), members[houseChoice].getOwnHouse().getStartDay());
    members[houseChoice].addRequests(request);
    cout << "Send request success!" << endl;
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

    string requestChoice;

    while (true)
    {
        cout << "Enter request's number: ";
        cin >> requestChoice;
        if (!isNumber(requestChoice))
            cout << "Enter number only" << endl;
        else
            break;
    }

    Request temp = currentMember->getRequests()[stoi(requestChoice)];
    temp.setStatus(1);
    currentMember->cleanRequests();
    currentMember->addRequests(temp);
    currentMember->unListHouse();
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
    this->currentMember = nullptr;
}

void System::mainPage()
{
    while (true)
    {
        cout << "_______________________Main_______________________" << endl;
        string choice;
        cout << "Do you want to use as:\n" << "1. Guest\t2. Member\t3. Admin\t4. Exit" << endl;
        cout << "Enter your choice: ";
        fflush(stdin);
        getline(cin, choice);

        if (isNumber(choice))
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
                    break;
                case 4:
                    this->saveData();
                    return;
                default:
                    cout << "Invalid input!!!" << endl;
                    break;
            }
        }
        else
            cout << "Invalid input!!!" << endl;
    }
}

void System::guestPage()
{
    while (true)
    {
        cout << "_______________________Guest_______________________" << endl;
        string choice;
        cout << "Do you want to:\n" << "1. View houses\t2. Sign up\t3. Exit" << endl;
        cout << "Enter your choice: ";
        fflush(stdin);
        getline(cin, choice);


        if (isNumber(choice))
        {
            switch (stoi(choice))
            {
                case 1:
                    this->showHouseShort();
                    break;
                case 2:
                    this->signup();
                    this->memberPage();
                    return;
                case 3:
                    this->logout();
                    return;
                default:
                    cout << "Invalid input!!!" << endl;
                    break;
            }
        }
        else
            cout << "Invalid input!!!" << endl;
    }
}

void System::memberPage()
{
    if (currentMember == nullptr)
        if (!this->login())
            return;

    while (true)
    {
        cout << "_______________________Member_______________________" << endl;
        string choice;
        cout << "Your information: " << endl;
        this->currentMember->displayInformation();

        cout << "Do you want to:" << endl;
        if (this->currentMember->getRentHouse() != nullptr)
        {
            cout << "1. List/Unlist house\t2. View request\t3. Accept request" << endl;
            cout << "4. Find House       \t5. Send Request\t6. Return House" << endl;
            cout << "7.Log out" << endl;
        }
        else
        {
            cout << "1. List/Unlist house\t2. View request\t3. Accept request" << endl;
            cout << "4. Find House       \t5. Send Request\t6. Log out" << endl;
        }
        cout << "Enter your choice: ";
        fflush(stdin);
        getline(cin, choice);

        if (isNumber(choice))
        {
            switch (stoi(choice))
            {
                case 1:
                    this->houseList();
                    break;
                case 2:
                    this->currentMember->displayRequest();
                    cout << "Enter to continue." << endl;
                    getline(cin, choice);
                    break;
                case 3:
                    this->acceptRequest();
                    break;
                case 4:
                    this->findHouse();
                    break;
                case 5:
                    this->sendRequest();
                    break;
                case 6:
                    if (this->currentMember->getRentHouse() != nullptr)
                    {
                        this->currentMember->returnHouse();
                        break;
                    }
                    else
                    {
                        this->logout();
                        return;
                    }
                case 7:
                    if (this->currentMember->getRentHouse() != nullptr)
                    {
                        this->logout();
                        return;
                    }
                    else
                    {
                        cout << "Invalid input!!!" << endl;
                        break;
                    }
                default:
                    cout << "Invalid input!!!" << endl;
                    break;

            }
        }
        else
            cout << "Invalid input!!!" << endl;
    }
}

void System::adminPage()
{
    if (!this->adminLogin())
        return;

    while (true)
    {
        cout << "_______________________Admin_______________________" << endl;
        string choice;

        cout << "Do you want to:\n" << "1. View users\t2. Log out" << endl;
        cout << "Enter your choice: ";
        fflush(stdin);
        getline(cin, choice);

        if (isNumber(choice))
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
        else
            cout << "Invalid input!!!" << endl;
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
        index++;
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
        str += member.getPassword() + ",";
        str += member.getFullName() + ",";
        str += member.getPhoneNumber() + ",";
        str += to_string(member.getCreditPoints()) + ",";

        str += member.getOwnHouse().getAddress() + ",";
        str += member.getOwnHouse().getCity() + ",";
        str += member.getOwnHouse().getDescription() + ",";

        if (member.getOwnHouse().getAvailable())
        {
            str += "1,";
            str += to_string(member.getOwnHouse().getConsumePoint()) + ",";
            str += member.getOwnHouse().getStartDay();
            if (!member.getRequests().empty())
            {
                for (Request request: member.getRequests())
                    str += "," + request.to_string();
            }
        }
        else if (!member.getRequests().empty())
        {
           if (member.getRenter() == nullptr)
               str+= "0";
           else
           {
               str += "0,";
               str += to_string(member.getOwnHouse().getConsumePoint()) + ",";
               str += member.getOwnHouse().getStartDay();
               str += "," + member.getRequests()[0].to_string();
           }
        }
        else
            str += "0";

        fileout << str << endl;
    }

}

System::System(string path)
{
    currentMember = nullptr;
    initialize(path);
}

void System::getData(string path)
{
    fstream filein;
    filein.open(path, ios::in);

    if(!filein)
    {
        cout << "Cannot open file!";
        return;
    }

    string data;
    while (!filein.eof())
    {
        getline(filein, data);
        if (data.length() == 0)
            break;

        this->members.push_back(splitData(data));
    }

    filein.close();
}

Member System::splitData(string data)
{
    stringstream strStream(data);
    vector<string> splitedData;
    string dataPiece;

    while(std::getline(strStream, dataPiece, ','))
        splitedData.push_back(dataPiece);

    int size = splitedData.size();
    Member tempMember = Member(splitedData[0], splitedData[1],
                               splitedData[2],splitedData[3],
                               stoi(splitedData[4]), splitedData[5],
                               splitedData[6], splitedData[7]);

    if (splitedData[8] == "0")
    {
        if (size == 9)
            return tempMember;
        else
        {
            Request request = Request(splitedData[12], splitedData[11]);
            request.setStatus(1);
            tempMember.addRequests(request);
            tempMember.listHouse(stoi(splitedData[9]),splitedData[10]);
            tempMember.unListHouse();
            return tempMember;
        }
    }
    else
        tempMember.listHouse(stoi(splitedData[9]),splitedData[10]);

    if  (size == 11)
        return tempMember;

    int index = 11;
    while (index < size)
    {
        Request request = Request(splitedData[index + 1], splitedData[index]);
        if (splitedData[index + 2] == "1")
        {
            request.setStatus(1);
            tempMember.addRequests(request);
            return tempMember;
        }
        else
            tempMember.addRequests(request);

        index += 3;
    }

    return tempMember;
}

void System::initialize(string path)
{
    getData(path);
    getAdminData("./admin.txt");
    if (members.empty())
        return;
    
    Member *memberPointer1 = members.data();
    Member *memberPointer2 = members.data();
    int size = members.size();
    for (int i = 0; i < size; i++, memberPointer1++)
    {
        if (!memberPointer1->getOwnHouse().getAvailable() && !memberPointer1->getRequests().empty())
        {
            bool found = false;
            for (int j = 0; j < size; j++, memberPointer2++)
            {
                if (memberPointer2->getUserName() == memberPointer1->getUserName())
                    continue;
                if (memberPointer2->getUserName() == memberPointer1->getRequests()[0].getRenterName())
                {
                    found = true;
                    memberPointer1->setRenter(memberPointer2);
                    memberPointer2->setRentHouse(memberPointer1);
                }
            }
            
            if (!found)
                memberPointer1->cleanRequests();
        }
    }
}

void System::getAdminData(string path)
{
    fstream filein;
    filein.open(path, ios::in);

    if(!filein)
    {
        cout << "Cannot open file!";
        return;
    }

    string data;
    while (!filein.eof())
    {
        getline(filein, data);
        if (data.length() == 0)
            break;

        stringstream strStream(data);
        vector<string> splitedData;
        string dataPiece;

        while(std::getline(strStream, dataPiece, ','))
            splitedData.push_back(dataPiece);

        Admin tempAdmin = Admin(splitedData[0], splitedData[1]);

        this->admins.push_back(tempAdmin);
    }

    filein.close();
}

// https://www.delftstack.com/howto/cpp/how-to-determine-if-a-string-is-number-cpp/#:~:text=Use%20std%3A%3Aisdigit%20Method%20to%20Determine%20if%20a%20String%20Is%20a%20Number,-The%20first%20version&text=Namely%2C%20pass%20a%20string%20as,none%20is%20found%20returns%20true.
bool isNumber(const string& str)
{
    if (str.empty())
        return false;
    return str.find_first_not_of("0123456789") == string::npos;
}
