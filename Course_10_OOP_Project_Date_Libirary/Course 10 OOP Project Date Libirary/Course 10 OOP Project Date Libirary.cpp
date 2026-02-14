// Course 10 OOP Project Date Libirary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsDate.h"
#include "clsPeriode.h"
using namespace std;
int main()
{
    clsDate Date2;
    Date2.Print();
    Date2.PrintNumberOfDays(Date2);
    clsDate Date1(225, 2022);
    Date1.Print();
    cout << "\\";
    cout << Date1.GetDifferenceInDays(Date2) << endl;;
    
    Date2.NumberOfDaysFromTheBeginingOfTheYear();
    Date1.IsDate1BeforeDate2(Date2);
  Date2=  Date2.AddDyasToDate(222,Date2);
    Date2.Print();
    Date1.SwaapDate(Date2);
    Date1.Print();
    Date2.Print();
   

 
   Date1.IncreaseDateByOneWeek();
     Date1.Print();
     Date1.IncreaseDateByOneWeek();
     Date1.Print();
     Date2.IncreaseDateBy_X_Weeks(2);
     Date2.Print();
     Date2.IncreaseDateBy_X_DecadFaster(2);
     Date2.Print();
     clsDate Date3;
     Date3.Print();
     Date3.AddOneDay();
     Date3.Print();
    
     Date3.DayUntilTheEndOfWeek();
     Date3.IsWeekend();
     Date3.Print();
     clsDate Date4(222, 2023);
     clsDate Date5(2, 3, 2026);
     clsDate Date6("1/2/2022");
     clsPeriode Periode1(Date4,Date2);
     clsPeriode Periode2(Date6, Date5);
     cout << "\nDate2: ";
     Date2.Print();
     cout << "Date3: ";
     Date3.Print();
     cout << "Date4: ";
     Date4.Print();
     cout << "Date5: ";
     Date5.Print();
     cout << "Date6: ";
     Date6.Print();
     Periode1.Is_OverLap(Periode2);
     cout << "\nLength In Days: ";
     cout << endl << Periode2.CalculatePeriodeLengthInDays();
     Periode1.ThenCheckPeriode(Date4);
     cout << endl;
   cout <<"Count Over Lap: "  << Periode1.CountOverLap(Periode2);
   string Formatting;
   Formatting=Date2.PrintFormatDate("dd/mm/yyyy");
   cout << "\nFormatting: " << Formatting << endl;
   Date3.IsDate1BeforeDate2(Date2);
    system("pause>0");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
