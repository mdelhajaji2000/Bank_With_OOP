#pragma once

#include "clsMainScreen.h"
#include "clsInputValidation.h"
#include "clsBankClient.h"
#include "clsDipositScreen.h"
#include "clsWithdarawScreen.h"
#include "clsTotaleBalancesScreen.h"

class clsTransectionScreen :
    protected clsScreen
{
private:

    enum enTransectionOprions
    {
        Deposit = 1,
        withdraw = 2,
        TotaleBalances = 3,
        MainMenu = 4
    };



    static int _ReadTransectionMenueOption()
    {
        int Option;
        cout << setw(37) << "" << "What Do you whant : [1~4] ? : ";
        Option = clsInputValidate::ReadNumberBetwin(1, 4, "Please Enter Number Betwin 1 ~ 4 : try again : ");
        return Option;
    }

    static void _PerformTransectionMenue(enTransectionOprions Option)
    {
        switch (Option)
        {
        case clsTransectionScreen::Deposit:
            system("cls");
            _ShowDepositMenuScreen();
            _GoBackToTransectionMenu();
            break;
        case clsTransectionScreen::withdraw:
            system("cls");
            _ShowWithdrawMenuScreen();
            _GoBackToTransectionMenu();
            break;
        case clsTransectionScreen::TotaleBalances:
            system("cls");
            _ShowTotaleBalancesScreen();
            _GoBackToTransectionMenu();
            break;
        case clsTransectionScreen::MainMenu:
            system("cls");
            _BackToMainMenu();
            break;
        default:
            break;
        }
    }

    static void _ShowDepositMenuScreen()
    {
        //cout << "Deposiy Menu Will br Here..." << endl;
        clsDipositScreen::Deposit();
    }

    static void _ShowWithdrawMenuScreen()
    {
        //cout << "WithDraw Menu Will Be Here..." << endl;
        clsWithdarawScreen::WithdrawScreen();
    }

    static void _ShowTotaleBalancesScreen()
    {
        //cout << "Totale Balances Screen Will Be Here..." << endl;
        clsTotaleBalancesScreen::showTotaleBalances();
    }

    static void _BackToMainMenu() {
        //! DoNot Edit here or add somthing!
    }


    static void _GoBackToTransectionMenu(string Message = "\nPress Any Key To GoBack To Transection-Menue...\n")
    {
        cout << Message;
        system("pause>0");
        ShowTransectionMenue();
    }

public:

    static void ShowTransectionMenue () {

        system("cls");

        _DrawScreenHeader("Transection Menue", "");
        cout << setw(37) << left << "" << "======================================" << endl;
        cout << setw(37) << left << "" << "\t\tTransection Menue" << endl;
        cout << setw(37) << left << "" << "======================================" << endl;
        cout << setw(37) << left << "" << "[1] Deposit." << endl;
        cout << setw(37) << left << "" << "[2] Withdraw." << endl;
        cout << setw(37) << left << "" << "[3] TotaleBalances." << endl;
        cout << setw(37) << left << "" << "[4] Main Menu." << endl;
        cout << setw(37) << left << "" << "--------------------------------------" << endl;

        _PerformTransectionMenue((enTransectionOprions)_ReadTransectionMenueOption());
    }
};

