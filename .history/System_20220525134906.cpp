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

        cout <<"memres size: " << members.size() << endl;
        if (members.size() == 0)
            break;
            
        cout << "after check size" << endl;
        for (Member member : members)
        {
            cout << "1" << endl;
            if (username.compare(member.getUserName()) == 0)
            {
                isValid = false;
                break;
            }
        }
        if (isValid)
            break;
    }
    cout << "out while" << endl;
    
    Member member = Member();
    cout << "after create member null" << endl;

    if (isValid)
    {
        cout << "in check valid" << endl;
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

string System::getUserData(, string type, bool isHouse)
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