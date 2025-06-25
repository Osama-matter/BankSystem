#pragma once
#include <iostream>
#include <iomanip> 
#include <conio.h>
#include "ClsScreen.h"
#include "clsInputValidate..h"
#include "ClsMainMenue.h"
#include "ClsDeposit.h"
#include "ClsWithdraw.h"
#include "ClsCurrentBalance.h"
#include "ClsTransefer.h"
#include "ClaTranseferRecord.h"

using namespace std; 

class ClsTransactionsScreen :protected ClsScreen 
{

	static void _StarttoShowMassage()
	{
		system("cls");
		cout << "\n------------------------------------\n";
		cout << "Access Denied, \nYou dont Have Permission To Do this, \nPlease Conact Your Admin.";
		cout << "\n------------------------------------\n";
	}
	enum _EnTreasactionMode {Deposit = 1 , Wihtdraw = 2 , TotalBalance = 3 , Transfer = 4,TransferRecord = 5  ,GoTOMainMenue =6   };

	static short ReadTransationScreenOptiom()
	{
		short Choise = 0;
		cout << "Enter Youer Choise (1 : 6 ) ";
		Choise = clsInputValidate::ReadDblNumberBetween(1, 6, "Number Is not Within range Enter agin \n");
		return Choise;
	}

	static void GoBackToMainMenue()
	{
		cout << "Press Any Key To Return ...";
		_getch();
		StartTransationScreen();
	}
	static void StartMakeDeposite()
	{
		ClsDeposit::StartDeposit(); 
	}
	static void StartMakeWithdraw()
	{
		ClsWithdraw::StartWithdraw(); 
	}
	static void StartShowTotalBalance()
	{
		ClsCurrentBalance::ShowTotalBlalance(); 
	}
	static void StartToMakeTransefer()
	{
		ClsTransefer::ShowTransferScreen(); 
	}
	static void StartTransfermationRecord()
	{
		ClaTranseferRecord::StartTransferRecord(); 
	}
	static void GoToMainMenue()
	{

	}
	
	static void _preformTransation(_EnTreasactionMode Transation)
	{
		switch (Transation )
		{
		case(_EnTreasactionMode::Deposit):
		{
			system("cls");
			StartMakeDeposite();
			GoBackToMainMenue();
			break;
		}
		case(_EnTreasactionMode::Wihtdraw):
		{
			system("cls");
			StartMakeWithdraw();
			GoBackToMainMenue();
			break;
		}
		case(_EnTreasactionMode::TotalBalance):
		{
			system("cls");
			StartShowTotalBalance();
			GoBackToMainMenue();
			break;
		}
		case(_EnTreasactionMode::Transfer):
		{
			system("cls");
			StartToMakeTransefer(); 
			GoBackToMainMenue();
			break;
		}
		case(_EnTreasactionMode::TransferRecord):
		{
			system("cls");
			StartTransfermationRecord(); 
			GoBackToMainMenue();
			break;
		}
		case(_EnTreasactionMode::GoTOMainMenue):
		{

		}
		}

	}

	
public:
	static void StartTransationScreen()
	{
		if (!(CurrentUser.ifHavepermation(clsUsers::enMainMenuePermissions::pTranactions)))
		{

			_StarttoShowMassage();
		}
		else
		{
			system("cls");
			_DrawScreenHeader("Transactions Screen");

			cout << "[1] Depotie \n";
			cout << "[2] Withdraw \n";
			cout << "[3] Total Balacnce \n";
			cout << "[4] Transfer \n";
			cout << "[5] Transformation Record \n";
			cout << "[6] Main menue \n";
			cout << "================================================================\n\n";
			_preformTransation(_EnTreasactionMode(ReadTransationScreenOptiom()));

		}
	}
};

