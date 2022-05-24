#include "GeneralFunction.h"

void getData(string path)
{
    fstream file;
    file.open("data.txt", std::ios::in);

    if(!file){
        cout << "Cannot open file!";
        return;
    }

    string data;
    while (!file.eof())
    {   
        getline(file, data);
        if (!data.length()) 
            break;

        members.push_back(splitData(data));
    }

    file.close();
}

Member splitData(string data)
{
    stringstream strStream(data);
    vector<string> userData;
    string token;
    while(getline(strStream, token, ',')){
        userData.push_back(token);
    }
    user.set_info(std::stoi(userData[0]), userData[1], userData[2], userData[3], userData[4], 
    stod(userData[5]), std::stod(userData[6]),std::stod(userData[7]), userData[8], userData[9], std::stoi(userData[10]),std::stod(userData[11]) 
    ,userData[12], userData[13], userData[14], userData[15]);

    //input peding/accepted request
    while(userData[16] != "END"){
        cout << "in request ";
        Request temp;
        temp.set_req(std::stoi(userData[i]),userData[i+1],std::stod(userData[i+2]),userData[i+3],userData[i+4]);
        user.set_request(temp);
        i+=5;
    }
}

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