#pragma once
#include <iostream>
#include "clsBankClient.h" 
#include "clsInputValidate..h"
#include "ClsScreen.h" 
using namespace std;
class ClsWithdraw :protected ClsScreen
{
private:

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

    static void StartWithdraw()
    {


        system("cls");
        _DrawScreenHeader("Withdraw Screen");
        string AccountNumber;
        cout << "Enter Account Number ? ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _Print(Client1);
        float Withdraw;
        cout << "Enter Deposit ?";
        Withdraw = clsInputValidate::ReadFloatNumber("Un Valid Number please enter Valid number ? ");
        cout << "\n Are you Sure to make Deposit y/n ? ";
        char answer;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            
            if (Client1.WithDrow(Withdraw))
            {
                cout << "Amount Deposit Successfully \n";
                cout << "Current balance Is :" << Client1.AccountBalance << endl;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Withdraw << endl;
                cout << "\nYour Balance is: " << Client1.AccountBalance << endl;
            }
        }
        else
        {
                       

            cout << "Withdraw opperation Canceled . \n"; 
        }

    }

};

