#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"

class clsDeletClientScreen :
    protected clsScreen
{
private:


public:

    static void DeletClient()
   {

    _DrawScreenHeader("Delet Client Screen");

   	string Accnumber = "";
   
   	cout << "Enter Account Number : ";
   	Accnumber = clsInputValidate::ReadString();
   
   	while (!clsBankClient::IsClientExist(Accnumber))
   	{
   		cout << "Account number Not Exist try another one : ";
   		Accnumber = clsInputValidate::ReadString();
   	}
   
   	clsBankClient Client = clsBankClient::Find(Accnumber);
   	Client.Print();
   
   	char Answer = 'n';
   	cout << "Are you sure To Delet This Client Definitively !" << endl;
   	cout << "y = yes | n = no : ";
   	cin >> Answer;
   
   	if (Answer == 'y' || Answer == 'Y')
   	{
   		if (Client.Delet(Accnumber))
   		{
   			cout << "Client Seccussfly Deleted !" << endl;
   		}
   		else cout << "Error Client Could Not Deleted Correctly !" << endl;
   	}
   }


};

