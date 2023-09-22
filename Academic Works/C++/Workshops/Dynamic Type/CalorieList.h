/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 3 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds {
	class CalorieList {
		Food* m_food;
		int noOfFood;
		int foodAdded;
		int totalCal()const;
		void setTitle()const;
		void footer()const;
		void setEmpty();
		bool isValid()const;
	public:
		void init(int number);
		void display();
		bool add(const char* name, int number, int time );
		void deallocate();
	};

}
#endif 