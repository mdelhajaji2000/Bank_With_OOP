#pragma once

#include <iostream>
#include <string>

using namespace std;

class clsEncryption
{
private:

	static const int EnCode = 4377809;

	static string _Encrypt(string str)
	{
		for (int i = 0; i < str.length(); i++)
			str[i] += EnCode;
		return str;
	}

	static string _Decrypt(string str)
	{
		for (int i = 0; i < str.length(); i++)
			str[i] -= EnCode;
		return str;
	}

public:

	static string Encrypt(string str)
	{
		return _Encrypt(str);
	}

	static string DeEncrypt(string str)
	{
		return _Decrypt(str);
	}

};

