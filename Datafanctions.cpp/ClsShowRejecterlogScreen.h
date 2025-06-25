#pragma once
#include <iostream>
#include <vector>
#include <iomanip> 
#include "ClsUsers.h" 
#include "ClsScreen.h"
#include "ClsUtility.h"
#include "ClsDate.h"
using namespace std;
class ClsShowRejecterlogScreen :protected ClsScreen
{
    static void PrintUserRecordLine(clsUsers Users)
    {
        cout << "| " << setw(25) << left << clsDate::GetSystemDateTimeString(); 
        cout << "| " << setw(15) << left << Users.AccountNumber();
        cout << "| " << setw(10) << left << Users.PinCode;
        cout << "| " << setw(12) << left << Users.permation;

    }
    static void _StarttoShowMassage()
    {
        system("cls");
        cout << "\n------------------------------------\n";
        cout << "Access Denied, \nYou dont Have Permission To Do this, \nPlease Conact Your Admin.";
        cout << "\n------------------------------------\n";
    }

public:
    static void StartShowUserList()
    {


        if (!(CurrentUser.ifHavepermation(clsUsers::enMainMenuePermissions::pLoginregister)))
        {

            _StarttoShowMassage();
        }
        else
        {
            vector < clsUsers> vUserslog = clsUsers::GetUsersFromFileLog();
            int Size = vUserslog.size();
            ClsScreen::_DrawScreenHeader("Show Log Users List", to_string(Size));


            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;
            cout << "| " << left << setw(25) << "Date login";
            cout << "| " << left << setw(15) << "Accout Number";
            cout << "| " << left << setw(10) << "Pin Code";
            cout << "| " << left << setw(12) << "Permation";
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (vUserslog.size() == 0)
                cout << "\t\t\t\tNo Clients Available In the System!";
            else

                for (clsUsers Users : vUserslog)
                {

                    PrintUserRecordLine(Users);
                    cout << endl;
                }

            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;
        }


    }


};

