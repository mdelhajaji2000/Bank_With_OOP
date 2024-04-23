#pragma once

#include "clsScreen.h"
#include "clsUsers.h"
#include "clsInputValidation.h"

class clsFindUser :
    protected clsScreen
{
private:


public:

    static void FindUserScreen()
    {
        _DrawScreenHeader("Find user Screen", "");

        string userName;
        cout << "Enter User name : ";
        userName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(userName))
        {
            cout << "user Not Found Try another one : " << endl;
            userName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(userName);
        User.PrintUserIfo();
    }
};

