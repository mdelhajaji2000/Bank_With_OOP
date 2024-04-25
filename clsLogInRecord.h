#pragma once

#include <string>

#include "clsUsers.h"
#include "Global.h"
#include "clsDate.h"

const string filepath = "LogInRecords.txt";

class clsLogInRecord
{
private:

	static string CreatRecord()
	{
		clsDate Date = clsDate();
		string record =  to_string(Date.GetYear()) + "/" + to_string(Date.GetMonth()) + "/" + to_string(Date.GetDay());
		record += " - " + Date.getClock();
		record += " - " + CurrentUser.UserName + " # " + CurrentUser.Password + " # " + to_string(CurrentUser.Permissions);

		return record;
	}

public:

	static void AddUserRecordToFile()
	{
		fstream Myfile;
		Myfile.open(filepath, ios::app);
		if (Myfile.is_open())
		{
			Myfile << CreatRecord() << endl;
			Myfile.close();
		}
	}
};

