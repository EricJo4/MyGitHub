/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version 1.0
// Date July 11 2023
// Author Eric Jo
// Description Milestone 4
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
***********************************************************************/

#include "Utils.h"
namespace sdds {
	// Copies the source character string into the destination
	void strCpy(char* des, const char* src) {
		int i;
		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len) {
		int i;
		for (i = 0; i < len || src[i] != '\0'; i++) {
			des[i] = src[i];
		}

	}

	// Compares two C-strings 
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2) {
		int i;
		for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
			if (s1[i] != s2[i]) {
				return s1[i] - s2[i];
			}
		}

		return 0;
	}

	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len) {
		int i;
		for (i = 0; i < len; i++) {
			if (s1[i] != s2[i]) {
				return s1[i] - s2[i];
			}
		}
		return 0;
	}

	// returns the lenght of the C-string in characters
	int strLen(const char* s) {
		int i;
		for (i = 0; s[i] != '\0'; i++);
		return i;
	}

	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2) {
		int i;
		int j;
		int str2Len;
		int occurance;
		int matched = 0;

		// if str2 has no value, return nullptr
		if (*str2 == '\0') {
			return nullptr;
		}
		for (str2Len = 0; str2[str2Len] != '\0'; str2Len++);
		// i will be a position of first occurance of str2 in str1
		for (i = 0; str1[i] != '\0'; i++) {
			if (str1[i] == str2[0]) {
				occurance = i; // occurance variable gets the value of i

				// How many characters on str2 are matched with the ones from the first occurance position in str1?
				for (j = 0; j < str2Len; i++, j++) {
					if (str1[i] == str2[j]) {
						matched++;
					}
					// if all characters of str2 are matched with the ones from the frist occurance position in str1, return str1 + occurance.
					if (matched == str2Len) {
						str1 = str1 + occurance;
						return str1;
					}
				}
			}
		}
		return nullptr; // no matches, return nullptr
	}

	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src) {
		int desLen;
		int i;

		for (desLen = 0; des[desLen] != '\0'; desLen++);

		for (i = 0; src[i] != '\0'; i++) {
			des[desLen + i] = src[i];
		}

		des[desLen + i] = '\0';
	}

	//Ignores characters until it encounters new line character 
	void clearInputBuffer(std::istream& is) {
		while (is.peek() != '\n' && is.good()) {
			is.ignore();
		}
	}

	//Ignores characters until it encounters designated delimeter
	void clearUntilDelimeter(std::istream& is) {
		char c;
		bool delimeterFound = false;
		while (!delimeterFound && is.get(c)) {
			delimeterFound = true;
		}
	}
}