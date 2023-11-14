/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Nov 12, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

namespace sdds {
	struct Covid {
		std::string m_country{};
		std::string m_city{};
		std::string m_variant{};
		int m_year{};
		unsigned m_numOfCases{};
		unsigned m_numOfDeaths{};
		std::string m_status{"General"};
	};

	class CovidCollection {
		std::vector<Covid> m_covidCases{};
	public:
		CovidCollection(const std::string filename);
		
		//Implement the function to print only the information about the country specified in the second parameter. If the parameter has the value ALL, then print information for all countries.
		void display(std::ostream& out, const std::string& country = "ALL") const;

		//Sort the collection of Covid objects in ascending order based on the field received as parameter.
		//The parameter should have a default value of country.
		void sort(const std::string& field = "DEFAULT");

		//Search in the collection for a city in the specified country where the variant from the first parameter has caused more deaths than the last parameter. Return true if such an object exists, false otherwise.
		bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
		
		//Create and return a collection of Covid objects from the current instance where the number of deaths is at least as the value specified as parameter.
		std::list<Covid> getListForDeaths(unsigned int deaths);
		
		//updates the status of each city. If the number of deaths is greater than 300, the status should be EPIDEMIC, if it is less than 50, it should be EARLY; for anything else, the status should be MILD.
		void updateStatus();
	};
	//inserts one Covid object into the first parameter, using the following format(the width of each field is specified in brackets) :
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}



#endif //SDDS_COVIDCOLLECTION_H