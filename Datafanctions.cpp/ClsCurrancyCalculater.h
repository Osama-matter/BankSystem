#pragma once
#include <iostream>
#include "ClsScreen.h" 
#include "clsInputValidate..h"
#include "clsCurrency.h"
class ClsCurrancyCalculater :public ClsScreen
{
	static void  ClaCurrancyConvertion(float Amount  , clsCurrency From , clsCurrency To)
	{
		float ConverationRasualts; 
		ConverationRasualts = ((Amount / From.Rate()) * To.Rate()); 
		cout << Amount << From.CurrencyCode() << " = " << ConverationRasualts << To.CurrencyCode() << endl; 
	}
	static float ReadAmount()
	{
		cout << "Enter Currancy Amount    ? ";
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
	static void StartCurrancyCalculater()
	{
		_DrawScreenHeader("Currancy Claculater ");
		string Code;
		cout << "\nEnter Country Code From ?";
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

		float Amount = ReadAmount(); 
		
		string Code2;
		cout << "\nEnter Country Code To ?";
		Code2 = clsInputValidate::ReadString();
		while (!(clsCurrency::IsCurrencyExistByCode(clsString::UpperAllString(Code2))))
		{
			cout << "Un Valide Code Enter Country Code Name ?";
			Code2 = clsInputValidate::ReadString();
		}
		clsCurrency Currancy2 = clsCurrency::FindByCode(Code2);
		if (!Currancy2.IsEmpty())
		{
			cout << "Currancy Found \n";
		}
		else
		{
			cout << "Currancy Not Found \n";
		}
		_printCurrancy(Currancy);
		cout << "\n Enter Amount To Exchande ?"; 

		ClaCurrancyConvertion(Amount, Currancy, Currancy2); 
	}
};

