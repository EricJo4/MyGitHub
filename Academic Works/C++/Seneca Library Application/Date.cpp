// Final Project Milestone 5
// Date Module
// File	Date.cpp
// Version 1.2
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name  Eric Jo             Date  July 11, 2023           Reason  Creating task functions for submission
// Name  Eric Jo             Date  July 27, 2023           Reason  Removed Flushing the inputbuffer at read function, added some global variables, and changed systemYear and setToToday
/*I have done all the coding by myselfand only copied the code
that my professor provided to complete my workshopsand assignments.
------------------------------------------------------------*/
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include "Utils.h"
namespace sdds {
    bool sdds_test = false;
    int sdds_year = 2023;
    int sdds_mon = 12;
    int sdds_day = 25;

    // Validates the date setting the error code andthen returns true, if valid, and false if invalid.
   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   //returns the number of days in current month (the month stored in m_mon attribute)
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   //Sets the error code value
   int Date::systemYear()const {
       int theYear = sdds_year;
       if (!sdds_test) {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           theYear = lt.tm_year + 1900;
       }
       return theYear;
   }
   //Sets the date to the current date(system date)
   void Date::setToToday() {
       if (sdds_test) {
           m_day = sdds_day;
           m_mon = sdds_mon;
           m_year = sdds_year;
       }
       else {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           m_day = lt.tm_mday;
           m_mon = lt.tm_mon + 1;
           m_year = lt.tm_year + 1900;
       }
       errCode(NO_ERROR);
   }
   //Returns number of days passed since the date 0001/01/01
   int Date::daysSince0001_1_1()const {
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   //Creates a date with current date
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   //Creates a date with assigned values then validates the date and sets the error code accordingly
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   //Returns a string stating the current status of the date
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   //Returns the m_CUR_YEAR attribute value
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }
   //Change m_ErrorCode with the argument
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }
   //Returns the error code or zero if date is valid
   int Date::errCode()const {
      return m_ErrorCode;
   }
   //Returns if the values are invalid
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }

   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }

   //tasks
   //Read year, month, and day from input stream
   istream& Date::read(istream& is) {
       errCode(NO_ERROR);
       is.clear();
       is >> m_year;
       clearUntilDelimeter(is); //Ignores characters in the input stream until slash ('/') character.
       is >> m_mon;
       clearUntilDelimeter(is);
       is >> m_day;
       
       
       if (is.fail()) {
           errCode(CIN_FAILED);
           is.clear();
          
           
       }

       else {
           validate(); //validate if it has an error
       }
       
       
       return is;
   }

   //Print date on the console
   ostream& Date::write(ostream& os)const {
       if (m_ErrorCode != 0) {
           os << dateStatus();
       }
       else {
           os << m_year << '/';
           os.width(2);
           if (m_mon < 10) {
               os.fill('0');
           }
           os << std::right << m_mon;
           os << '/';
           os.width(2);
           if (m_day < 10) {
               os.fill('0');
           }
           os << std::right << m_day;
           os.fill(' ');
       }
       return os;
   }
   //Comparison Operators
   bool Date::operator==(const Date& right)const {
       return (m_year == right.m_year && m_mon == right.m_mon && m_day == right.m_day);
       
   }
   bool Date::operator!=(const Date& right)const {
       return !(m_year == right.m_year && m_mon == right.m_mon && m_day == right.m_day);
   }
   bool Date::operator>=(const Date& right)const {
       return (daysSince0001_1_1() >= right.daysSince0001_1_1());
   }
   bool Date::operator<=(const Date& right)const {
       return (daysSince0001_1_1() <= right.daysSince0001_1_1());
   }
   bool Date::operator<(const Date& right)const {
       return (daysSince0001_1_1() < right.daysSince0001_1_1());
   }
   bool Date::operator>(const Date& right)const {
       return (daysSince0001_1_1() > right.daysSince0001_1_1());
   }
   int Date::operator-(const Date& right)const {
       return daysSince0001_1_1() - right.daysSince0001_1_1();
   }
   Date::operator bool()const {
       return !bad();
   }

}
