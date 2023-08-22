/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 16 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Mark.h"

namespace sdds {

	Mark::Mark() {
		m_mark = 0;
	}

	Mark::Mark(int number) {
		m_mark = number;
	}

	Mark::operator bool() const {
		if (m_mark >= 0 && m_mark <= 100) {
			return true;
		}
		return false;
	}

	Mark::operator int() const {
		if (*this) {
			return m_mark;
		}
		return 0;
	}

	Mark::operator double() const {
		double scale4Mark;
		/*  0 < = Mark < 50		0.0
			50 < = Mark < 60	1.0
			60 < = Mark < 70	2.0
			70 < = Mark < 80	3.0
			80 < = Mark < = 100	4.0 
			Out of range        0.0 */
		if (*this) {
			if (m_mark >= 0 && m_mark < 50) {
				scale4Mark = 0.0;
			}
			else if (m_mark >= 50 && m_mark < 60) {
				scale4Mark = 1.0;
			}
			else if (m_mark >= 60 && m_mark < 70) {
				scale4Mark = 2.0;
			}
			else if (m_mark >= 70 && m_mark < 80) {
				scale4Mark = 3.0;
			}
			else {
				scale4Mark = 4.0;
			}
		}
		else {
			scale4Mark = 0.0;
		}
		return scale4Mark;
	}

	Mark::operator char() const {
		char grade;
		/*  0 < = Mark < 50	    F	
			50 < = Mark < 60	D	
			60 < = Mark < 70	C	
			70 < = Mark < 80	B	
			80 < = Mark < = 100	A	
			Out of range        X */
		if (*this) {
			if (m_mark == 0) {
				grade = 'X';
			}
			else if (m_mark > 0 && m_mark < 50) {
				grade = 'F';
			}
			else if (m_mark >= 50 && m_mark < 60) {
				grade = 'D';
			}
			else if (m_mark >= 60 && m_mark < 70) {
				grade = 'C';
			}
			else if (m_mark >= 70 && m_mark < 80) {
				grade = 'B';
			}
			else {
				grade = 'A';
			}
		}
		else {
			grade = 'X';
		}
		return grade;
	}

	Mark& Mark::operator = (int number) {
		m_mark = number;
		return *this;
	}

	Mark& Mark::operator += (int number) {
		int sum = m_mark + number;
		if (sum >= 0 && sum <= 100) {
			m_mark = sum;
		}
		else {
			m_mark = 0;
		}
		return *this;
	}

	int operator+=(int& var, Mark& mark) {
		var += (int)mark;
		return var;
	}
}