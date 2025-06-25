#pragma once
#include <iostream>
#include <vector>
#include <iomanip> 
#include "ClsUsers.h" 
#include "ClsScreen.h"
#include "ClsUtility.h" 
using namespace std;
class ClsShowUserList :protected ClsScreen
{
    static void PrintUserRecordLine(clsUsers Users)
    {

        cout << "| " << setw(15) << left << Users.AccountNumber();
        cout << "| " << setw(20) << left << Users.FullName();
        cout << "| " << setw(12) << left << Users.Phone;
        cout << "| " << setw(20) << left << Users.Email;
        cout << "| " << setw(10) << left << Users.PinCode;
        cout << "| " << setw(12) << left << Users.permation;


    }

public:
    static void StartShowUserList()
    {


        vector < clsUsers> vUsers = clsUsers::GetUsersFromFile();
        int Size = vUsers.size();
        ClsScreen::_DrawScreenHeader("Show Users List", to_string(Size));


        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Permation";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsUsers Users : vUsers)
            {

                PrintUserRecordLine(Users); 
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;


    }


};

