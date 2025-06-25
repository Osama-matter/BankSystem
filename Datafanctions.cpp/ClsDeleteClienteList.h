#pragma once
#include <iostream>
#include "clsBankClient.h" 
#include "clsInputValidate..h"
#include "ClsScreen.h"

using namespace std; 
class ClsDeleteClienteList :protected ClsScreen 
{

    static void _StarttoShowMassage()
    {
        system("cls");
        cout << "\n------------------------------------\n";
        cout << "Access Denied, \nYou dont Have Permission To Do this, \nPlease Conact Your Admin.";
        cout << "\n------------------------------------\n";
    }
    static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }


public:

    static void DeleteMode()
    {
        if (!(CurrentUser.ifHavepermation(clsUsers::enMainMenuePermissions::pDeleteClient)))
        {

            _StarttoShowMassage();
        }
        else
        {

            ClsScreen::_DrawScreenHeader("Delete Clientes List");

            string AccountNumber;
            cout << "Enter Account Number ? ";
            AccountNumber = clsInputValidate::ReadString();
            while (!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "Account Number not foud please enter anthor account Number ?";
                AccountNumber = clsInputValidate::ReadString();
            }

            clsBankClient Client1 = clsBankClient::Find(AccountNumber);

            _Print(Client1);
            char answer = 'n';
            cout << "Are Your sure to delete clientes (Y:N) ? ";
            cin >> answer;
            if (answer == 'y' || answer == 'Y')
            {

                if (Client1.Delete())
                {
                    cout << "Clientes Delete Successfully --)\n";
                    _Print(Client1);
                }
                else
                {
                    cout << "Error when delete account !\n";
                }

            }
        }

    }
};

