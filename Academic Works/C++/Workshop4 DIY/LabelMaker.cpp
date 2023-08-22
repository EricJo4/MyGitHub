/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 10 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "LabelMaker.h"
#include "cstring.h"
using namespace std;

namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		m_label = new Label[noOfLabels];
		m_noOfLabels = noOfLabels;
	}

	void LabelMaker::readLabels() {
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		for(int i = 0; i < m_noOfLabels; i++){
			cout << "Enter label number " << i + 1 << endl;
			m_label[i].readLabel();
		}
	}

	void LabelMaker::printLabels() {
		for (int i = 0; i < m_noOfLabels; i++) {
			m_label[i].printLabel() << endl;
		}
	}

	LabelMaker::~LabelMaker() {
		delete[] m_label;
	}
}