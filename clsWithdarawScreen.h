#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsBankClient.h"

class clsWithdarawScreen :
    protected clsScreen
{
private:

public:
        static void WithdrawScreen()
        {

            _DrawScreenHeader("WithDraw Screen", "");

            string AccountNumber;
            cout << "Enter Account Number : ";
            AccountNumber = clsInputValidate::ReadString();

            while (!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "Account with [" << AccountNumber << "] Number Dose not Exist Try another one : ";
                AccountNumber = clsInputValidate::ReadString();
            }

            clsBankClient Client = clsBankClient::Find(AccountNumber);

            Client.Print();

            double amount;
            cout << "Enter Amount That will be Withdrawed : ";
            amount = clsInputValidate::ReadNumberBetwin(0, 100000000, "Enable To Performe This Action with that amount try another one : ");

            bool Confirmation;
            cout << "Do You Want to Perform This Action ? [ 0 = NO ] [ 1 = OK] ? : ";
            Confirmation = clsInputValidate::ReadIntNumber();

            if (Confirmation)
            {
                Client.Whitdraw(amount);
                cout << GREEN << "Action Performed Successfuly..!" << RESET << endl;
                cout << "NEW BALANCE : " << Client.AccountBalance << endl;
            }
            else
            {
                cout << RED << "OPERATION WAS CANCELLED...!" << RESET << endl;
            }


        }

};


