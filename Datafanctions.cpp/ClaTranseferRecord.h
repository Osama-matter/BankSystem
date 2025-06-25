#pragma once
#include <iostream>
#include <vector>
#include <iomanip> 
#include "clsBankClient.h"
#include "ClsScreen.h"
#include "ClsUtility.h"
#include "ClsDate.h"
#include "ClsTransactionsScreen.h"
using namespace std;
class ClaTranseferRecord :protected ClsScreen
{
    static void PrintTransferLogRecordLine(clsBankClient::stTrnsferLogRecord TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.srcBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.destBalanceAfter;
        cout << "| " << setw(8) << left << TransferLogRecord.UserName;


    }
    static void _StarttoShowMassage()
    {
        system("cls");
        cout << "\n------------------------------------\n";
        cout << "Access Denied, \nYou dont Have Permission To Do this, \nPlease Conact Your Admin.";
        cout << "\n------------------------------------\n";
    }

public:
    static void StartTransferRecord()
    {


        if (!(CurrentUser.ifHavepermation(clsUsers::enMainMenuePermissions::pTransfermationRecord)))
        {

            _StarttoShowMassage();
        }
        else
        {
            vector < clsBankClient::stTrnsferLogRecord> Transfer = clsBankClient::_LoadUsersDataFromFile(); 
            int Size = Transfer.size();
            ClsScreen::_DrawScreenHeader("Show Log Users List", to_string(Size));


            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
            cout << "| " << left << setw(8) << "s.Acct";
            cout << "| " << left << setw(8) << "d.Acct";
            cout << "| " << left << setw(8) << "Amount";
            cout << "| " << left << setw(10) << "s.Balance";
            cout << "| " << left << setw(10) << "d.Balance";
            cout << "| " << left << setw(8) << "User";

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (Transfer.size() == 0)
                cout << "\t\t\t\tNo Clients Available In the System!";
            else

                for (clsBankClient::stTrnsferLogRecord Users :Transfer)
                {

                    PrintTransferLogRecordLine(Users);
                    cout << endl;
                }

            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;
        }


    }


};



