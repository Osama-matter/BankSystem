#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "ClsGlobalUser.h"
#include "ClsDate.h" 
#include <vector>
#include <fstream>
#include "ClsUtility.h"
using namespace std;
class clsUsers : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMOde = 2 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    string _DateTime;
    bool _MarkForDaelete = false;
    int _Permation; 

    string _PrepareRejecterLog(  string Seperator = "#//#")
    {
        string Date = "";
        Date += clsDate::GetSystemDateTimeString() + Seperator; 
        Date += AccountNumber()+ Seperator;
        Date += clsUtil::EncryptText( PinCode)+ Seperator; 
        Date += to_string(permation) + Seperator;
        return Date; 

    }

    static clsUsers _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUsers(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4],clsUtil::DecryptText( vUserData[5]), stod(vUserData[6]));

    }


    static clsUsers _ConvertLinetoUserObjectLog(string Line, string Seperator = "#//#")
    {
        vector<string> vUserDataLog = clsString::Split(Line, Seperator);

        return clsUsers(enMode::UpdateMode, vUserDataLog[0], vUserDataLog[1],
            clsUtil::DecryptText( vUserDataLog[2]), stoi(vUserDataLog[3]));
    }



    static string _ConverUsersObjectToLine(clsUsers Users, string Seperator = "#//#")
    {

        string stUserRecord = "";
        stUserRecord += Users.FirstName + Seperator;
        stUserRecord += Users.LastName + Seperator;
        stUserRecord += Users.Email + Seperator;
        stUserRecord += Users.Phone + Seperator;
        stUserRecord += Users.AccountNumber() + Seperator;
        stUserRecord += clsUtil::EncryptText(  Users.PinCode) + Seperator;
        stUserRecord += to_string(Users.permation);

        return stUserRecord;

    }

    static  vector <clsUsers> _LoadUsersDataFromFile()
    {

        vector <clsUsers> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUsers User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }


    static void _SaveUsersDataToFile(vector <clsUsers> vUsers)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out); // overwrite

        if (MyFile.is_open())
        {
            for (clsUsers U : vUsers)
            {
                if (!U._MarkForDaelete)
                {
                    string DataLine = _ConverUsersObjectToLine(U);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }



    void _Update()
    {
        vector <clsUsers> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUsers& U : _vUsers)
        {
            if (U.AccountNumber() == AccountNumber())
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }
    void _AddNew()
    {
        _AddDataLineToFile(_ConverUsersObjectToLine(*this));
    }
    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUsers _GetEmptyUserObject()
    {
        return clsUsers(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:



    clsUsers(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        int permation) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _Permation = permation;

    }
    clsUsers(enMode Mode , string DateTime , string AccountNumber, string PinCode,int permation)
        :clsPerson("", "", "", "")
    {
        _Mode = Mode; 
        _DateTime = DateTime;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _Permation = permation;

    }


    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }
    bool MarkToDelete()
    {
        return _MarkForDaelete;
    }
    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;



    void SetPermation(int permation)
    {
        _Permation = permation; 
    }
    int GePermation()
    {
        return _Permation; 
    }
    _declspec(property(get = GePermation, put = SetPermation)) int permation;
    static clsUsers Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUsers User = _ConvertLinetoUserObject(Line);
                if (User.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUsers Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUsers User = _ConvertLinetoUserObject(Line);
                if (User.AccountNumber() == AccountNumber && User.PinCode == PinCode)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {

            return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }
        case(enMode::AddNewMOde):
            if (clsUsers::IsUserExist(_AccountNumber))
            {
                return enSaveResults::svFaildEmptyObject;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
        }

    }

    static bool IsUserExist(string AccountNumber)
    {

        clsUsers User1 = clsUsers::Find(AccountNumber);
        return (!User1.IsEmpty());
    }

    static clsUsers GetAddNewUsersMod(string AccountNumber)
    {
        return clsUsers(enMode::AddNewMOde, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector<clsUsers> Users;
        Users = _LoadUsersDataFromFile();
        for (clsUsers& u : Users)
        {
            if (u.AccountNumber() == _AccountNumber)
            {
                u._MarkForDaelete = true;
                break;
            }
        }
        _SaveUsersDataToFile(Users);
        *this = _GetEmptyUserObject();
        return true;
    }
    static vector<clsUsers> GetUsersFromFile()
    {
        return _LoadUsersDataFromFile();
    }
    static enum enMainMenuePermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient
        = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32,
        pManageUsers = 64 , pLoginregister = 128 , pTransfermationRecord = 256
    };
    bool ifHavepermation(enMainMenuePermissions permation)
    {

        if (this->permation == enMainMenuePermissions::eAll)
        {
            return true;
        }
        if ((permation & this->permation) == permation)
            return true;
        else
        {
            return false;
        }
    }
    void _AddDatalogLineToFile()
    {
        string  stDataLine = _PrepareRejecterLog(); 
        fstream MyFile;
        MyFile.open("Log.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
    static vector<clsUsers> GetUsersFromFileLog()
    {
        return _LoadUsersLogDataFromFile();
    }

    static  vector <clsUsers> _LoadUsersLogDataFromFile()
    {

        vector <clsUsers> vUsersLog;

        fstream MyFile;
        MyFile.open("Log.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUsers User = _ConvertLinetoUserObjectLog(Line);

                vUsersLog.push_back(User);
            }

            MyFile.close();

        }

        return vUsersLog; 

    }

};
