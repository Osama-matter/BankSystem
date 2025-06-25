#pragma once
#include <iostream> 
#include "ClsGlobalUser.h"
#include "ClsUsers.h"
#include "ClsDate.h"
using namespace std; 
class ClsScreen 
{
protected:
	static void _DrawScreenHeader(string ScreenTitle , string SubTitle = "")
	{
		cout << "=============================================================================================\n\n"; 
		cout << "\t\t\t" << ScreenTitle << endl <<endl ;
		if (!(SubTitle == "")) 
		{
			cout << "\t\t\t (" << SubTitle << ") Clientes " << endl;
		}
		
		
		cout << "\t\t\tUser : " <<CurrentUser.AccountNumber()  << endl; 
		cout << "\t\t\tDate : " << clsDate::DateToString(clsDate()); 
			
		cout << "\n==============================================================================================\n\n";
	}

};

