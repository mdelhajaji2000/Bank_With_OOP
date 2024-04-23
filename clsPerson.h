#pragma once

#include <iostream>
#include <string>

using namespace std;

class clsPerson {
private :

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public :

	clsPerson(string FirstName, string LastName, string Email, string PhoneNumber);

	string getFirstName()
	{
		return _FirstName;
	}

	string getLastName()
	{
		return _LastName;
	}

	string getEmail()
	{
		return _Email;
	}

	string getPhone()
	{
		return _Phone;
	}

	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

	void setLastName(string LastName)
	{
		_LastName = LastName;
	} 
	__declspec(property(get = getLastName, put = setLastName)) string LastName;

	void setEmail(string Email)
	{
		_Email = Email;
	}
	__declspec(property(get = getEmail, put = setEmail)) string Email;

	void setPhone(string Phone)
	{
		_Phone = Phone;
	}
	__declspec(property(get = getPhone, put = setPhone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void PrintPerson()
	{
		cout << "- First Name   : " << _FirstName << endl;
		cout << "- Last Name    : " << _LastName << endl;
		cout << "- Email	    : " << _Email << endl;
		cout << "- Phone Number : " << _Phone << endl;
	}


};

clsPerson::clsPerson(string FirstName, string LastName, string Email, string PhoneNumber)
{

	_FirstName = FirstName;
	_LastName = LastName;
	_Email = Email;
	_Phone = PhoneNumber;

}