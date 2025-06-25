#pragma once
#include<iostream> 
#include <iomanip>
#include <conio.h> 
#include "ClsScreen.h" 
#include "clsInputValidate..h"
#include "ClsShowClienteList.h"
#include "ClsAddNewClient.h"
#include "ClsDeleteClienteList.h"
#include "ClsUpdateClient.h" 
#include "ClsFindClient.h"
#include "ClsTransactionsScreen.h"
#include "ClsStartMainMenueOfUser.h"
#include "ClsLogIn.h" 
#include "ClsShowRejecterlogScreen.h"
#include "clsCurrencyScreen.h"
using namespace std; 

class ClsMainMenue :protected ClsScreen 
{
    enum _enMainMenueOptio {ShowClientList=1 , AddNewClient =2 , DeleteClients =3, UpdateClientInfo =4 , FindClient =5, Transaction =6 , MangeUser = 7, LogList = 8  , CuurancyScreen = 9,logOut = 10  };
    static short ReadMainMenueScreenOptiom()
    {
        short Choise = 0; 
        cout << "Enter Youer Choise (1 : 8 ) "; 
        Choise = clsInputValidate::ReadDblNumberBetween(1, 9, "Number Is not Within range Enter agin \n"); 
        return Choise; 
    }

    static void GoBackToMainMenue()
    {
        cout << "Press Any Key To Return ...";
        _getch();
        ShowMainScreen();
    }

    static void StartShowClientList()
    {
     
        ClsShowClienteList::ShowClientsList(); 
    }
    static void  StartAddNewClient()
    {
       
        ClsAddNewClient::AddNewClintes(); 
    }
    static void  StartDeleteClient()
    {
      
        ClsDeleteClienteList::DeleteMode(); 
    }
    static void   StartUpdateClientInfo()
    {
        
        ClsUpdateClient::UpdateClient(); 
    }
    static void  StartFindClient()
    {
      
        ClsFindClient::FindClients(); 
    }
    static void   StartTransaction()
    {
     
        ClsTransactionsScreen::StartTransationScreen(); 
    }
    static void StartMangeUser()
    {
        ClsMainMenueOfUser::ShowMainScreenOfUsers(); 
    }
    static void StartShowLogscreen()
    {
        ClsShowRejecterlogScreen::StartShowUserList(); 
    }
    static void  StartCurrancyScreen()
    {
        clsCurrencyScreen::StartCurrancyScreen(); 
    }
    static void  StartlogOut()
    {
     
        CurrentUser = clsUsers::Find("", ""); 
    }
    static void _PErformMainMenue(_enMainMenueOptio MainMenue)
    {
        switch (MainMenue)
        {
        case(_enMainMenueOptio::ShowClientList):
            system("cls");
            StartShowClientList();
            GoBackToMainMenue();
            break; 
        case(_enMainMenueOptio::AddNewClient):
            system("cls");
            StartAddNewClient();
            GoBackToMainMenue();
            break; 
        case(_enMainMenueOptio::DeleteClients):
            system("cls");
            StartDeleteClient();
            GoBackToMainMenue(); 
            break; 
        case(_enMainMenueOptio::UpdateClientInfo):
            system("cls");
            StartUpdateClientInfo();
            GoBackToMainMenue();
            break;
        case(_enMainMenueOptio::FindClient):
            system("cls");
            StartFindClient();
            GoBackToMainMenue();
            break;
        case(_enMainMenueOptio::Transaction):
            system("cls");
            StartTransaction();
            GoBackToMainMenue(); 
            break; 
          
        case(_enMainMenueOptio::MangeUser):
        {
            system("cls");
            StartMangeUser(); 
            GoBackToMainMenue();
            break;
        }
        case(_enMainMenueOptio::LogList):
        {
            system("cls");
            StartShowLogscreen(); 
            GoBackToMainMenue();
            break;
        }
        case(_enMainMenueOptio::CuurancyScreen):
        {
            system("cls");
            StartCurrancyScreen(); 
            GoBackToMainMenue();
            break;
        }
        case(_enMainMenueOptio::logOut):
            system("cls");
            StartlogOut();

            break; 
        }
    }

public:
	static void ShowMainScreen()
	{
        system("cls"); 
		_DrawScreenHeader("Bank System"); 
        cout << "==================================================================================================\n\n";
        cout << "\t\t Main Menue \t\t              \n\n";
        cout << "==================================================================================================\n\n";
        cout << "[1] Show Client List \n";
        cout << "[2] Add New Client \n";
        cout << "[3] Delete Clients \n";
        cout << "[4] Update Client Info \n";
        cout << "[5] Find Client \n";
        cout << "[6] Transaction \n";
        cout << "[7] Mange Users \n";
        cout << "[8] Login Register \n";
        cout << "[9] Currancy Screen \n"; 
        cout << "[10] LogOut \n";
        cout << "=======================================================================================================\n\n";
        _PErformMainMenue(_enMainMenueOptio(ReadMainMenueScreenOptiom())); 

	}
};

