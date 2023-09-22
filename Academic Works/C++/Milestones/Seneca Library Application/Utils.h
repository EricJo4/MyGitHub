/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 1.1
// Date	July 11 2023
// Author Eric Jo
// Description Milestone 5
//
// Revision History
// -----------------------------------------------------------
// Name Eric Jo           Date Aug 6, 2023           Reason Added getIntegerInput(int low, int high)
// 
/////////////////////////////////////////////////////////////////
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
***********************************************************************/

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
namespace sdds {

	void strCpy(char* des, const char* src);
	void strnCpy(char* des, const char* src, int len);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	int strLen(const char* s);
	const char* strStr(const char* str1, const char* str2);
	void strCat(char* des, const char* src);
	void clearInputBuffer(std::istream& is);
	void clearUntilDelimeter(std::istream& is);
	int getIntegerInput(int low, int high);
}
#endif // SDDS_UTILS_H__
