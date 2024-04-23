#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
class clsAddUserScreen :
    protected clsScreen
{
private:

    static int _ReadPermessions()
    {
        int per = 0;

        bool GiveFullPermession = clsInputValidate::ReadYandN("Do You want To Give Full Permession [ Y = yes] [ N = NO ] ? : ");
        if (GiveFullPermession) return -1;

        cout << "\t Do You want To Give Access To : " << endl;
        if (clsInputValidate::ReadYandN("\t\t Clients list   [Y = yes][N = no] ? : ")) per += clsUser::enPermessions::pListClients;
        if (clsInputValidate::ReadYandN("\t\t Add new Client [Y = yes][N = no] ? : ")) per += clsUser::enPermessions::pAddNewClient;
        if (clsInputValidate::ReadYandN("\t\t Delet Client   [Y = yes][N = no] ? : ")) per += clsUser::enPermessions::pDeletClient;
        if (clsInputValidate::ReadYandN("\t\t Update Client  [Y = yes][N = no] ? : ")) per += clsUser::enPermessions::pUpdateClient;
        if (clsInputValidate::ReadYandN("\t\t Find Client    [Y = yes][N = no] ? : ")) per += clsUser::enPermessions::pFindClient;
        if (clsInputValidate::ReadYandN("\t\t Transection    [Y = yes][N = no] ? : ")) per += clsUser::enPermessions::pTransection;
        if (clsInputValidate::ReadYandN("\t\t Manage Users   [Y = yes][N = no] ? : ")) per += clsUser::enPermessions::pManageUsers;

        return per;
    }

    static void _ReadUserInfo(clsUser &User)
    {
        //cout << "Creat user name : " << endl;
        //User.UserName = clsInputValidate::ReadString();

        cout << "Enter First Name : " << endl;
        User.FirstName = clsInputValidate::ReadString();

        cout << "Enter Last Name : " << endl;
        User.LastName = clsInputValidate::ReadString();

        cout << "Enter Email : " << endl;
        User.Email = clsInputValidate::ReadString();

        cout << "Enter Phone : " << endl;
        User.Phone = clsInputValidate::ReadString();

        cout << "Creat a Password : " << endl;
        User.Password = clsInputValidate::ReadString();

        cout << "Enter Permessions : " << endl;
        User.Permissions = _ReadPermessions();
    }

    static void PrintUser(clsUser User)
    {
        cout << endl;
        cout << setw(37) << "The Folowing are The Client Information : " << endl;
        cout << setw(37) << "" << "===========================" << endl;
        cout << setw(37) << "" << "- User name      : " << User.UserName << endl;
        cout << setw(37) << "" << "- Full Name		: " << User.FullName() << endl;
        cout << setw(37) << "" << "- Email			: " << User.Email << endl;
        cout << setw(37) << "" << "- Phone			: " << User.Phone << endl;
        cout << setw(37) << "" << "- Password		: " << User.Password << endl;
        cout << endl;
    }

public:

    static void AddUser()
    {
        _DrawScreenHeader("Add New User", "");

        string Username = "";
        cout << "Creat a user name : " << endl;
        Username = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(Username))
        {
            cout << RED << "User Exit with The same User Name" << RESET << endl;
            Username = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::GetAddNewUserObject(Username);
        _ReadUserInfo(User);

        clsUser::enSaveResults SaveResult;
        SaveResult = User.Save();

        switch (SaveResult)
        {
        case clsUser::svFaildEmptyObject:
            cerr << RED << "Error : Empty-Object" << RESET << endl;
            break;
        case clsUser::svSucceeded:
            cout << GREEN << "User Added Succesfuly..." << RESET << endl;
            break;
        case clsUser::svFaildUserExists:
            cout << RED << "User name Exist Try another one : " << RESET << endl;
            break;
        default:
            break;
        }

        PrintUser(User);
    }

};

