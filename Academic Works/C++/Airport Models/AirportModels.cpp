/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Sep 22 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <cstring>
#include <fstream>
#include "AirportModels.h"

namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Airport& airport) {
		if(airport.m_code.c_str()[0] == '\0') {
			os << "Empty Airport";
		}
		else {
			os.width(20);
			os.fill('.');
			os << std::right << "Airport Code" << " : ";
			os.width(30);

			os << std::left << airport.m_code << std::endl;
			os.width(20);

			os << std::right << "Airport Name" << " : ";
			os.width(30);

			os << std::left << airport.m_name << std::endl;
			os.width(20);

			os << std::right << "City" << " : ";
			os.width(30);

			os << std::left << airport.m_city << std::endl;
			os.width(20);

			os << std::right << "State" << " : ";
			os.width(30);

			os << std::left << airport.m_state << std::endl;
			os.width(20);

			os << std::right << "Country" << " : ";
			os.width(30);

			os << std::left << airport.m_country << std::endl;
			os.width(20);

			os << std::right << "Latitude" << " : ";
			os.width(30);

			os << std::left << airport.m_latitude << std::endl;
			os.width(20);

			os << std::right << "Longitude" << " : ";
			os.width(30);
			os << std::left << airport.m_longitude << std::endl;
			os.fill(' ');
		}
		return os;
	}


	AirportLog::AirportLog(const char* filename):m_airports(nullptr), m_numOfAirports(0) {
		std::ifstream fin(filename);
		std::string ignoreHeader;
		std::getline(fin, ignoreHeader); // skip the header of the file.
		std::string line;
		while(std::getline(fin, line)){ // count the number of lines in the file
			m_numOfAirports++;
		}
		fin.clear();
		fin.seekg(0, fin.beg); // return to beginning of the file

		m_airports = new Airport[m_numOfAirports];

		while (std::getline(fin, ignoreHeader)) { // skip the header of the file
			for (size_t i = 0; i < m_numOfAirports; i++) {
				//copy the input buffer to member variables
				getline(fin, line, ',');
				m_airports[i].m_code = line;

				getline(fin, line, ',');
				m_airports[i].m_name = line;

				getline(fin, line, ',');
				m_airports[i].m_city = line;


				getline(fin, line, ',');
				m_airports[i].m_state = line;

				getline(fin, line, ',');
				m_airports[i].m_country = line;

				fin >> m_airports[i].m_latitude;
				fin.ignore();
				fin >> m_airports[i].m_longitude;
				fin.ignore(); //ignore '\n' in the end
			}
		}
		fin.close();
	}

	AirportLog::AirportLog(const AirportLog& other) {
		m_airports = nullptr;
		*this = other;
	}

	AirportLog& AirportLog::operator=(const AirportLog& other) {
		if (this != &other) {
			delete[]m_airports;
			if (other) {
				m_airports = new Airport[other.m_numOfAirports];
				for (size_t i = 0; i < other.m_numOfAirports; i++) {
					m_airports[i].m_code = other.m_airports[i].m_code;
					m_airports[i].m_name = other.m_airports[i].m_name;
					m_airports[i].m_city = other.m_airports[i].m_city;
					m_airports[i].m_state = other.m_airports[i].m_state;
					m_airports[i].m_country = other.m_airports[i].m_country;
					m_airports[i].m_latitude = other.m_airports[i].m_latitude;
					m_airports[i].m_longitude = other.m_airports[i].m_longitude;
				}
			}
			m_numOfAirports = other.m_numOfAirports;
		}
		return *this;
	}

	AirportLog::AirportLog(AirportLog&& other) {
		*this = std::move(other);
	}
	AirportLog& AirportLog::operator=(AirportLog&& other) {
		if (this != &other) {
			delete[] m_airports;
			if (other) {
				m_airports = other.m_airports;
				other.m_airports = nullptr;
			}
			m_numOfAirports = other.m_numOfAirports;
			other.m_numOfAirports = 0;
			}
		return *this;
	}

	AirportLog::~AirportLog() {

		delete[] m_airports;
		m_airports = nullptr;
	}

	void AirportLog::addAirport(const Airport& airport) {
		
		Airport* newAirports;
		newAirports = new Airport[m_numOfAirports + 1];
		for (size_t i = 0; i < m_numOfAirports; i++) {
			newAirports[i] = m_airports[i];
		}//copy current object to the newly created Airport object, newAirports

		delete[] m_airports;
		m_airports = newAirports; //copy newAirports to the current Airport object.
		m_airports[m_numOfAirports++] = airport; //Push the argument into the last index of the current Airport object.
	}

	AirportLog AirportLog::findAirport(const char* state, const char* country) const {
		AirportLog matchingAirportLog; //AirportLog data matching with the two parameters

		for (size_t i = 0; i < m_numOfAirports; i++) {
			if (strcmp(m_airports[i].m_state.c_str(), state) == 0 && strcmp(m_airports[i].m_country.c_str(), country) == 0) {
				matchingAirportLog.addAirport(m_airports[i]); //(optional)matchingAirportLog.m_numOfAirports++++;(Without using addAirports)
			}
		}

		/* (optional)Without using addAirports
		matchingAirportLog.m_airports = new Airport[matchingAirportLog.m_numOfAirports];
		for (size_t i = 0; i < matchingAirportLog.m_numOfAirports; i++) {
			for (size_t j = 0; j < m_numOfAirports; j++) {
				if (strcmp(m_airports[j].m_state.c_str(), state) == 0 && strcmp(m_airports[j].m_country.c_str(), country) == 0) {
					matchingAirportLog.m_airports[i] = m_airports[j];
				}
			}
		}
		*/
		return matchingAirportLog;
	}

	const Airport& AirportLog::operator[](size_t index) const {
		if (index < m_numOfAirports) {
			return m_airports[index];
		}
		else {
			// Return an empty Airport (assuming you have an empty constructor)
			static Airport emptyAirport; // Assuming an empty Airport can be constructed this way
			return emptyAirport;
		}
	}

	AirportLog::operator size_t() const {

		return m_numOfAirports;
	}
}