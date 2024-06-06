#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsCurrency
{
private:

	string Country_Code;
	string Country_Name;
	int Value$;

	vector<string> _FileData_ToVectorOfLines()
	{

		vector<string> vLines;

		fstream Myfile;
		Myfile.open("Currency", ios::in);
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				vLines.push_back(Line);
			}
		}
	}

	vector<clsCurrency> vCountry_List()
	{
		vector<clsCurrency> vCountry;
		vector<string> SplitVector;


	}

public:


};

