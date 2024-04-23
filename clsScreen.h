#pragma once
#include <iostream>
#include <iomanip>

#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(std::string Title, std::string SubTitle = "Main Menu")
	{
		clsDate Date = clsDate();
        cout << setw(37) << left << "" << "--------------------------------------" << endl;
        cout << setw(37) << left << "" << "\t\t" << Title << endl;
        cout << setw(37) << left << "" << "\t\t" << SubTitle << endl;
        cout << setw(37) << left << "" << "--------------------------------------" << endl;
		cout << setw(37) << left << "" << "User : " << CurrentUser.UserName << endl;
		cout << setw(37) << left << "" << "Date : ";
		Date.print();
		cout << endl;
	}
};

