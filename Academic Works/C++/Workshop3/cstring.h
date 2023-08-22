/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: May 17 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_

namespace sdds {

	void strCpy(char* des, const char* src);
	void strnCpy(char* des, const char* src, int len);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	int strLen(const char* s);
	const char* strStr(const char* str1, const char* str2);
	void strCat(char* des, const char* src);
}
#endif // !SDDS_CSTRING_H_



