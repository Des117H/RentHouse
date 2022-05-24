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
    user.set_info(std::stoi(userData[0]), outp[1], outp[2], outp[3], outp[4], 
    stod(outp[5]), std::stod(outp[6]),std::stod(outp[7]), outp[8], outp[9], std::stoi(outp[10]),std::stod(outp[11]) 
    ,outp[12], outp[13], outp[14], outp[15]);

    //input peding/accepted request
    while(outp[i] != "END"){
        cout << "in request ";
        Request temp;
        temp.set_req(std::stoi(outp[i]),outp[i+1],std::stod(outp[i+2]),outp[i+3],outp[i+4]);
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