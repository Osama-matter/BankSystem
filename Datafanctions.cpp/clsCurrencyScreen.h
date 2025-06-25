#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "clsInputValidate..h"
#include <iomanip>  
#include <conio.h>
#include "ClsLIstCrenseies.h"
#include "ClsFindCurrrancy.h"
#include "ClsUpdateCurrancy.h"
#include "ClsCurrancyCalculater.h"
using namespace std; 
class clsCurrencyScreen :public ClsScreen 
{
	enum _enCurrancyMainScreen{LIstCrenseies = 1 , FindCurrancy = 2 ,UPdateRate = 3 , CurrancyClaculatur =4 , MainMenue = 5  };
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
		StartCurrancyScreen(); 
		
	}

	static void StartLIstCrenseies()
	{
		ClsLIstCrenseies::StartCurrancyList(); 
	}
	static void StartFindCurrancy()
	{
		ClsFindCurrrancy::StartFindCurrancy(); 
	}
	static void StartUPdateERte()
	{
		ClsUpdateCurrancy::StartToUpdateRateCurrancy(); 
	}

	static void StartCurrancyClaculatur()
	{
		ClsCurrancyCalculater::StartCurrancyCalculater(); 
	}


	static void StartMainMenue()
	{

	}
	static void _perFormCurrancy(_enCurrancyMainScreen Currancy )
	{
		switch (Currancy)
		{
		case(clsCurrencyScreen::LIstCrenseies):
		{
			system("cls"); 
			StartLIstCrenseies();
			GoBackToMainMenue(); 
		}

		case(clsCurrencyScreen::FindCurrancy):
		{
			system("cls");
			StartFindCurrancy(); 
			GoBackToMainMenue();
		}
		case(clsCurrencyScreen::UPdateRate):
		{
			system("cls");
			StartUPdateERte(); 
			GoBackToMainMenue();
		}
		case(clsCurrencyScreen::CurrancyClaculatur):
		{
			system("cls");
			StartCurrancyClaculatur(); 
			GoBackToMainMenue();
		}
		case(clsCurrencyScreen::MainMenue):
		{

		}

		}

	}
public :

	static void StartCurrancyScreen()
	{
		system("cls"); 
		_DrawScreenHeader("Currancy Exhange Main Menue "); 
		cout << "\n=================================================================\n";
		cout << "Main Menue \n"; 
		cout << "==================================================================\n"; 
		cout << "[1] LIstCrenseies \n";
		cout << "[2] FindCurrancy \n";
		cout << "[3] UpdateRate \n";
		cout << "[4] Currancy Claculatur \n";
		cout << "[5] Main menue \n";
		cout << "================================================================\n\n";
		_perFormCurrancy(_enCurrancyMainScreen(ReadTransationScreenOptiom())); 

	}
};

