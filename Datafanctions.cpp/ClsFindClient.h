#pragma once
#include <iostream>
#include "clsBankClient.h" 
#include "clsInputValidate..h"
using namespace std; 
class ClsFindClient :protected ClsScreen 
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
	static void FindClients()
	{
        if (!(CurrentUser.ifHavepermation(clsUsers::enMainMenuePermissions::pFindClient)))
        {

            _StarttoShowMassage();
        }
        else
        {
            ClsScreen::_DrawScreenHeader("Find Clientes List");
            string AccountNumber;
            cout << "Enter Account Number ? ";
            AccountNumber = clsInputValidate::ReadString();


            while (!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\nAccount number is not found, choose another one: ";
                AccountNumber = clsInputValidate::ReadString();
            }

            clsBankClient Client1 = clsBankClient::Find(AccountNumber);
            if (!Client1.IsEmpty())
            {
                cout << "\nClient Found . \n";
            }
            else
            {
                cout << "CLient Not Found  .\n";
            }
            _Print(Client1);
        }
	}
};

