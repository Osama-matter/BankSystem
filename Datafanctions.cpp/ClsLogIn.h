#pragma once
#include <iostream> 
#include "ClsScreen.h"
#include "ClsGlobalUser.h"
#include "ClsMainMenue.h"

using namespace std; 
class ClsLogIn :ClsScreen
{
	static bool  _Login()
	{
		bool LoginFaild = false;
		string UserName, PinCode;
		int count = 0;


		do
		{
			
			
			count++;
			if (count > 3)
			{
				cout << "You are Looked after 3 trials . \n";
				return false;
			}

			if (LoginFaild )
			{
				cout << "Un Valid UserName Or Password you have " << 4 - count  <<" Trials  please Try agine !\n";
			}


			cout << "\nEnter User Name ? ";
			cin >> UserName;
			cout << "\nEnter Password ?";
			cin >> PinCode; 
			CurrentUser = clsUsers::Find(UserName, PinCode);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild );
		CurrentUser._AddDatalogLineToFile(); 
		ClsMainMenue::ShowMainScreen();

		
	}
public:
	static bool Login()
	{
		system("cls"); 
		_DrawScreenHeader("Login Screen "); 
		return _Login(); 
	}

};

