#pragma once

#include "clsScreen.h"
#include "clsUsers.h"
#include "Global.h"
#include "clsMainScreen.h"
#include "clsInputValidation.h"

class clsLoginScreen :
    protected clsScreen
{
private:

    static void _LogIn()
    {
        bool LogINFaild = false;
        static int attempts = 3;

        string username, password;

        do
        {
            if (attempts == 0)
            {
                cout << "System Locked after 3 Failed attempts To Log-In...!" << endl;
                system("pause>0");
                exit(0);
            }

            if (LogINFaild)
            {
                cout << "Invalid UserName/Password!" << endl;
                attempts--;
                cout << "You Have " << attempts << " Trials To Log-In...!" << endl;

                if (attempts == 0) // Check if attempts reached 0 after decrementing
                {
                    cout << "System Locked after 3 Failed attempts To Log-In...!" << endl;
                    system("pause>0");
                    exit(0);
                }
            }

            cout << "Enter User name : ";
            username = clsInputValidate::ReadString();

            cout << "Enter Password  : ";
            password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(username, password);

            LogINFaild = CurrentUser.IsEmpty();

        } while (LogINFaild);

        CurrentUser.AddUserRecordToFile();
        clsMainScreen::ShowMainMenu();
        
    }

public:

    static void ShowLogInScreen()
    {
        system("cls");
        _DrawScreenHeader("Log - In Screen");
        _LogIn();
    }
    
};

