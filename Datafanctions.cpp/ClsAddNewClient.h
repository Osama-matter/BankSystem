#pragma once
#include <iostream> 
#include <vector>
#include "clsBankClient.h"
#include "clsInputValidate..h"
#include "ClsScreen.h"
#include "clsPerson.h"
using namespace std; 
class ClsAddNewClient :ClsScreen 
{
private:
    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }
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
        cout << "\nFirstName   : " <<Client.FirstName;
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
    static void AddNewClintes()
    {

        if (!(CurrentUser.ifHavepermation(clsUsers::enMainMenuePermissions::pAddNewClient)))
        {

            _StarttoShowMassage();
        }
        else
        {
            ClsScreen::_DrawScreenHeader("Add Clientes List");


            string AccountNumber;
            cout << "Enter Account Number ? ";
            AccountNumber = clsInputValidate::ReadString();
            while (clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "Account Number Is foud please chose anthor account Number ?";
                AccountNumber = clsInputValidate::ReadString();
            }

            clsBankClient Client1 = clsBankClient::GetAddNewClintesMod(AccountNumber);

            ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResult;
            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Add Successfully :-)\n";
                _Print(Client1);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }
        }
    }

};

