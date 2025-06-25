#pragma once
#include<iostream> 
#include <iomanip>
#include <conio.h> 
#include "ClsScreen.h"
#include "StartToShowUsersList.h"
#include "ClsStartToAddUser.h"
#include "ClsSartToDeleteUser.h"
#include "ClsStartToUpdateUser.h"
#include "ClsStarttoFindUser.h"
#include "ClsGlobalUser.h"

using namespace std;

class ClsMainMenueOfUser :protected ClsScreen
{
    enum _enMainMenueOptio { ShowUsersList = 1, AddNewUsers = 2, DeleteUsers = 3, UpdateUsersInfo = 4, FindUsers = 5, logOut = 6 };
    static short ReadMainMenueScreenOptiom()
    {
        short Choise = 0;
        cout << "Enter Youer Choise (1 : 8 ) ";
        Choise = clsInputValidate::ReadDblNumberBetween(1, 8, "Number Is not Within range Enter agin \n");
        return Choise;
    }
    static void _StarttoShowMassage()
    {
        system("cls"); 
        cout << "\n------------------------------------\n";
        cout << "Access Denied, \nYou dont Have Permission To Do this, \nPlease Conact Your Admin.";
        cout << "\n------------------------------------\n";
    }
    static void GoBackToMainMenue()
    {
        cout << "Press Any Key To Return ...";
        _getch();
        ShowMainScreenOfUsers(); 
    }

    static void StartShowUsersList()
    {

        ClsShowUserList::StartShowUserList(); 
    }
    static void  StartAddNewUser()
    {

        ClsSartToAddUser::AddNewUsers(); 
    }
    static void  StartDeleteUser()
    {

        ClsSartToDeleteUser::DeleteMode(); 
    }
    static void   StartUpdateUserInfo()
    {

        ClsStartToUpdateUser::UpdateUser(); 
    }
    static void  StartFindUser()
    {
        ClsStartToFindUser::FindClients(); 
        
    }

    static void  StartlogOut()
    {
        
        
    }
    static void _PErformMainMenue(_enMainMenueOptio MainMenue)
    {
        switch (MainMenue)
        {
        case(_enMainMenueOptio::ShowUsersList):
            system("cls");
            StartShowUsersList();
            GoBackToMainMenue();
            break;
        case(_enMainMenueOptio::AddNewUsers):
            system("cls");
            StartAddNewUser();
            GoBackToMainMenue();
            break;
        case(_enMainMenueOptio::DeleteUsers):
            system("cls");
            StartDeleteUser();
            GoBackToMainMenue();
            break;
        case(_enMainMenueOptio::UpdateUsersInfo):
            system("cls");
            StartUpdateUserInfo();
            GoBackToMainMenue();
            break;
        case(_enMainMenueOptio::FindUsers):
            system("cls");
            StartFindUser();
            GoBackToMainMenue();
            break;

        case(_enMainMenueOptio::logOut):

        
            break;
        }
    }

public:
    static void ShowMainScreenOfUsers()
    {
        if (!(CurrentUser.ifHavepermation(clsUsers::enMainMenuePermissions::pManageUsers)))
        {

            _StarttoShowMassage(); 
        }
        else
        {
            system("cls");
            _DrawScreenHeader("User Main Menue");

            cout << "[1] Show Users List \n";
            cout << "[2] Add New Users \n";
            cout << "[3] Delete Users \n";
            cout << "[4] Update Users Info \n";
            cout << "[5] Find Users \n";
            cout << "[6] Exit \n";
            cout << "=======================================================================================================\n\n";
            _PErformMainMenue(_enMainMenueOptio(ReadMainMenueScreenOptiom()));

        }
    }
};


