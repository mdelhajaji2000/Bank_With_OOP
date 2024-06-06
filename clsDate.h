#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <vector>

using namespace std;

class clsDate
{
private:
    int year;
    int month;
    int day;

    int _Hour;
    int _minutes;
    int _Seconds;

    int _DaysInDate;

    static vector<int> GetDateFromString(string str, string Delemiter = "/")
    {
        string word;
        short pos = 0;
        vector<int> vWords;

        while ((pos = str.find(Delemiter)) != string::npos)
        {
            word = str.substr(0, pos);
            str.erase(0, pos + Delemiter.length());
            vWords.push_back(stoi(word));
        }
        if (str != "")
        {
            vWords.push_back(stoi(str));
        }
        return vWords;
    }

    static clsDate vectorToDate(vector<int> vDate)
    {
        clsDate Date;
        Date.day = vDate.at(0);
        Date.month = vDate.at(1);
        Date.year = vDate.at(2);

        return Date;
    }

    static int DayInWeekOrder(int year, int month, int day) {
        if (month < 3) {
            month += 12;
            year--;
        }
        int a = year / 100;
        int b = a / 4;
        int c = 2 - a + b;
        int d = year % 100;
        int e = 26 * (month + 1) / 10;
        int dayOfWeek = (day + e + d + d / 4 + c + 5) % 7;
        return dayOfWeek;
    }

    int DayInWeekOrder()
    {
        return DayInWeekOrder(year, month, day);
    }


public:

    clsDate();
    clsDate(int day, int month, int year);
    clsDate(string Date);
    clsDate(int Days, int Year);

    int GetDay()
    {
        return day;
    }

    int GetMonth()
    {
        return month;
    }

    int GetYear()
    {
        return year;
    }

    static clsDate stringToDate(string sDate)
    {
        vector<int> vDate = GetDateFromString(sDate);
        return vectorToDate(vDate);
    }

    clsDate stringToDateMember(string Date)
    {
        return stringToDate(Date);
    }

    string getDateInstring()
    {
        string Date;
        Date += to_string(day);
        Date += "/";
        Date += to_string(month);
        Date += "/";
        Date += to_string(year);
        return Date;
    }

    string getClock()
    {
        return to_string(_Hour) + ":" + to_string(_minutes) + ":" + to_string(_Seconds);
    }

    void print()
    {
        cout << day << "/" << month << "/" << year << endl;
    }

    static bool IsleapYear(short y)
    {
        return (y % 400 == 0 || y % 4 == 0) && (y % 100 != 0);
    }

    bool IsleapYear()
    {
        return IsleapYear(year);
    }

    static int DaysInmonth(int month, int year)
    {
        bool isleap;
        isleap = IsleapYear(year);
        if (month == 2 && isleap) return 29;
        else if (month == 2) return 28;
        else if (month % 2 == 0) return 30;
        return 31;
    }

    int DaysInmonth()
    {
        return DaysInmonth(month, year);
    }

    static int hoursInMonths(int DaysInmonth)
    {
        return DaysInmonth * 24;
    }

    int hoursInMonths()
    {
        return hoursInMonths(DaysInmonth(day, year));
    }

    static int minutesInMonths(int hoursInMonths)
    {
        return hoursInMonths * 60;
    }

    int minutesInMonths()
    {
        return minutesInMonths(hoursInMonths());
    }

    static int SecondsInmonth(int minutesInMonths)
    {
        return minutesInMonths * 60;
    }

    int SecondsInmonth()
    {
        return SecondsInmonth(minutesInMonths());
    }

    static int DaysToseconds(short NumberofDays) {
        return  NumberofDays * 24 * 60 * 60;
    }

    static int DaysInDate(int year, int month, int day) {
        int DaysSum = day; // Start with the given day

        // Loop through the months preceding the given month
        for (int i = month - 1; i >= 1; --i) {
            DaysSum += DaysInmonth(i, year); // Add days in each preceding month
        }

        return DaysSum;
    }

    int DaysInDate() const
    {
        return _DaysInDate;
    }


    int DaysToseconds()
    {
        return DaysToseconds(_DaysInDate);
    }

    static int DaysToHours(short NumberofDays) {

        return  NumberofDays * 24;
    }

    int DaysToHours()
    {
        return DaysToHours(_DaysInDate);
    }

    static int DaysToMinutes(short NumberofDays) {

        return NumberofDays * 24 * 60;
    }

    int DaysToMinutes()
    {
        return DaysToMinutes(_DaysInDate);
    }

