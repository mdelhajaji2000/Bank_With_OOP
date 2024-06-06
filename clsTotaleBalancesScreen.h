#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtility.h"

class clsTotaleBalancesScreen :
    protected clsScreen
{

private :

    static void _PrintClientRecordLine(clsBankClient Client)
    {
    
        cout << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(45) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    
    }

public:

    static void showTotaleBalances()
    {

        _DrawScreenHeader("Totale-Balances Screen", "");

        {
            vector <clsBankClient> vClients = clsBankClient::getClientsList();

            cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
            cout << "\n_________________________________________________________________";
            cout << "___________________________________________________\n" << endl;

            cout << "| " << left << setw(15) << "Accout Number";
            cout << "| " << left << setw(40) << "Client Name";
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

            cout << setw(50) << " " << clsBankClient::getTotaleBalances() << endl;
            cout << setw(29) << " " << clsUtil::NumberToText(clsBankClient::getTotaleBalances()) << endl;

        }
    }

};

