#include "System.h"
bool System::login()
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

bool System::signup()
{
    bool isValid = true;
    string username;

    while (true)
    {
        cout << "Enter username: ";
        cin >> username;
            
        for (Member member : members)
        {
            if (username.compare(member.getUserName()) == 0)
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
        string location = getUserData("Location", true);
        string description = getUserData("Description", true);

        House house = House(location, description);
        member = Member(username, password, fullName, phoneNumber, 500, location, description);
        members.push_back(member);
    }
    
    return isValid;
}

string System::getUserData(string type, bool isHouse)
{
    string data;
    do
    {
        if (!isHouse)
            cout << "Enter " + type + ": " ;
        else
            cout << "Enter house " + type + ": " ;

        cin >> data;
        if (data.empty())
        {
            cout << type << " cannot be empty." << endl;
            cout << "Please enter again." << endl;
        }
        else
            break;
    } while (true);

    return data;
}


void System::showHouseData()
{
    for (Member member : members)
    {
        member.ownHouse.showFullInformation();
    }
}