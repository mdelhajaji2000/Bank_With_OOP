#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include <vector>
#include <fstream>
#include "clsEncryption.h"

using namespace std;
class clsUser : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;

    bool _MarkedForDelete = false;

    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], clsEncryption::DeEncrypt(vUserData[5]), stoi(vUserData[6]));

    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.UserName + Seperator;
        UserRecord += clsEncryption::Encrypt(User.Password) + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;

    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
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

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    string _CreatRecord()
    {
        clsDate Date = clsDate();
        string record = to_string(Date.GetYear()) + "/" + to_string(Date.GetMonth()) + "/" + to_string(Date.GetDay());
        record += "#//#" + Date.getClock();
        record += "#//#" + this->UserName + "#//#" + this->Password + "#//#" + to_string(this->Permissions);

        return record;
    }

    

public:

    enum enPermessions {
        eAll = -1,
        pListClients = 1,
        pAddNewClient = 2,
        pDeletClient = 4,
        pUpdateClient = 8,
        pFindClient = 16,
        pTransection = 32,
        pManageUsers = 64,
        pLoginRegester = 128,
        pCurrency_Exchange = 256
    };

    struct stUserRegisterRecord
    {
        string Date_Time;
        string UserName;
        string Password;
        int Permessions;
    };

    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    static clsUser::stUserRegisterRecord _ConvertRecordLineTostructData(string Line)
    {
        stUserRegisterRecord stRegestRecord;
        vector<string> LineToData = clsString::Split(Line, "#//#");
        stRegestRecord.Date_Time = LineToData.at(0);
        stRegestRecord.UserName = LineToData.at(1);
        stRegestRecord.Password = LineToData.at(2);
        stRegestRecord.Permessions = stoi(LineToData.at(3));

        return stRegestRecord;
    }

    static vector<clsUser::stUserRegisterRecord> GetUserRegisterRecord()
    {
        vector<clsUser::stUserRegisterRecord> vLogInRegister;

        fstream Myfile;
        Myfile.open("LogInRecords.txt", ios::in);
        if (Myfile.is_open())
        {
            string Line;

            stUserRegisterRecord RegsterLogIn;
            while (getline(Myfile, Line))
            {
                RegsterLogIn = _ConvertRecordLineTostructData(Line);
                vLogInRegister.push_back(RegsterLogIn);
            }

            Myfile.close();
        }

        return vLogInRegister;
    }

    void AddUserRecordToFile()
    {
        string filepath = "users_LogINrecords";

        fstream Myfile;
        Myfile.open(filepath, ios::app);
        if (Myfile.is_open())
        {
            Myfile << _CreatRecord() << endl;
            Myfile.close();
        }
    }

    struct stRecords
    {
        string date;
        string time;
        string user_name;
        string password;
        string permession;
    };

    static vector<stRecords> vGetLoginRecordsList()
    {
        vector<stRecords> vRecords;
        vector<string> vLines;
        
        fstream Myfile;
        Myfile.open("users_LogINrecords", ios::in);
        if (Myfile.is_open())
        {
            string Line;
            while (getline(Myfile, Line))
            {
                vLines = clsString::Split(Line, "#//#");
                vRecords.push_back({vLines.at(0), vLines.at(1), vLines.at(2), vLines.at(3), vLines.at(4)});
            }

            Myfile.close();
        }

        return vRecords;
    }

    void PrintUserIfo()
    {
        PrintPerson();
        cout << "User name  : " << UserName << endl;
        cout << "Password   : " << Password << endl;
        cout << "Permessios : " << Permissions << endl;
        cout << "------------------------------------" << endl;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }


    bool CheckPermession(enPermessions Per)
    {
        if (this->Permissions == enPermessions::eAll)
        {
            return true;
        }

        if ((Per & this->Permissions) == Per)
            return true;
        else
            return false;
    }


};

