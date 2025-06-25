#pragma once
#include <iostream>
#include <vector>
#include "ClsScreen.h"
#include "clsInputValidate..h"
#include "clsCurrency.h"
using namespace std; 
class ClsUpdateCurrancy :public ClsScreen
{
	static float ReadNewRate()
	{
		cout << "Enter New Currancy Rate  ? "; 
		return clsInputValidate::ReadFloatNumber(); 
	}

	static  void _printCurrancy(clsCurrency Currancy)
	{
		cout << "-----------------------------\n";
		cout << "Currancy Name : " << Currancy.Country() << endl;
		cout << "Currancy Code : " << Currancy.CurrencyCode() << endl;
		cout << "Currancy Rate Using USD : " << Currancy.Rate() << endl;
		cout << "------------------------------\n";
	}

public :


	static void StartToUpdateRateCurrancy()
	{
		_DrawScreenHeader("Update Currancy Rate "); 
		string Code; 
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
		char answer = ' '; 
		cout << "Do you want to change rate y/n :"; 
		cin >> answer; 
		if (answer == 'y' || answer == 'Y')
		{
			float NewRate = ReadNewRate();
			Currancy.UpdateRate(NewRate);

			cout << "\nCurrancy Rate Updated Successfully :-)\n";
			_printCurrancy(Currancy); 
		}



	}
};

