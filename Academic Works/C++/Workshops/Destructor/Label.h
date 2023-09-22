/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 10 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>

namespace sdds {
	class Label {
		char* m_frameArg;
		char* m_content;
		void setFrame(const char* Cstr);
		void setContent(const char* Cstr);
		void setToDefault();
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel()const;

	};
}

#endif

