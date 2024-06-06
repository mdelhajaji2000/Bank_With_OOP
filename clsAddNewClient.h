#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"


class clsAddNewClient :
    protected clsScreen
{
private:

	static void ReadClientInfo(clsBankClient& Client)
	{
		cout << endl;
		cout << "Creat : " << endl;
		cout << "        -FirstName : ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "        -LastName : ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "        -Email : ";
		Client.Email = clsInputValidate::ReadString();
		cout << "        -Phone : ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "        -PIN code : ";
		Client.PIN = clsInputValidate::ReadString();
		cout << endl;
	}

	static void PrintClient(clsBankClient Client)
	{
		cout << endl;
		cout << setw(37) << "The Folowing are The Client Information : " << endl;
		cout << setw(37) << "" << "===========================" << endl;
		cout << setw(37) << "" << "- Account Number : " << Client.getAccountNumber() << endl;
		cout << setw(37) << "" << "- First Name		: " << Client.FirstName << endl;
		cout << setw(37) << "" << "- Last Name		: " << Client.FirstName << endl;
		cout << setw(37) << "" << "- Email			: " << Client.Email << endl;
		cout << setw(37) << "" << "- Phone			: " << Client.Phone << endl;
		cout << setw(37) << "" << "- PIN Code		: " << Client.PIN << endl;
		cout << endl;
	}

public:

	static void AddNew()
	{
		_DrawScreenHeader("AddNewScreen", "");

		string Accnumber;
		cout << "Creat an Account Number : ";
		Accnumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(Accnumber))
		{
			cout << "Account Exist with the same number Try another one ! : ";
			Accnumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::GetAddNewClientObject(Accnumber);
		ReadClientInfo(Client);

		clsBankClient::enSaveResult SaveResult;
		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFailEmptyObject:
			cout << "Error : Empty-Object" << endl;
			break;
		case clsBankClient::svSucceeded:
			cout << "Client added Succesfuly ! " << endl;
			break;
		case clsBankClient::svFaildAccnumberExist:
			cout << "Client Account Number Used Befor Try another one !" << endl;
			break;
		default:
			break;
		}

		PrintClient(Client);
	}

};

