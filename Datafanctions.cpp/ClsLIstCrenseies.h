#pragma once
#include <iostream>
#include <vector>
#include <iomanip> 
#include "ClsUsers.h" 
#include "ClsScreen.h"
#include "ClsUtility.h"
#include "ClsDate.h"
#include "clsCurrency.h"
using namespace std;
class ClsLIstCrenseies :protected ClsScreen
{
    static void PrintCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(45) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();

    }
    static void _StarttoShowMassage()
    {
        system("cls");
        cout << "\n------------------------------------\n";
        cout << "Access Denied, \nYou dont Have Permission To Do this, \nPlease Conact Your Admin.";
        cout << "\n------------------------------------\n";
    }

public:
    static void StartCurrancyList()
    {


        //if (!(CurrentUser.ifHavepermation(clsUsers::enMainMenuePermissions::pLoginregister)))
        //{

        //    _StarttoShowMassage();
        //}
        vector < clsCurrency> vCurrancy = clsCurrency::GetCurrenciesList();
        int Size = vCurrancy.size();
        ClsScreen::_DrawScreenHeader("Currencies List Screen ", to_string(Size));


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vCurrancy.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsCurrency Curranc : vCurrancy)
            {

                PrintCurrencyRecordLine(Curranc);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }


};

