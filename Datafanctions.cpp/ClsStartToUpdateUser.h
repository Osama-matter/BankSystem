#pragma once
#include <iostream> 
#include <vector> 
#include "ClsUsers.h"
#include "ClsScreen.h"
#include "clsInputValidate..h"


using namespace std;
class ClsStartToUpdateUser :protected ClsScreen
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
    static void UpdateUser()
    {

        ClsScreen::_DrawScreenHeader("Update Users List");
        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsUsers::IsUserExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsUsers Users = clsUsers::Find(AccountNumber);
        _Print(Users);
        char answer = 'n';
        cout << "Are Your sure to update clientes (Y:N) ? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            ReadUserInfo(Users); 
            int permation = Readpermation(); 
            Users.permation = permation; 

            clsUsers::enSaveResults SaveResult;

            SaveResult = Users.Save();

            switch (SaveResult)
            {
            case  clsUsers::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";
                _Print(Users);
                break;
            }
            case clsUsers::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

