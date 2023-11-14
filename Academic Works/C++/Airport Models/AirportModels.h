/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Sep 22 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H


#include<iostream>
#include <string>

namespace sdds {
	struct Airport {
		std::string m_code;
		std::string m_name;
		std::string m_city;
		std::string m_state;
		std::string m_country;
		double m_latitude;
		double m_longitude;

	};
	std::ostream& operator<<(std::ostream&, const Airport&);


	class AirportLog {
		struct Airport* m_airports;
		size_t m_numOfAirports;
	public:
		AirportLog() :m_airports(nullptr), m_numOfAirports(0) {}
		AirportLog(const char* filename);
		~AirportLog();

		AirportLog(const AirportLog&);
		AirportLog& operator=(const AirportLog&);

		AirportLog(AirportLog&&);
		AirportLog& operator =(AirportLog&&);

		/*addAirport(): A modifier that receives a constant reference to an Airport objectand returns nothing.
		addAirport will attempt to append the parameter to the dynamic array of airports held by the current object.
		Resize the array appropriately to accommodate the new objectand avoid memory leaks.*/
		void addAirport(const Airport&);

		/*findAirport(): a query that receives two C-style strings as paramenters representing the state name and the country name and returns an AirportLog object. 
		The returned object will contain all of the airports in that state and country.*/
		AirportLog findAirport(const char* state, const char* country) const;

		/*operator[](size_t): A query that will return the Airport in the dynamic array at the index provided.
		If the index is not valid, return an empty Airport instead.*/
		const Airport& operator[](size_t) const;

		/*operator size_t(): A casting operator that will convert the current object to a size_t value. 
		The returned value is the number of airports held by the current object.*/
		operator size_t() const;
	};
}
#endif //SDDS_AIRPORTMODELS_H
