#pragma once

#include <iostream>
#include <string>

#include "clsPerson.h"
#include "clsString.h"

#include <vector>
#include <fstream>

#include "clsEncryption.h"

using namespace std;

string ClientBasepath = "clients.database";

class clsBankClient : public clsPerson {
private:

	enum enMode
	{
		EmptyMode = 0,
		UpdateMode = 1,
		AddNewMode = 2
	};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;

	bool _MarkedForDelet = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Delimiter = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Delimiter);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], clsEncryption::DeEncrypt(vClientData[5]), stod(vClientData[6]));
	}
	
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "empty", "empty", "empty", "empty", "empty", "empty", 0);
	}

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClients;

		fstream Myfile;
		Myfile.open(ClientBasepath, ios::in);

		if (Myfile.is_open())
		{
			string Line;

			while (getline(Myfile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}

			Myfile.close();
		}

		return vClients;
	}

	static string _ConvertObjectsToLines(clsBankClient Client)
	{
		string Del = "#//#"; // Del = delimiter = "#//#"
		return Client.FirstName + Del + Client.LastName + Del + Client.Email + Del +
			Client.Phone + Del + Client.getAccountNumber() + Del 
			+ clsEncryption::Encrypt(Client.PIN) + Del + to_string(Client.AccountBalance);
	}

	static void _SaveClientDataToFile(vector<clsBankClient> _vClients)
	{
		fstream Myfile;
		string DataLine;
		Myfile.open(ClientBasepath, ios::out);
		if (Myfile.is_open())
		{
			for (clsBankClient& C : _vClients)
			{
				if (C._MarkedForDelet == false)
				{
					DataLine = _ConvertObjectsToLines(C);
					Myfile << DataLine << endl;
				}
				
			}
		}
		
	}

	void _Update()
	{
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C._AccountNumber == getAccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientDataToFile(_vClients);
	}

	static void _addDataLineToFile(string Line)
	{
		fstream Myfile;
		Myfile.open(ClientBasepath, ios::app);
		if (Myfile.is_open())
		{
			Myfile << Line << endl;
			Myfile.close();
		}
	}

	static void _addnew(clsBankClient Client)
	{
		_addDataLineToFile(_ConvertObjectsToLines(Client));
	}



public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccNumber, string PINCode, float AccountBalance);

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	struct stTransferRecord
	{
		string date;
		string Client1_account_number;
		string Client2_account_number;
		string Transfer_amount;
		string Client2_amount;
		string Client1_amount;
		string user_name;
	};

	static vector<stTransferRecord> vGetTransferLog()
	{
		vector<stTransferRecord> vRecords;
		vector<string> vLines;

		fstream Myfile;
		Myfile.open("TransferLog.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				vLines = clsString::Split(Line, "#//#");
				vRecords.push_back({vLines.at(0), vLines.at(1), vLines.at(2), vLines.at(3), vLines.at(4), vLines.at(5), vLines.at(6) });
			}

			Myfile.close();
		}

		return vRecords;
	}

	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
		string UserName, string Seperator = "#//#")
	{
		clsDate Date;
		string TransferLogRecord = "";
		TransferLogRecord += Date.getDateInstring() + " - " + Date.getClock() + Seperator;
		TransferLogRecord += getAccountNumber() + Seperator;
		TransferLogRecord += DestinationClient.getAccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{

		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		Whitdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);

		return true;
	}


	string getAccountNumber() // Account Number is read only member dont creat a set property !
	{
		return _AccountNumber;
	}

	string getPinCode()
	{
		return _PinCode;
	}

	float getAccountBalance()
	{
		return _AccountBalance;
	}

	void setPinCode(string PIN)
	{
		_PinCode = PIN;
	}

	void setAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	__declspec(property(get = getAccountBalance, put = setAccountBalance)) float AccountBalance;
	__declspec(property(get = getPinCode, put = setPinCode)) string PIN;

	void Print()
	{
		cout << "\nClientCard : ";
		cout << "\n===========================";
		cout << "\nFirstName      : " << FirstName;
		cout << "\nLast Name      : " << LastName;
		cout << "\nFull Name      : " << FullName();
		cout << "\nEmail          : " << Email;
		cout << "\nPhone          : " << Phone;
		cout << "\nAccount Number : " << getAccountNumber();
		cout << "\nPassword       : " << PIN;
		cout << "\nBalance        : " << AccountBalance;
		cout << "\n===========================";

		cout << endl;
	}

	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient> vClients;
		
		fstream Myfile;
		Myfile.open(ClientBasepath, ios::in);

		if (Myfile.is_open())
		{
			string Line;

			while (getline(Myfile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.getAccountNumber() == AccountNumber)
				{
					Myfile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			Myfile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string Accnumber, string PINCode)
	{
		vector<clsBankClient> vClients;

		fstream Myfile;
		Myfile.open(ClientBasepath, ios::in);

		if (Myfile.is_open())
		{
			string Line;

			while (getline(Myfile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.getAccountNumber() == Accnumber && Client.PIN == PINCode)
				{
					Myfile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			Myfile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccNumber);
		return (!Client.IsEmpty());
	}

	enum enSaveResult
	{
		svFailEmptyObject = 0,
		svSucceeded = 1,
		svFaildAccnumberExist = 2
	};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
			return enSaveResult::svFailEmptyObject;
			break;
		case clsBankClient::UpdateMode:
			_Update();
			return enSaveResult::svSucceeded;
			break;
		case clsBankClient::AddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResult::svFaildAccnumberExist;
			}
			else {
				_addnew(*this);
				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delet(string Accnumber)
	{
		vector<clsBankClient> vClients;
		vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.getAccountNumber() == Accnumber)
			{
				C._MarkedForDelet = true;
				break;
			}
		}

		_SaveClientDataToFile(vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static vector<clsBankClient> getClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double getTotaleBalances()
	{
		vector<clsBankClient> vClients = clsBankClient::getClientsList();

		double Totale = 0.000;

		for (clsBankClient& C : vClients)
		{
			Totale += C.AccountBalance;
		}
		return Totale;
	}

	void Deposit(double amount)
	{
		AccountBalance += amount;
		Save();
	}

	void Whitdraw(double amount)
	{
		AccountBalance -= amount;
		Save();
	}
};

clsBankClient::clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
	string AccNumber, string PINCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
{
	_Mode = Mode;
	_AccountNumber = AccNumber;
	_AccountBalance = AccountBalance;
	_PinCode = PINCode;
}