#include "GeneralFunction.h"

// void getData(string path)
// {
//     fstream file;
//     file.open("data.txt", std::ios::in);

//     if(!file){
//         cout << "Cannot open file!";
//         return;
//     }

//     string data;
//     while (!file.eof())
//     {   
//         getline(file, data);
//         if (!data.length()) 
//             break;

//         members.push_back(splitData(data));
//     }

//     file.close();
// }
// // Member::Member(string username, string fullName, string phoneNumber, 
// // string password,int creditPoints, House *ownHouse)

// Member splitData(string data)
// {
//     stringstream strStream(data);
//     vector<string> userData;
//     string piece;
//     while (getline(strStream, piece, ','))
//     {
//         userData.push_back(piece);
//     }
//     House house = House(userData[5], userData[6]);
//     Member member = Member(userData[0], userData[1], userData[2], userData[3], stoi(userData[4]), &house);
//     // ,std::stod(userData[7]), userData[8], userData[9], std::stoi(userData[10]),std::stod(userData[11]) 
//     // ,userData[12], userData[13], userData[14], userData[15]

//     //input peding/accepted request
//     // while(userData[16] != "END"){
//     //     cout << "in request ";
//     //     Request temp;
//     //     temp.set_req(std::stoi(userData[i]),userData[i+1],std::stod(userData[i+2]),userData[i+3],userData[i+4]);
//     //     members.set_request(temp);
//     //     i+=5;
//     // }
// }

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
                isValid = true;
                currentMember = &member;
                break;
            }
        
        if (isValid)
        {
            cout << "Enter password: ";
            cin >> password;
            if(password.compare(currentMember->getPassword()) == 0)
            {
                cout << "Log in success." << endl;
                return true;    
            }
            else
            {
                currentMember = nullptr;
                cout << "Wrong password!!!" << endl;
                return false;
            }
        } 
        else
            cout << "No user found..." << endl;
    } while(isValid);
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
    }

    if (isValid)
    {
        string password = getData(password, "Password");
        string fullName;
        string phoneNumber;
        string location;
        string description;


        do
        {
            cout << "Enter password: ";
            cin >> password;
            if (password.compare("") == 0)
                cout << "Password cannot be empty." << endl;
            else
                break;
        } while (true);

        do
        {
            cout << "Enter full name: ";
            cin >> fullName;
            if (fullName.compare("") == 0)
                cout << "Full name cannot be empty." << endl;
            else
                break;
        } while (true);
            
        do
        {
            cout << "Enter phone number: ";
            cin >> phoneNumber;
            if (phoneNumber.compare("") == 0)
                cout << "Phone number cannot be empty." << endl;
            else
                break;
        } while (true);

        do
        {
            cout << "Enter house location: ";
            cin >> location;
            if (location.compare("") == 0)
                cout << "Location cannot be empty." << endl;
            else
                break;
        } while (true);

        do
        {
            cout << "Enter house description: ";
            cin >> description;
            if (description.compare("") == 0)
                cout << "Description cannot be empty." << endl;
            else
                break;
        } while (true);
    }
}

string getData(string data, string type, bool isHouse)
{
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
}