    static int Daypos(int year, int month, int day)
    {
        if (month < 3) {
            year--;
            month += 12;
        }

        int a = year / 100;
        int b = year % 100;

        return (day + (13 * (month + 1)) / 5 + b + (b / 4) + (a / 4) - 2 * a) % 7;
    }

    int Daypos()
    {
        return Daypos(year, month, day);
    }

    static string DayShortName(int daypos)
    {
        string Week[7] = { "Satur", "Mon", "Tue", "Wed", "Thu", "Fri", "Sun" };
        return Week[daypos];
    }

    string DayShortName()
    {
        return DayShortName(Daypos(year, month, day));
    }

    static string MonthShortName(int month) {
        string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return months[month - 1];
    }

    string MonthShortName()
    {
        return MonthShortName(month);
    }

    static clsDate totalDaysToDate(short totalDays, short year)
    {
        clsDate date;

        date.year = year;
        date.month = 1;

        while (totalDays > DaysInmonth(date.month, year))
        {
            totalDays -= DaysInmonth(date.month, year);
            date.month++;
        }

        date.day = totalDays;

        return date;
    }

    static bool IsDate1EqualDate2(clsDate date1, clsDate date2)
    {
        return  (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
    }

    bool IsDate1EqualDate2(clsDate Date2)
    {
        return IsDate1EqualDate2(*this, Date2);
    }

    static int GetLastDayinMonth(int year, int month)
    {
        int LastDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (month == 2 && IsleapYear(year)) ? 29 : LastDay[month - 1];
    }

    int GetLastDayinMonth()
    {
        return GetLastDayinMonth(this->year, this->month);
    }

    static bool Is_Last_Day_In_month(int year, int month, int Day)
    {
        return Day == GetLastDayinMonth(year, month);
    }

    bool Is_Last_Day_In_month()
    {
        return Is_Last_Day_In_month(this->year, this->month, this->day);
    }

    static bool Is_Last_Month_In_Year(int month)
    {
        return month == 12;
    }

    bool Is_Last_Month_In_Year()
    {
        return Is_Last_Month_In_Year(this->month);
    }

    static bool IsLastDayInMonth(clsDate Date)
    {
        return (Date.day == DaysInmonth(Date.month, Date.year));
    }

    static clsDate IncreaseDateByOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (Is_Last_Month_In_Year(Date.month))
            {
                Date.month = 1;
                Date.day = 1;
                Date.year++;
            }
            else {
                Date.day = 1;
                Date.month++;
            }
        }
        else {
            Date.day++;
        }

