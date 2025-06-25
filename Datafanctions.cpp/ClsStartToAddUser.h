#pragma once
#include <iostream> 
#include <vector>
#include "ClsUsers.h"
#include "clsInputValidate..h"
#include "ClsScreen.h"
#include "clsPerson.h"
using namespace std;
class ClsSartToAddUser :ClsScreen
{
private:

    static void ReadUserInfo(clsUsers& Client)
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
    }

    static int Readpermation()
    {
        int permatio = 0;
        char answer = ' ';
        cout << "Do you wont to give full ascess system ?";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            return -1;
        }
        cout << "Do you wont to give  ascess to show clint list ?";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permatio += clsUsers::enMainMenuePermissions::pListClients;
        }
        cout << "Do you wont to give  ascess to Add clint  ?";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permatio += clsUsers::enMainMenuePermissions::pAddNewClient;
        }
        cout << "Do you wont to give  ascess to Delete clint ?";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permatio += clsUsers::enMainMenuePermissions::pDeleteClient;
        }
        cout << "Do you wont to give  ascess to Edit clint Data ?";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permatio += clsUsers::enMainMenuePermissions::pUpdateClients;
        }
        cout << "Do you wont to give  ascess to find clint ?";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permatio += clsUsers::enMainMenuePermissions::pFindClient;
        }
        cout << "Do you wont to give  ascess to Tranactions clint ?";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permatio += clsUsers::enMainMenuePermissions::pTranactions;
        }
        cout << "Do you wont to give  ascess to mange users ?";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permatio += clsUsers::enMainMenuePermissions::pManageUsers;
        }
        cout << "Do you wont to give  ascess to Login Register ?";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permatio += clsUsers::enMainMenuePermissions::pLoginregister;
        }
        return permatio;
    }
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
    static void AddNewUsers()
    {

        ClsScreen::_DrawScreenHeader("Add Users List");


        string AccountNumber;
        cout << "Enter Account Number ? ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsUsers::IsUserExist(AccountNumber))
        {
            cout << "Account Number Is foud please chose anthor account Number ?";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsUsers User = clsUsers::GetAddNewUsersMod(AccountNumber);


        ReadUserInfo(User);
        
        int permation = Readpermation();
        User.permation = permation;
        clsUsers::enSaveResults SaveResult;
        SaveResult = User.Save();

        switch (SaveResult)
        {
        case  clsUsers::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Add Successfully :-)\n";
            _Print(User);
            break;
        }
        case clsUsers::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }

        }
    }

};


