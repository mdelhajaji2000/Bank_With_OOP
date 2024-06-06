#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"


class clsCurrencyMainScreen :
    protected clsScreen
{
private:

    enum enOptions
    {
        enList = 1,
        enFind = 2,
        enUpdate = 3,
        enCalculator = 4,
        enMainMenu = 5
    };

	static int _ReadMainMuneOptions()
	{
		int option;

		cout << "Take your Option [ 1 ~ 5] : ";
		option = clsInputValidate::ReadNumberBetwin(1, 5, "Option faild...!");
		return option;
	}

	static void _Currencies_List()
	{

	}

	static void _Find_Currency()
	{

	}

	static void _Update_Rate()
	{

	}

	static void _Calculat_Currency()
	{

	}

	static void PerformOption(clsCurrencyMainScreen::enOptions option)
	{
		switch (option)
		{
		case clsCurrencyMainScreen::enList:
			break;
		case clsCurrencyMainScreen::enFind:
			break;
		case clsCurrencyMainScreen::enUpdate:
			break;
		case clsCurrencyMainScreen::enCalculator:
			break;
		case clsCurrencyMainScreen::enMainMenu:
			break;
		default:
			break;
		}
	}

public:

    static void MenueScreen()
    {
        _DrawScreenHeader("Currency Exhange Main Screen", "Menue");

			system("cls");
			_DrawScreenHeader("Show Main Screen");

			cout << setw(37) << left << "" << "======================================" << endl;
			cout << setw(37) << left << "" << "\t\tMain Menue" << endl;
			cout << setw(37) << left << "" << "======================================" << endl;
			cout << setw(37) << left << "" << "\t[1] List Currencies." << endl;
			cout << setw(37) << left << "" << "\t[2] Find Currency." << endl;
			cout << setw(37) << left << "" << "\t[3] Update Rate." << endl;
			cout << setw(37) << left << "" << "\t[4] Currency Calculator." << endl;
			cout << setw(37) << left << "" << "\t[5] Main Menue." << endl;

			PerformOption((clsCurrencyMainScreen::enOptions)_ReadMainMuneOptions());
    }

};

