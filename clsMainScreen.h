#pragma once

#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsBankClient.h"
#include "clsAddNewClient.h"
#include "clsDeletClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransectionScreen.h"
#include "clsUserMangementScreen.h"
#include "clsShowClientsList.h"
#include "clsUsers.h"
#include "clsLoginRegesterScreen.h"
#include "clsCurrencyMainScreen.h"
#include "Global.h"

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOptions
	{
		eListClients = 1, eAddNewClient = 2, eDeletClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransectionMenu = 6,
		eManageUsers = 7, eLoginResgeter = 8, Currency, eExit = 10
	};

	static short _ReadMainMenuOptions()
	{
		cout << setw(37) << left << "" << "Choose What Do you Want [1~8] ? : ";
		short Choice = clsInputValidate::ReadNumberBetwin(1, 10, "Number must be betwin 1 ~ 10 try agin => ");
		return Choice;
	}

	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenu();
	}


	static void _PerfomMainMenueOption(enMainMenueOptions Option)
	{
		switch (Option)
		{
		case clsMainScreen::eListClients:
			system("cls");
			if (CurrentUser.CheckPermession(clsUser::enPermessions::pListClients))
			{
				_ShowAllClientsScreen();
			}
			else {
				_DrawScreenHeader("Action Denied... Contact Your Admin", "");
			}
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eAddNewClient:
			system("cls");
			if (CurrentUser.CheckPermession(clsUser::enPermessions::pAddNewClient))
			{
				_Show_add_New_Screen();
			}
			else {
				_DrawScreenHeader("Action Denied... Contact Your Admin", "");
			}
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eDeletClient:
			system("cls");
			if (CurrentUser.CheckPermession(clsUser::enPermessions::pDeletClient))
			{
				_ShowDeletClientScreen();
			}
			else {
				_DrawScreenHeader("Action Denied... Contact Your Admin", "");
			}
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eUpdateClient:
			system("cls");
			if (CurrentUser.CheckPermession(clsUser::enPermessions::pUpdateClient))
			{
				_ShowUpdateClientScreen();
			}
			else {
				_DrawScreenHeader("Action Denied... Contact Your Admin", "");
			}
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eFindClient:
			system("cls");
			if (CurrentUser.CheckPermession(clsUser::enPermessions::pFindClient))
			{
				_ShowFindClientScreen();
			}
			else {
				_DrawScreenHeader("Action Denied... Contact Your Admin", "");
			}
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eShowTransectionMenu:
			system("cls");
			if (CurrentUser.CheckPermession(clsUser::enPermessions::pTransection))
			{
				_ShowTransectionScreen();
			}
			else {
				_DrawScreenHeader("Action Denied... Contact Your Admin", "");
			}
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eManageUsers:
			system("cls");
			if (CurrentUser.CheckPermession(clsUser::enPermessions::pManageUsers))
			{
				_ShowManageUsersScreen();
			}
			else {
				_DrawScreenHeader("Action Denied... Contact Your Admin", "");
			}
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eLoginResgeter:
			if (CurrentUser.CheckPermession(clsUser::enPermessions::pLoginRegester))
			{
				_ShowRegesterLoginHistory();
			}
			else
			{
				_DrawScreenHeader("Action Denied... Contact Your Admin!", "");
			}
			break;
		case clsMainScreen::eExit:
			break;
		case clsMainScreen::Currency:
			system("cls");
			if (CurrentUser.CheckPermession(clsUser::enPermessions::pCurrency_Exchange))
			{

				_Currecy_Exchange();
			}
			else {
				_DrawScreenHeader("Action Denied Please contact your admin...!", "");
			}
			_GoBackToMainMenue();
		default:
			break;
		}
	}

	static void _Currecy_Exchange()
	{
		clsCurrencyMainScreen::MenueScreen();
	}

	static void _ShowAllClientsScreen()
	{
		clsShowClientsList::PrintClientsTable();
	}


	static void _Show_add_New_Screen()
	{
		clsAddNewClient::AddNew();
	}


	static void _ShowDeletClientScreen()
	{
		clsDeletClientScreen::DeletClient();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::UpdateClient();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::FindClient();
	}

	static void _ShowTransectionScreen()
	{
		/*cout << "TransectionScreen Will Be Here..." << endl;*/
		clsTransectionScreen::ShowTransectionMenue();
	}

	static void _ShowManageUsersScreen()
	{
		//cout << "ManageUsers Screen WillBe Here..." << endl;
		//clsManageUsersScreen::ShowManageUsersScreen();
		clsManageUsersScreen::ShowManageUsersScreen();
		//clsUsers::printHelloWorld();
		system("pause>0");
	}

	static void _ShowRegesterLoginHistory()
	{
		system("cls");
		clsLoginRegesterScreen::ShowRegesterRecordScreen();
		_GoBackToMainMenue();
	}

	static void _Log_out()
	{
		CurrentUser = clsUser::Find("", "");


	}


public:
	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("Show Main Screen");

		cout << setw(37) << left << "" << "======================================" << endl;
		cout << setw(37) << left << "" << "\t\tMain Menue" << endl;
		cout << setw(37) << left << "" << "======================================" << endl;
		cout << setw(37) << left << "" << "\t[1] Show Client Screen." << endl;
		cout << setw(37) << left << "" << "\t[2] Add New Client." << endl;
		cout << setw(37) << left << "" << "\t[3] Delet Client." << endl;
		cout << setw(37) << left << "" << "\t[4] Update Client." << endl;
		cout << setw(37) << left << "" << "\t[5] Find Client." << endl;
		cout << setw(37) << left << "" << "\t[6] Transection." << endl;
		cout << setw(37) << left << "" << "\t[7] Manage Users." << endl;
		cout << setw(37) << left << "" << "\t[8] Login Regester Screen." << endl;
		cout << setw(37) << left << "" << "\t[9] Currecy Exchange." << endl;
		cout << setw(37) << left << "" << "\t[10] LogOut" << endl;

		_PerfomMainMenueOption((enMainMenueOptions)_ReadMainMenuOptions());
	}
};

