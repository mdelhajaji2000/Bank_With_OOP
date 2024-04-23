#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"

class clsFindClientScreen :
    protected clsScreen
{
public :
    
    static void FindClient()
    {
        _DrawScreenHeader("FindClientScreen", "");
       
        cout << "Enter Account Number : ";
        string AccountNumber = clsInputValidate::ReadString();
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (Client.IsEmpty())
        {
            cout << RED << "Client Not Found !" << endl;
        }
        else {
            Client.Print();
        }
        
    }
};

