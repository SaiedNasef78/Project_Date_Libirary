#pragma once
#pragma warning (disable:4996)
#include <string>
#include <ctime>
#include <iostream>
#include "clsDate.h"
#include "clsString.h"

using namespace std;
class clsPeriode
{
private:
	clsDate StartDate;
	clsDate EndDate;
public :
	
	clsPeriode(clsDate Date1, clsDate Date2) {
		StartDate = Date1;
		EndDate = Date2;
	}
	void setStartDate(clsDate _StartDate) {
		StartDate = _StartDate;

	}
	clsDate getStartDate() {
		return StartDate;
	}
	__declspec(property(get = getStartDate, put = setStartDate)) clsDate startdate;
	void setENdDate(clsDate _EndDate) {
		EndDate = _EndDate;

	}
	clsDate getEndDate() {
		return EndDate;
	}
	__declspec(property(get = getEndDate, put = setENdDate)) clsDate enddate;
	static bool IsOverLap(clsPeriode Periode1, clsPeriode  Periode2) {
		if (clsDate::CompareDates(Periode2.enddate, Periode1.startdate) == clsDate::enDaste1AndDate2::Before ||
		clsDate::CompareDates(Periode2.startdate, Periode1.enddate) == clsDate::enDaste1AndDate2::After)
			return false;
		else
			return true;

	}

	void Is_OverLap( clsPeriode  Periode2) {
		if (IsOverLap(*this, Periode2)) {

			cout << "\n\nYes,OverLap";

		}
		else {
			cout << "\n\nNo,OverLap";
		}

	}
	static short CalculatePeriodeLengthInDays(clsPeriode Periode, bool IncludingDay = false) {

		return  clsDate::GetDifferenceInDays(Periode.StartDate, Periode.EndDate, IncludingDay);


	}
	short CalculatePeriodeLengthInDays(bool IncludingDay = false) {
		return CalculatePeriodeLengthInDays(*this, IncludingDay );
	}
	static bool ThenCheckPeriode(clsPeriode Periode,clsDate Date) {


		/*return ((MyDate::CompareDates(Periode.StartDate, Date) == MyDate::enDaste1AndDate2::Before )&&
		   ( MyDate::CompareDates(Date, Periode.EndDate)==MyDate::enDaste1AndDate2::Before));*/


		return !(clsDate::CompareDates(Date, Periode.StartDate) == clsDate::enDaste1AndDate2::Before || clsDate::CompareDates(Date, Periode.EndDate) == clsDate::enDaste1AndDate2::After);
	}
	void  ThenCheckPeriode(clsDate Date) {

		if (ThenCheckPeriode(*this, Date)) {

			cout << "\n\nYes, Date Is within periode";
		}
		else {
			cout << "\n\nNo,Date is within periode";
		}
	}
	static bool IsOverLapDate(clsDate Date, clsPeriode Periode2) {
		return(clsDate::CompareDates(Date, Periode2.StartDate) == clsDate::enDaste1AndDate2::Before ||

			clsDate::CompareDates(Date, Periode2.EndDate) == clsDate::enDaste1AndDate2::After);


	}

	static short Count_OverLap(clsPeriode Periode1, clsPeriode Periode2) {
		short lengthOverP1 = CalculatePeriodeLengthInDays(Periode1, true);
		short lengthOverP2 = CalculatePeriodeLengthInDays(Periode2, true);
		short CountLength = 0;

		if (!IsOverLap(Periode1, Periode2))
			return 0;
		if (lengthOverP1 < lengthOverP2) {

			while (clsDate::IsDate1BeforeDate2(Periode1.startdate, Periode1.enddate)) {

				if (IsOverLapDate(Periode1.startdate, Periode2))
					CountLength++;
				Periode1.startdate = clsDate::AddOneDay(Periode1.startdate);

			}



		}
		else {


			while (clsDate::IsDate1BeforeDate2(Periode2.startdate, Periode2.enddate)) {

				if (IsOverLapDate(Periode2.startdate, Periode1)) {
					CountLength++;
				}
				Periode2.startdate = clsDate::AddOneDay(Periode2.startdate);

			}


		}


		return CountLength;


	}
	short CountOverLap(clsPeriode Periode1)
	{
		return Count_OverLap(*this, Periode1);

	}
	
};

