/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 3 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;

namespace sdds {
	void Food::setName(const char* name) {
		strnCpy(foodName, name, 30);
		foodName[30] = '\0';
	}

	void Food::setEmpty() {
		foodName[0] = '\0';
		calorieNumber = 0;
		timeOfConsumption = 0;
	}

	void Food::set(const char* name, int number, int time) {
		if (name == nullptr || (number < 0 || number >3000) || (time < 1 || time > 4)) {
			setEmpty();
		}
		else {
			setName(name);
			calorieNumber = number;
			timeOfConsumption = time;
		}
	}

	void Food::display() {
		if (isValid()) {
			cout << "| ";
			cout.fill('.');
			cout.width(30);
			cout.setf(ios::left);
			cout << foodName;
			cout.unsetf(ios::left);
			cout << " | ";
			cout.fill(' ');
			cout.width(4);
			cout.setf(ios::right);
			cout << calorieNumber;
			cout.unsetf(ios::right);
			cout << " | ";
			cout.width(10);
			cout.setf(ios::left);
			cout << consumptionTime(timeOfConsumption);
			delete[] consumptionTime(timeOfConsumption);
			cout.unsetf(ios::left);
			cout << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

	bool Food::isValid() {
		return foodName[0] != '\0';
	}

	char* Food::consumptionTime(int time) {
		char* timeInString = new char[10];

		switch (time) {
			case 1:
				strnCpy(timeInString, "Breakfast", 9);
				break;
			case 2:
				strnCpy(timeInString, "Lunch", 9);
				break;
			case 3:
				strnCpy(timeInString, "Dinner", 9);
				break;
			case 4:
				strnCpy(timeInString, "Snack", 9);
		}
		timeInString[9] = '\0';
		
		return timeInString;
	}

	int Food::calorie() {
		return calorieNumber;
	}

	
}