#include "System.h"
bool login()
{
    bool isValid = false;
    do {
        string username;
        string password;
        cout << "Enter username: ";
        cin >> username;
        for (Member member : members)
            if (username.compare(member.getUserName()) == 0)
            {
                cout << "Enter password: ";
                cin >> password;
                if(password.compare(member.getPassword()) == 0)
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
    } while (true);
}

bool signup()
{
    bool isValid = true;
    string username;

    while (true)
    {
        cout << "Enter username: ";
        cin >> username;
        for (Member member : members)
            if (username.compare(member.getUserName()) == 0)
            {
                isValid = false;
                break;
            }
        if (isValid)
            break;
    }
    
    Member member = Member();

    if (isValid)
    {
        string password = getUserData(password, "Password", false);
        string fullName = getUserData(fullName, "Full Name", false);
        string phoneNumber = getUserData(phoneNumber, "Phone Number", false);
        string location = getUserData(location, "Location", true);
        string description = getUserData(description, "Description", true);

        House house = House(location, description);
        member = Member(username, password, fullName, phoneNumber, 500, &house);
        members.push_back(member);
    }
    
    return isValid;
}

string getUserData(string data, string type, bool isHouse)