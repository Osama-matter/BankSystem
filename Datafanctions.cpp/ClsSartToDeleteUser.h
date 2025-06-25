#pragma once
#include <iostream>
#include "ClsUsers.h" 
#include "clsInputValidate..h"
#include "ClsScreen.h"



using namespace std;
class ClsSartToDeleteUser :protected ClsScreen
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

    static void DeleteMode()
    {

        ClsScreen::_DrawScreenHeader("Delete Users List");

        string AccountNumber;
        cout << "Enter Account Number ? ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsUsers::IsUserExist(AccountNumber))
        {
            cout << "Account Number not foud please enter anthor account Number ?";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsUsers User = clsUsers::Find(AccountNumber);

        _Print(User);
        char answer = 'n';
        cout << "Are Your sure to delete clientes (Y:N) ? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {

            if (User.Delete())
            {
                cout << "Clientes Delete Successfully --)\n";
                _Print(User);
            }
            else
            {
                cout << "Error when delete account !\n";
            }

        }

    }
};

