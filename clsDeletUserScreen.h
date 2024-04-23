#pragma once

#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUsers.h"

class clsDeletUserScreen :
    protected clsScreen
{
private:



public:

    static void DeletUser()
    {
        _DrawScreenHeader("Delet User Screen", "");

        string userName;

        cout << "Enter user name : ";
        userName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(userName))
        {
            cout << "User Not Found Try Another user name : " << endl;
            userName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(userName);
        User.PrintUserIfo();

        bool ConfirmDeletAction;
        ConfirmDeletAction = clsInputValidate::ReadYandN("Are you sure that do you want to Delet This user ? [y = yes][n = no] ? : ");

        if (ConfirmDeletAction)
        {
            if (User.Delete()) {
                cout << "User Deleted Successfuly..!" << endl;
            }
            else
            {
                cerr << "Error Client Could Not Deleted Correctly..!" << endl;
            }
        }
    }
};

