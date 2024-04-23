#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsString
{
private:
	string _value;

public:

	clsString()
	{
		_value = "";
	}

	clsString(string value)
	{
		_value = value;
	}

	void setValue(string value)
	{
		_value = value;
	}

	string getvalue()
	{
		return _value;
	}

	static string readstring(string message = "enter string : ")
	{
		string str;
		cout << message;
		getline(cin, str);
		return str;
	}

	static short lenght(string str)
	{
		return str.length();
	}

	// short lenght()
	// {
	// 	return lenght(this->value);
	// }

	static void PrintFirstChar(string txt)
	{
		// Check if the string is not empty
		if (!txt.empty()) {
			// Print the first character of the string
			cout << txt[0];

			// Loop through the characters of the string
			for (int i = 1; i < txt.length(); i++)
			{
				// If the current character is preceded by a space, print it
				if (txt[i - 1] == ' ' && txt[i] != ' ')
					cout << txt[i] << endl;
			}
		}
	}

	void PrintFristChar(string text)
	{
		PrintFirstChar(_value);
	}

	static string UpperFirstChar(string txt)
	{
		// Check if the string is not empty
		if (!txt.empty()) {
			// Convert the first character to uppercase
			txt[0] = toupper(txt[0]);

			// Loop through the characters of the string
			for (int i = 1; i < txt.length(); i++)
			{
				// If the current character is preceded by a space, convert it to uppercase
				if (txt[i - 1] == ' ')
					txt[i] = toupper(txt[i]);
			}
		}

		return txt;
	}

	string UpperFirstChar()
	{
		return UpperFirstChar(_value);
	}

	static string LowerFirstChar(string txt)
	{
		// Check if the string is not empty
		if (!txt.empty()) {
			// Convert the first character to lowercase
			txt[0] = tolower(txt[0]);

			// Loop through the characters of the string
			for (int i = 1; i < txt.length(); i++)
			{
				// If the current character is preceded by a space, convert it to lowercase
				if (txt[i - 1] == ' ')
					txt[i] = tolower(txt[i]);
			}
		}

		return txt;
	}

	string LowerFirstChar()
	{
		return LowerFirstChar(_value);
	}

	static string UpperCase(string txt)
	{
		for (int i = 0; i < txt.length(); i++)
		{
			txt[i] = toupper(txt[i]);
		}
		return txt;
	}

	string UpperCase()
	{
		return UpperCase(_value);
	}

	static	string LowCase(string txt)
	{
		for (int i = 0; i < txt.length(); i++)
		{
			txt[i] = tolower(txt[i]);
		}
		return txt;
	}

	string LowCase()
	{
		return LowCase(_value);
	}

	static string CheckCase(char c)
	{
		if (c >= 'A' && c <= 'Z') return "Upper";
		else if (c >= 'a' && c <= 'z') return "Lower";
		return "Not a Letter";
	}

	static string InvertString(string txt)
	{
		for (int i = 0; i < txt.length(); i++)
		{
			if (CheckCase(txt[i]) == "Upper") txt[i] = char(tolower(txt[i]));
			else if (CheckCase(txt[i]) == "Lower") txt[i] = char(toupper(txt[i]));
		}

		return txt;
	}

	string InvertString()
	{
		return InvertString(_value);
	}

	static int SmallLetterCounter(string text)
	{
		int Counter = 0;
		for (int i = 0; i < text.length(); i++)
		{
			if (CheckCase(text[i]) == "Lower")Counter++;
		}
		return Counter;
	}

	int SmallLetterCounter()
	{
		return SmallLetterCounter(_value);
	}

	static int CapitaleCounter(string text)
	{
		int Counter = 0;
		for (int i = 0; i < text.length(); i++)
		{
			if (CheckCase(text[i]) == "Upper") Counter++;
		}
		return Counter;
	}

	int CapitaleCounter()
	{
		return CapitaleCounter(_value);
	}

	static int CharacterCounter(string text, char Character)
	{
		int Counter = 0;
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] == Character) Counter++;
		}
		return Counter;
	}

	int CharacterCounter(char character)
	{
		return CharacterCounter(_value, character);
	}

	static bool CheckVoyel(char c)
	{
		return (c == 'a' || c == 'o' || c == 'i' || c == 'u' || c == 'y' || c == 'e');
	}

	static int VoyelCounter(string text)
	{
		int Counter = 0;
		for (int i = 0; i < text.length(); i++)
		{
			if (CheckVoyel(text[i])) Counter++;
		}
		return Counter;
	}

	int VoyelCounter()
	{
		return VoyelCounter(_value);
	}


	static short CountWordsInString(string s1)
	{
		string Delim = " ";

		short counter = 0;
		short Pos = 0;
		string sWord;

		while ((Pos = s1.find(Delim)) != std::string::npos)
		{
			sWord = s1.substr(0, Pos);
			if (sWord != "")
			{
				counter++;
			}
			s1.erase(0, Pos + Delim.length());

		}

		if (s1 != "")
		{
			counter++;
		}


		return counter;

	}

	short CountWordsInString()
	{
		return CountWordsInString(_value);
	}

	static vector<string> Split(string S1, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			// if (sWord != "")
			// {
			vString.push_back(sWord);
			//}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}

	vector<string> Split(string Delim)
	{
		return Split(_value, Delim);
	}

	static string ReveaseStringWords(string s1, string Delim)
	{
		short pos = 0;
		string s1Revesed = "";

		for (int i = s1.length(); i >= 0; i--)
		{
			if (s1[i] == ' ')
			{
				s1Revesed += s1.substr(i + 1, s1.length()) + Delim;
				s1.erase(i, s1.length());
			}
		}
		s1Revesed += s1.substr(0, s1.length());
		return s1Revesed;

	}

	string ReverseStringWords(string Delimiter)
	{
		return ReverseStringWords(Delimiter);
	}


	static string LowerAllString(string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			s = tolower(s.at(i));
		}
		return s;
	}

	static string ReplaceWordInString(string s1, string WordToReplace, string sReplaceTo, bool MatchCase = true)
	{
		string s2;
		vector<string>vstring;
		vstring = Split(s1, " ");



		for (string vWord : vstring)
		{
			if (MatchCase)
			{
				if (WordToReplace == vWord)
				{

					vWord = sReplaceTo;

				}
			}
			else
			{
				if (LowerAllString(WordToReplace) == LowerAllString(vWord))
				{
					vWord = sReplaceTo;
				}
			}


			s2 += vWord + " ";
		}

		return s2.substr(0, s2.length() - 1);

	}


	string ReplaceWordInString(string WordToReplace, string WordToReplace_with)
	{
		return ReplaceWordInString(_value, WordToReplace, WordToReplace_with);
	}

	static bool IsPunctiation(char c)
	{
		return ispunct(c);
	}

	static string RemovePunc(string text)
	{
		for (int i = text.length() - 1; i >= 0; --i)
		{
			if (ispunct(text[i]))
			{
				text.erase(i, 1); // erase 1 character at position i
			}
		}

		return text;
	}

	string RemovePunc()
	{
		return RemovePunc(_value);
	}
	// use this properity if you use microsoft C++ Compiler (Vs Community)
	__declspec(property(get = getvalue, put = setValue)) string value;
};

