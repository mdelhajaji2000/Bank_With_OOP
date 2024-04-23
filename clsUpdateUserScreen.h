#pragma once


#include "clsScreen.h"
#include "clsUsers.h"
#include "clsInputValidation.h"


class clsUpdateUserScreen :
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

    static void _ReadUserInfo(clsUser& User)
    {
        //cout << "Creat user name : " << endl;
        //User.UserName = clsInputValidate::ReadString();

        cout << "Edit First Name : " << endl;
        User.FirstName = clsInputValidate::ReadString();

        cout << "Edit Last Name : " << endl;
        User.LastName = clsInputValidate::ReadString();

        cout << "Edit Email : " << endl;
        User.Email = clsInputValidate::ReadString();

        cout << "Edit Phone : " << endl;
        User.Phone = clsInputValidate::ReadString();

        cout << "Edit a Password : " << endl;
        User.Password = clsInputValidate::ReadString();

        bool readPermession = clsInputValidate::ReadYandN("Do you want To Edit Permessions ? y/n : ");
        if (readPermession)
        {
            cout << "Edit Permessions : " << endl;
            User.Permissions = _ReadPermessions();
        }

    }

    static void PrintUser(clsUser User)
    {
        cout << endl;
        cout << setw(37) << "The Folowing are The Client Information after Editing : " << endl;
        cout << setw(37) << "" << "===========================" << endl;
        cout << setw(37) << "" << "- User name      : " << User.UserName << endl;
        cout << setw(37) << "" << "- Full Name		: " << User.FullName() << endl;
        cout << setw(37) << "" << "- Email			: " << User.Email << endl;
        cout << setw(37) << "" << "- Phone			: " << User.Phone << endl;
        cout << setw(37) << "" << "- Password		: " << User.Password << endl;
        cout << endl;
    }

public:


    static void EditUser()
    {
        _DrawScreenHeader("Update User Screen", "");

        string UserName;
        cout << "Enter User name : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "User Not Found Try another one : " << endl;
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = User.Find(UserName);
        User.PrintUserIfo();



        _ReadUserInfo(User);

        bool IsPerform = clsInputValidate::ReadYandN("Do you want To Save Changes y/n ? : ");

        if (IsPerform)
        {
            clsUser::enSaveResults SaveResult;
            SaveResult = User.Save();

            switch (SaveResult)
            {
            case clsUser::svFaildEmptyObject:
                cerr << RED << "Error : Empty-Object" << RESET << endl;
                break;
            case clsUser::svSucceeded:
                cout << GREEN << "User Updated Succesfuly..." << RESET << endl;
                break;
            case clsUser::svFaildUserExists:
                cout << RED << "User name Exist Try another one : " << RESET << endl;
                break;
            default:
                break;
            }
        }

    }

};

