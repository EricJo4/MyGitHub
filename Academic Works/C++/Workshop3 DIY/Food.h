/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 3 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
	class Food {
		char foodName[31];
		int calorieNumber;
		int timeOfConsumption;
		void setName(const char* name);
	public:
		void setEmpty();
		void set(const char* name, int number, int time);
		void display();
		bool isValid();
		char* consumptionTime(int time);
		int calorie();
		
	};

}

#endif