        return Date;
    }

    clsDate IncreaseDateByOneDay()
    {
        return IncreaseDateByOneDay(*this);
    }

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {
        return (Date1.year < Date2.year) ? true :
            (Date1.year > Date2.year) ? false :
            (Date1.month < Date2.month) ? true :
            (Date1.month > Date2.month) ? false :
            (Date1.day < Date2.day);
    }

    static bool IsDate1AftereDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.year < Date2.year) ? false :
            (Date1.year > Date2.year) ? true :
            (Date1.month < Date2.month) ? false :
            (Date1.month > Date2.month) ? true :
            (Date1.day > Date2.day);
    }

    bool IsDate1AftereDate2(clsDate Date2)
    {
        return IsDate1AftereDate2(*this, Date2);
    }

    bool IsDate1BeforeDate2(clsDate Date2)
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static void SwapDates(clsDate& Date1, clsDate& Date2)
    {
        clsDate TempDate;
        TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;
    }

    static int GetDiferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        short SwapFlagValue = 1;
        if (!IsDate1BeforeDate2(Date1, Date1))
        {
            SwapDates(Date1, Date2);
            SwapFlagValue = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }

        Days *= SwapFlagValue;

        return IncludeEndDay ? ++Days : Days;
    }

    int GetDiferenceInDays(clsDate Date2, bool IncludeLastDay = false)
    {
        return GetDiferenceInDays(*this, Date2, IncludeLastDay);
    }

    static clsDate getActualDate()
    {
        clsDate Date;

        time_t t = time(0);
        tm* now = localtime(&t);

        Date.year = now->tm_year + 1900;
        Date.month = now->tm_mon + 1;
        Date.day = now->tm_mday;

        return Date;
    }

    static void increaseDateByXDays(clsDate& Date, int X)
    {
        for (int i = 0; i < X; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
    }

    void increaseDateByXDays(int X)
    {
        increaseDateByXDays(*this, X);
    }

    static void increaseDateByOneWeek(clsDate& Date)
    {
        increaseDateByXDays(Date, 7);
    }

    void increaseDateByOneWeek()
    {
        increaseDateByOneWeek(*this);
    }

    static void increaseDateByXWeeks(clsDate& Date, int X)
    {
        for (int i = 0; i < X; i++)
        {
            increaseDateByOneWeek(Date);
        }
    }

    void increaseDateByXWeeks(int X)
    {
        increaseDateByXWeeks(*this, X);
    }

    static void IncreaseDateByOnemonth(clsDate& Date)
    {
        if (Date.month == 12)
        {
            Date.month = 1;
            Date.year++;
        }
        else
        {
            Date.month++;
        }

        int daysInNextMonth = DaysInmonth(Date.month, Date.year);
        if (Date.day > daysInNextMonth)
        {
            Date.day = daysInNextMonth;
        }
    }

    void IncreaseDateByOnemonth()
    {
        IncreaseDateByOnemonth(*this);
    }

    static void IncreaseDateByXMonth(clsDate& Date, int X)
    {
        for (int i = 0; i < X; i++)
        {
            IncreaseDateByOnemonth(Date);
        }
    }

    void IncreaseDateByXMonth(int X)
    {
        IncreaseDateByXMonth(*this, X);
    }

    static void IncreaseDateByOneYear(clsDate& Date)
    {
        if (Date.month == 2 && !IsleapYear(Date.year) && Date.day == 29)
        {
            Date.day = 28; // Move to the last day of February for non-leap years
        }
        Date.year++; // Increment the year
    }

    void IncreaseDateByOneYear()
    {
        IncreaseDateByOneYear(*this);
    }

    static void IncreaseDateByXYears(clsDate& Date, int X)
    {
        for (int i = 0; i < X; i++)
        {
            IncreaseDateByOneYear(Date);
        }
    }

    void IncreaseDateByXYears(int X)
    {
        IncreaseDateByXYears(*this, X);
    }

    static bool IsFristDayInMonth(clsDate Date)
    {
        return (Date.day == 1);
    }

    static bool IsFristMonthInYear(short month)
    {
        return (month == 1);
    }

    static clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (IsFristDayInMonth(Date))
        {
            if (IsFristMonthInYear(Date.month))
            {
                Date.year--;
                Date.month = 12;
                Date.day = 31;
            }
            else {
                Date.month--;
                Date.day = DaysInmonth(Date.month--, Date.year);
            }
        }
        else {
            Date.day--;
        }

        return Date;
    }

    void DecreaseDateByOneDay()
    {
        *this = DecreaseDateByOneDay(*this);
    }

    static bool IsendOfWeek(clsDate Date)
    {
        return Daypos(Date.year, Date.month, Date.day) == 6;
    }

    static bool IsWeekend(clsDate Date)
    {
        return (IsendOfWeek(Date) || Daypos(Date.year, Date.month, Date.day) == 5);
    }

    static bool IsBusinessDay(clsDate Date)
    {
        return !IsWeekend(Date);
    }

    static int DaysUntillEndOfWeek(clsDate Date)
    {
        if (IsWeekend(Date)) return 0;
        return 7 - Daypos(Date.year, Date.month, Date.day);
    }

    static int DaysUntillEndOfMonth(clsDate Date)
    {
        return DaysInmonth(Date.month, Date.year) - Date.day;
    }

    int DaysUntillEndOfYear(clsDate AcDate) // AcDate Actual Date
    {
        clsDate End_Of_year;
        End_Of_year.day = 31;
        End_Of_year.month = 12;
        End_Of_year.year = AcDate.year;
        return GetDiferenceInDays(AcDate, End_Of_year);
    }

    // add : DateAfterDate - DateBeforeDate - ComparDates //

    friend class clsCalander;
};

clsDate::clsDate()
{
    time_t now = time(nullptr);
    tm* timeinfo = localtime(&now);

    this->day = timeinfo->tm_mday;
    this->month = timeinfo->tm_mon + 1;
    this->year = timeinfo->tm_year + 1900;
    this->_DaysInDate = DaysInDate(this->year, this->month, this->day); // Compute days since January 1st

    this->_Hour = timeinfo->tm_hour;
    this->_minutes = timeinfo->tm_min;
    this->_Seconds = timeinfo->tm_sec;
}

clsDate::clsDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
    this->_DaysInDate = DaysInDate(year, month, day); // Compute days since January 1st
}

clsDate::clsDate(string Date)
{
    *this = stringToDate(Date);
    this->_DaysInDate = DaysInDate(this->year, this->month, this->day); // Compute days since January 1st
}

clsDate::clsDate(int Days, int Year)
{
    *this = totalDaysToDate(Days, Year);
}