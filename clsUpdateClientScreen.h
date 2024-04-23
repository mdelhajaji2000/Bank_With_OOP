#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"


class clsUpdateClientScreen :
    protected clsScreen
{

private:

    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << endl;
        cout << "Edit : " << endl;
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

public:

    static void UpdateClient()
    {

        _DrawScreenHeader("Update Client Screen", "");

    	string AccountNumber;
    	cout << "Enter Account Number : ";
    	AccountNumber = clsInputValidate::ReadString();

    	while (!clsBankClient::IsClientExist(AccountNumber))
    	{
    		cout << RED << "\n Account Number Is Not Found ! try another one : " << RESET;
    		AccountNumber = clsInputValidate::ReadString();
    	}

    	clsBankClient Client = clsBankClient::Find(AccountNumber);
    	Client.Print();
    	cout << "\nUpdate Client Info : " << endl;
    	cout << "==========================" << endl;

    	ReadClientInfo(Client);

    	clsBankClient::enSaveResult SaveResult;
    	SaveResult = Client.Save();

    	switch (SaveResult)
    	{
    	case clsBankClient::svFailEmptyObject:
    		cout << RED << "Error account was not saved ! (Empty object (client)) !" << RESET << endl;
    		break;
    	case clsBankClient::svSucceeded:
    		cout << GREEN "Account Updated Successfuly !" << RESET << endl;
    		Client.Print();
    		break;
    	}
    }

};

