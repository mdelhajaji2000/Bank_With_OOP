#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"

class clsShowClientsList :
	protected clsScreen
{
private:

	static void _PrintClientRecordLine(clsBankClient Client)
	{

		cout << "| " << setw(15) << left << Client.getAccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12 + 5) << left << Client.Phone;
		cout << "| " << setw(25) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PIN;
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}

public:

	static void PrintClientsTable()
	{
		_DrawScreenHeader("Client List");
		vector <clsBankClient> vClients = clsBankClient::getClientsList();

		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n_________________________________________________________________";
		cout << "___________________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12 + 5) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_________________________________________________________________";
		cout << "___________________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{

				_PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << "\n_________________________________________________________________";
		cout << "___________________________________________________\n" << endl;
	}

};

