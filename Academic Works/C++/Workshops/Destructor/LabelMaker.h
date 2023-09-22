/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 10 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H

#include <iostream>
#include "Label.h"
namespace sdds {
	class LabelMaker {
		Label* m_label;
		int m_noOfLabels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}

#endif
