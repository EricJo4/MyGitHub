/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: May 26 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_


namespace sdds {
	struct Population {
		char* postalCode;
		int population;
	};

	void sort();
	bool load(Population& pop);
	bool load(const char filename[]);
	
	void display(Population& pop);
	void display();
	void deallocateMemory();


}
#endif // SDDS_POPULATION_H_