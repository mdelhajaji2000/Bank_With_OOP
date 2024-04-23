#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <limits.h>

#include "clsDate.h"
#include "clsUtility.h"
#include "clsString.h"

#define RESET       "\033[0m        "      /* Rest To Default */
#define BLACK       "\033[30m       "      /* Black           */
#define RED         "\033[31m       "      /* Red             */
#define GREEN       "\033[32m       "      /* Green           */
#define YELLOW      "\033[33m       "      /* Yellow          */
#define BLUE        "\033[34m       "      /* Blue            */
#define MAGENTA     "\033[35m       "      /* Magenta         */
#define CYAN        "\033[36m       "      /* Cyan            */
#define WHITE       "\033[37m       "      /* White           */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black      */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red        */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green      */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow     */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue       */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta    */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan       */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White      */

using namespace std;


class clsInputValidate
{
public:
    static bool IsNumberBetween(int num1, int num_between, int num2)
    {
        return (num_between > num1 && num_between < num2);
    }

    static bool IsDateBetween(clsDate Date1, clsDate Date_between, clsDate Date2)
    {
        return (clsDate::IsDate1BeforeDate2(Date1, Date_between) && clsDate::IsDate1AftereDate2(Date2, Date_between));
    }

    static int ReadIntNumber(string ErrMessage = "Unvalid Input (Please Enter an integer")
    {
        int ErrMessageCounter = 0;
        int num;
        cin >> num;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
            cout << RED;
            if (ErrMessageCounter == 0) cout << ErrMessage;
            ErrMessageCounter++;
            cout << "Try again! : ";
            cout << RESET;
            cin >> num; // Read input again
        }
        return num;
    }


    static int ReadNumberBetwin(int x, int y, string ErrMessage)
    {
        int num = ReadIntNumber();

        while (num < x || num > y)
        {
            cout << ErrMessage << endl;
            num = ReadNumberBetwin(x, y, ErrMessage);
        }

        return num;
    }

    static double ReadDb(string ErrMessage = "Input Entred Isnt a Double ! ")
    {
        double num;
        cin >> num;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
            cout << RED;
            cout << ErrMessage;
            cout << "Try again! : ";
            cout << RESET;
            cin >> num; // Read input again
        }
        return num;
    }

    static bool IsValideDate(clsDate Date, bool PrintValidation = false)
    {
        if (Date.GetDay() != Date.DaysInmonth() || Date.GetMonth() > 12 || Date.GetMonth() < 1)
        {
            if (PrintValidation)cout << "Unvalid Date !" << endl;
            return false;
        }
        if (PrintValidation) cout << "Valid Date !" << endl;
        return true;
    }

    static string ReadString()
    {
        string  S1 = "";
        getline(cin >> ws, S1);
        return S1;
    }

    static bool ReadYandN(string Message)
    {
        char answer;
        cout << Message;
        cin >> answer;

        while ((toupper(answer) != 'Y') && (toupper(answer) != 'N'))
        {
            cout << Message;
            cin >> answer;
        }

        if (toupper(answer) != 'Y')
            return false;
        else
        {
            return true;
        }
    }
};
