#pragma once

#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUsersListScreen.h"
#include "clsAddUserScreen.h"
#include "clsDeletUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUser.h"

class clsManageUsersScreen :
    protected clsScreen
{
private:
    enum enManageUsersOptions {
        elistUsers = 1,
        eAddNewUser = 2,
        eDeletUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenu = 6
    };

    static int _ReadOption()
    {
        int option;
        cout << setw(37) << "" << "What Do You want : [1~6] ? :" << endl;
        option = clsInputValidate::ReadNumberBetwin(1, 6, "Please Enter Number Betwin 1 ~ 6 : try agin : ");
        return option;
    }

    static void _PerformMangeUsers(enManageUsersOptions Option)
    {
        switch (Option)
        {
        case clsManageUsersScreen::elistUsers:
            system("cls");
            _ShowUsersList();
            _GoBackToManageUsersScreen();
            break;
        case clsManageUsersScreen::eAddNewUser:
            system("cls");
            _ShowAddUsersScreen();
            _GoBackToManageUsersScreen();
            break;
        case clsManageUsersScreen::eDeletUser:
            system("cls");
            _ShowDeletUserScreen();
            _GoBackToManageUsersScreen();
            break;
        case clsManageUsersScreen::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersScreen();
            break;
        case clsManageUsersScreen::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersScreen();
            break;
        case clsManageUsersScreen::eMainMenu:
            _ReturnToMainMenu();
            break;
        default:
            break;
        }
    }

    static void _ShowUsersList()
    {
        clsUsersListScreen::ShowUsersList();
    }

    static void _ShowAddUsersScreen()
    {
        //cout << "Add Users screen Will ne Here..." << endl;
        clsAddUserScreen::AddUser();
    }

    static void _ShowDeletUserScreen()
    {
        //cout << "Delet User Screen Will Be Here..." << endl;
        //clsDeletUserScreen::DeletUser();
        clsDeletUserScreen::DeletUser();
    }

    static void _ShowUpdateUserScreen()
    {
        //cout << "Update User Screen Will Be Here..." << endl;
        clsUpdateUserScreen::EditUser();
    }

    static void _ShowFindUserScreen()
    {
        //cout << "Find User Screen Will Bw Here..." << endl;
        clsFindUser::FindUserScreen();
    }

    static void _ReturnToMainMenu()
    {
        //! Do Do anything Here..
    }

    static void _GoBackToManageUsersScreen()
    {
        cout << "Press Any Key To return To Users Management Screen..." << endl;
        system("pause>0");
        ShowManageUsersScreen();
    }

public:

    static void ShowManageUsersScreen()
    {
        system("cls");

        _DrawScreenHeader("Manage Users Screen.");

        cout << setw(37) << left << "" << "======================================" << endl;
        cout << setw(37) << left << "" << "\t\tManage Users Screen" << endl;
        cout << setw(37) << left << "" << "======================================" << endl;
        cout << setw(37) << left << "" << "[1] Users List." << endl;
        cout << setw(37) << left << "" << "[2] Add New User." << endl;
        cout << setw(37) << left << "" << "[3] Delet User." << endl;
        cout << setw(37) << left << "" << "[4] Update user." << endl;
        cout << setw(37) << left << "" << "[5] Find User." << endl;
        cout << setw(37) << left << "" << "[6] Main Menu." << endl;

        _PerformMangeUsers((enManageUsersOptions)_ReadOption());
    }

};

