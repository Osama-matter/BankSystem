#pragma once
#include <iostream>
#include "clsBankClient.h" 
#include "clsInputValidate..h"
#include "ClsScreen.h" 
using namespace std;
class ClsCurrentBalance :ClsScreen
{
public:
	static void ShowTotalBlalance()
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
        cout << "\nTotal balance Is : " << Client1.AccountBalance << endl <<endl ; 
	}

};

