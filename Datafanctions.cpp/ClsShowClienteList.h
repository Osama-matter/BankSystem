#pragma once
#include <iostream>
#include <vector>
#include <iomanip> 
#include "clsBankClient.h" 
#include "ClsScreen.h"
#include "ClsUtility.h" 
using namespace std; 
class ClsShowClienteList :protected ClsScreen
{

    static void _StarttoShowMassage()
    {
        cout << "\n------------------------------------\n";
        cout << "Access Denied, \nYou dont Have Permission To Do this, \nPlease Conact Your Admin.";
        cout << "\n------------------------------------\n";
    }
    static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }

public:
    static void ShowClientsList()
    {


        if (!(CurrentUser.ifHavepermation(clsUsers::enMainMenuePermissions::pListClients)))
        {

            _StarttoShowMassage();
        }
        else
        {
            vector <clsBankClient> vClients = clsBankClient::GetClientesFromFile();
            int Size = vClients.size();
            ClsScreen::_DrawScreenHeader("Show Clientes List", to_string(Size));


            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << "| " << left << setw(15) << "Accout Number";
            cout << "| " << left << setw(20) << "Client Name";
            cout << "| " << left << setw(12) << "Phone";
            cout << "| " << left << setw(20) << "Email";
            cout << "| " << left << setw(10) << "Pin Code";
            cout << "| " << left << setw(12) << "Balance";
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (vClients.size() == 0)
                cout << "\t\t\t\tNo Clients Available In the System!";
            else

                for (clsBankClient Client : vClients)
                {

                    PrintClientRecordLine(Client);
                    cout << endl;
                }

            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;
            double totalBalances = clsBankClient::ClaTotalBalance();
            cout << "\t\t\t\t Total Balances = " << clsBankClient::ClaTotalBalance() << endl;
            cout << "\t\t\t\t" << clsUtil::NumberToText(totalBalances) << endl;

        }
    }


};

