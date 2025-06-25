#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "ClsUsers.h" 
#include "clsInputValidate..h"
using namespace std;
class ClsStartToFindUser :protected ClsScreen
{
    static void _Print(clsUsers User)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nAcc. Number : " << User.AccountNumber();
        cout << "\nPassword    : " << User.PinCode;
        cout << "\nPermation     : " << User.permation;
        cout << "\n___________________\n";

    }


public:
    static void FindClients()
    {
        ClsScreen::_DrawScreenHeader("Find Users List");
        string AccountNumber;
        cout << "Enter Account Number ? ";
        AccountNumber = clsInputValidate::ReadString();


        while (!clsUsers::IsUserExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsUsers Users = clsUsers::Find(AccountNumber);
        if (!Users.IsEmpty())
        {
            cout << "\nClient Found . \n";
        }
        else
        {
            cout << "CLient Not Found  .\n";
        }
        _Print(Users);
    }
};

