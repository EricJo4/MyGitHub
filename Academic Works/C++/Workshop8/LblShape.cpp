/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 24 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "LblShape.h"


namespace sdds {
	//Return const char pointer of m_label
	const char* LblShape::label() const {
		return m_label;
	}
	
	LblShape::LblShape(const char* label) : m_label(nullptr) {
		if (label != nullptr) {
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}

	LblShape::~LblShape() {
		delete[] m_label;
	}

	//Read user input and assign it to m_label
	void LblShape::getSpecs(std::istream& in) {

		const int MAX_LABEL_SIZE = 100;
		char tempLabel[MAX_LABEL_SIZE];
		in.get(tempLabel, MAX_LABEL_SIZE, ',');
		in.ignore(); // Ignore the comma

		delete[] m_label;
		m_label = new char[strlen(tempLabel) + 1];
		strcpy(m_label, tempLabel);
	}

}