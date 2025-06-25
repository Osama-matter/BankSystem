#pragma once
#include <iostream>
#include "clsBankClient.h" 
#include "clsInputValidate..h"
#include "ClsScreen.h" 
using namespace std; 
class ClsDeposit :protected ClsScreen 
{
private :

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
    
    static void StartDeposit()
    {
        
       
        system("cls");
        _DrawScreenHeader("Deposit Screen");
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
        float Deposit ;
        cout << "Enter Deposit ?";
        Deposit = clsInputValidate::ReadFloatNumber("Un Valid Number please enter Valid number ? " );
        cout << "\n Are you Sure to make Deposit y/n ? "; 
        char answer;
        cin >> answer; 
        if (answer == 'y' || answer == 'Y')
        {
            Client1.Deposit(Deposit);
            cout << "Amount Deposit Successfully \n"; 
            cout << "Current balance Is :" << Client1.AccountBalance << endl; 
        }
        else
        {
            cout << "Amount Deposit Faild \n";
        }

    }

};

