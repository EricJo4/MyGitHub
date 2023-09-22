/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 3 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {
	int CalorieList::totalCal()const {
		int total = 0;
		for (int i = 0; i < foodAdded; i++) {
			total += m_food[i].calorie();
		}
		return total;
	}

	bool CalorieList::isValid()const {
		if (m_food == nullptr) {
			return false;
		}
		for (int i = 0; i < noOfFood; i++) {
			if (!m_food[i].Food::isValid())
				return false;
		}

		return true;
	}

	void CalorieList::setTitle()const {
		if (isValid()) {
			cout << "+----------------------------------------------------+" << endl;
			cout << "|  Daily Calorie Consumption                         |" << endl;
			cout << "+--------------------------------+------+------------+" << endl;
		}
		else {
			cout << "+----------------------------------------------------+" << endl;
			cout << "| Invalid Calorie Consumption list                   |" << endl;
			cout << "+--------------------------------+------+------------+" << endl;
		}
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}
	void CalorieList::footer()const {
		if (isValid()) {
			cout << "+--------------------------------+------+------------+" << endl;
			cout << "|    Total Calories for today:";
			cout.width(9);
			cout.setf(ios::right);
			cout << totalCal();
			cout << " |            |" << endl;
			cout << "+----------------------------------------------------+" << endl;
		}
		
		else {
			cout << "+--------------------------------+------+------------+" << endl;
			cout << "|    Invalid Calorie Consumption list                |" << endl;
			cout << "+----------------------------------------------------+" << endl;
		}
	}
	void CalorieList::setEmpty() {
		m_food = nullptr;
	}

	void CalorieList::init(int numberOfFood) {
		if (numberOfFood <= 0) {
			setEmpty();
		}
		noOfFood = numberOfFood;
		foodAdded = 0;
		m_food = new Food[noOfFood];
		for (int i = 0; i < noOfFood; i++) {
			m_food[i].Food::setEmpty();
		}
	}

	void CalorieList::display() {
		setTitle();
		for (int i = 0; i < noOfFood; i++) {
			m_food[i].Food::display();
		}
		footer();
	}

	bool CalorieList::add(const char* name, int number, int time) {
		if (foodAdded < noOfFood) {
			m_food[foodAdded].Food::set(name, number, time);
			foodAdded++;
			return true;
		}
		return false;
	}

	void CalorieList::deallocate() {
		delete[] m_food;
		m_food = nullptr;
	}

}