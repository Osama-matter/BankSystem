#pragma once
#include <iostream>
#include <string>
#include "clsCurrency.h"
#include "ClsScreen.h"
#include "clsInputValidate..h"
#include "ClsString.h"
using namespace std; 
class ClsFindCurrrancy :public ClsScreen
{
	static enum _enFindType{countryName = 1 , Code = 2 };
	static  void _printCurrancy(clsCurrency Currancy )
	{ 
		cout << "-----------------------------\n"; 
		cout << "Currancy Name : " << Currancy.Country() << endl;
		cout << "Currancy Code : " << Currancy.CurrencyCode() << endl;
		cout << "Currancy Rate Using USD : " << Currancy.Rate() << endl;
		cout << "------------------------------\n"; 
	}
public :
	static void StartFindCurrancy()
	{
		short Choise = 0 ; 
		ClsScreen::_DrawScreenHeader("Find Currancy "); 
		cout << "Do you Wont FInd By  [1]Country Name   [2] Countery Code "; 
		Choise = clsInputValidate::ReadFloatNumberBetween(1,2 , "In valid Chose please chose (1 , 2) ");
		string Code; 
		
		if (Choise == 1)
		{
			cout << "\nEnter Country Name ?";
			Code = clsInputValidate::ReadString();  
			while (!(clsCurrency::IsCurrencyExistByCountry(clsString::UpperAllString(Code))))
			{
				cout << "Un Valide Code Enter Country Code Name ?";
				Code = clsInputValidate::ReadString(); 
			}
			clsCurrency Currancy = clsCurrency::FindByCountry(Code); 
			if (!Currancy.IsEmpty())
			{
				cout << "Currancy Found \n"; 
			}
			else
			{
				cout << "Currancy Not Found \n"; 
			}
			_printCurrancy(Currancy); 

		}
		else  
		{
			cout << "\nEnter Country Code ?";
			Code = clsInputValidate::ReadString();
			while (!(clsCurrency::IsCurrencyExistByCode(clsString::UpperAllString(Code))))
			{
				cout << "Un Valide Code Enter Country Code Name ?";
				Code = clsInputValidate::ReadString();
			}
			clsCurrency Currancy = clsCurrency::FindByCode(Code);
			if (!Currancy.IsEmpty())
			{
				cout << "Currancy Found \n";
			}
			else
			{
				cout << "Currancy Not Found \n";
			}
			_printCurrancy(Currancy);

		}

	}


};

