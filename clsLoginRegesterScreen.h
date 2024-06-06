#pragma once

#include "Global.h"
#include "clsScreen.h"
#include "clsUsers.h"

class clsLoginRegesterScreen : protected clsScreen
{
private:

    static void _PrintRow(const clsUser::stRecords& record)
    {
        cout << left << "| " << setw(15) << record.user_name
            << "| " << setw(20) << record.time
            << "| " << setw(17) << record.password
            << "| " << setw(25) << record.date
            << "| " << setw(10) << record.permession
            << " |" << endl;
    }

    static void _PrintSeparator()
    {
        cout << setw(10) << " ";

        cout << left << setfill('-') << setw(99) << "-"
            << setfill(' ') << endl;
    }

public:

    static void ShowRegesterRecordScreen()
    {
        _DrawScreenHeader("Client List");

        vector<clsUser::stRecords> vRecords = clsUser::vGetLoginRecordsList();

        cout << "\nClient List (" << vRecords.size() << ") Client(s).";
        cout << "\n";
        _PrintSeparator();

        cout << setw(10) << " " << "| " << left << setw(15) << "User Name"
            << "| " << setw(20) << "Time"
            << "| " << setw(17) << "Password"
            << "| " << setw(25) << "Date"
            << "| " << setw(10) << "Permission"
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
                cout << setw(10) << " ";
                _PrintRow(record);
                _PrintSeparator();
            }
        }
    }
};
