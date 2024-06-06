#pragma once

#include "Global.h"
#include "clsScreen.h"
#include "clsUsers.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{
private:

    static void _PrintRow(const clsBankClient::stTransferRecord& record)
    {
        cout << left << "| " << setw(19) << record.date
            << "| " << setw(15) << record.Client1_account_number
            << "| " << setw(15) << record.Client2_account_number
            << "| " << setw(13) << record.Transfer_amount
            << "| " << setw(15) << record.Client2_amount
            << "| " << setw(15) << record.Client1_amount
            << "| " << setw(12) << record.user_name
            << " |" << endl;
    }

    static void _PrintSeparator()
    {
        cout << left << setfill('-') << setw(120) << "-"
            << setfill(' ') << endl;
    }

public:

    static void ShowRegesterRecordScreen()
    {
        _DrawScreenHeader("Client List");

        vector<clsBankClient::stTransferRecord> vRecords = clsBankClient::vGetTransferLog();

        cout << "\n\t\t\t\t\tClient List (" << vRecords.size() << ") Client(s).";
        cout << "\n";
        _PrintSeparator();

        cout << "| " << left << setw(19) << "Date and Time"
            << "| " << setw(15) << "Client1 Acc No"
            << "| " << setw(15) << "Client2 Acc No"
            << "| " << setw(13) << "Transfer Amt"
            << "| " << setw(15) << "Client2 Amt"
            << "| " << setw(15) << "Client1 Amt"
            << "| " << setw(12) << "User Name"
            << " |" << endl;

        _PrintSeparator();

        if (vRecords.empty())
        {
            cout << "\t\t\t\tNo Records Available In the System!" << endl;
        }
        else
        {
            for (const auto& record : vRecords)
            {
                _PrintRow(record);
                _PrintSeparator();
            }
        }
    }
};
