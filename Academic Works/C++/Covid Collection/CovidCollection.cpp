/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Nov 12, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iomanip>
#include <algorithm>
#include <functional>
#include <numeric>
#include "CovidCollection.h"


namespace sdds {
	CovidCollection::CovidCollection(const std::string filename) {
		std::ifstream file(filename);
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				Covid covidCase;//locally-defined instance to get extracted tokens from line.
				covidCase.m_country = line.substr(0, 25);
				covidCase.m_city = line.substr(25, 25);
				covidCase.m_variant = line.substr(50, 25);
				covidCase.m_year = std::stoul(line.substr(75, 5));
				covidCase.m_numOfCases = std::stoul(line.substr(80, 5));
				covidCase.m_numOfDeaths = std::stoul(line.substr(85, 5));

				//Remove leading and trailing spaces for each token.
				size_t country_start = covidCase.m_country.find_first_not_of(" \t");
				size_t country_end = covidCase.m_country.find_last_not_of(" \t");
				size_t city_start = covidCase.m_city.find_first_not_of(" \t");
				size_t city_end = covidCase.m_city.find_last_not_of(" \t");
				size_t variant_start = covidCase.m_variant.find_first_not_of(" \t");
				size_t variant_end = covidCase.m_variant.find_last_not_of(" \t");
				if (country_start != std::string::npos && country_end != std::string::npos) {
					covidCase.m_country = covidCase.m_country.substr(country_start, country_end - country_start + 1);
				}
				if (city_start != std::string::npos && city_end != std::string::npos) {
					covidCase.m_city = covidCase.m_city.substr(country_start, city_end - city_start + 1);
				}
				if (variant_start != std::string::npos && variant_end != std::string::npos) {
					covidCase.m_variant = covidCase.m_variant.substr(variant_start, variant_end - variant_start + 1);
				}
				m_covidCases.push_back(covidCase);//Add the instance to the member vector.
			}
			file.close();
		}
		else {
			throw std::runtime_error("No file");
		}
	}

	//inserts one Covid object into the first parameter, using the following format(the width of each field is specified in brackets) :
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		out << "| " << std::setw(21) << std::left << theCovid.m_country
			<< " | " << std::setw(15) << theCovid.m_city
			<< " | " << std::setw(20) << theCovid.m_variant
			<< " | " << std::setw(6) << std::right << (theCovid.m_year > 0 ? std::to_string(theCovid.m_year) : "")
			<< " | " << std::setw(4) << theCovid.m_numOfCases
			<< " | " << std::setw(3) << theCovid.m_numOfDeaths
			<< " | | " << std::setw(8) << theCovid.m_status << " |";
		return out;
	}
	
	//Implement the function to print only the information about the country specified in the second parameter. If the parameter has the value ALL, then print information for all countries.
	void CovidCollection::display(std::ostream& out, const std::string& country) const {
		unsigned totalCases = 0;
		unsigned totalDeaths = 0;
		unsigned countryCases = 0;
		unsigned countryDeaths = 0;

		std::for_each(m_covidCases.begin(), m_covidCases.end(), [&totalCases, &totalDeaths](const Covid& c) {
			totalCases += c.m_numOfCases;
			totalDeaths += c.m_numOfDeaths;
			});
		if (country == "ALL") {
			std::for_each(m_covidCases.begin(), m_covidCases.end(), [&out, country, &totalCases, &totalDeaths](const Covid& c) {

				out << "| " << std::setw(21) << std::left << c.m_country
					<< " | " << std::setw(15) << c.m_city
					<< " | " << std::setw(20) << c.m_variant
					<< " | " << std::setw(6) << std::right << (c.m_year > 0 ? std::to_string(c.m_year) : "")
					<< " | " << std::setw(4) << c.m_numOfCases
					<< " | " << std::setw(3) << c.m_numOfDeaths
					<< " | | " << std::setw(8) << c.m_status << " |" << std::endl;
			});
			out << "| " << std::setw(84) << std::right << "Total cases around the world: " + std::to_string(totalCases) << " |" << std::endl
				<< "| " << std::setw(84) << std::right << "Total deaths around the world: " + std::to_string(totalDeaths) << " |" << std::endl;
		}
		else {
			out << "Displaying information of country = " + country;
			std::for_each(m_covidCases.begin(), m_covidCases.end(), [&out, country, &countryCases, &countryDeaths](const Covid& c) {
				if (c.m_country == country) {
					out << std::endl << "| " << std::setw(21) << std::left << c.m_country
						<< " | " << std::setw(15) << c.m_city
						<< " | " << std::setw(20) << c.m_variant
						<< " | " << std::setw(6) << std::right << (c.m_year > 0 ? std::to_string(c.m_year) : "")
						<< " | " << std::setw(4) << c.m_numOfCases
						<< " | " << std::setw(3) << c.m_numOfDeaths
						<< " | | " << std::setw(8) << c.m_status << " |";
					
					countryCases += c.m_numOfCases;
					countryDeaths += c.m_numOfDeaths;
				}
				});
			double percentageCases = (totalCases > 0) ? ((double)countryCases / (double)totalCases) * 100 : 0.0;
			double percentageDeaths = (totalDeaths > 0) ? ((double)countryDeaths / (double)totalDeaths) * 100 : 0.0;

			out << std::endl << "----------------------------------------------------------------------------------------" << std::endl
				<< "| " << std::setw(84) << std::right << "Total cases in " + country + ": " + std::to_string(countryCases) << " |" << std::endl
				<< "| " << std::setw(84) << "Total deaths in " + country + ": " + std::to_string(countryDeaths) << " |" << std::endl
				<< "| " << std::setw(84) << country + " has " + std::to_string(percentageCases) + "% of global cases and "
				+ std::to_string(percentageDeaths) + "% of global deaths" << " |" << std::endl;
		}
	}

	//Sort the collection of Covid objects in ascending order based on the field received as parameter.
	//The parameter should have a default value of country.
	void CovidCollection::sort(const std::string& field) {
		std::sort(m_covidCases.begin(), m_covidCases.end(), [field](const Covid& c1, const Covid& c2) {
			if (field == "country"|| field == "DEFAULT") {
				if (c1.m_country == c2.m_country) { //If two Covid objects have the same value for the specified field, then the object with lower deaths is considered smaller.
					return c1.m_numOfDeaths < c2.m_numOfDeaths;
				}
				return c1.m_country < c2.m_country;
			}
			else if (field == "city") {
				if (c1.m_city == c2.m_city) {
					return c1.m_numOfDeaths < c2.m_numOfDeaths;
				}
				return c1.m_city < c2.m_city;
			}
			else if (field == "variant") {
				if (c1.m_variant == c2.m_variant) {
					return c1.m_numOfDeaths < c2.m_numOfDeaths;
				}
				return c1.m_variant < c2.m_variant;
			}
			else if (field == "year") {
				if (c1.m_year == c2.m_year) {
					return c1.m_numOfDeaths < c2.m_numOfDeaths;
				}
				return c1.m_year < c2.m_year;
			}
			else if (field == "numOfCases") {
				if (c1.m_numOfCases == c2.m_numOfCases) {
					return c1.m_numOfDeaths < c2.m_numOfDeaths;
				}
				return c1.m_numOfCases < c2.m_numOfCases;
			}
			else if (field == "numOfDeaths") {
				return c1.m_numOfDeaths < c2.m_numOfDeaths;
			}
			return false;
			});

	}

	//Search in the collection for a city in the specified country where the variant from the first parameter has caused more deaths than the last parameter. Return true if such an object exists, false otherwise.
	bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const {
		return std::any_of(m_covidCases.begin(), m_covidCases.end(), [variant, country, deaths](const Covid& c) {
			return c.m_variant == variant && c.m_country == country && c.m_numOfDeaths > deaths;
			});
	}

	//Create and return a collection of Covid objects from the current instance where the number of deaths is at least as the value specified as parameter.
	std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) {
		std::list<Covid> extractedList{};
		std::copy_if(m_covidCases.begin(), m_covidCases.end(), std::back_inserter(extractedList), [deaths](const Covid& c) {
			return c.m_numOfDeaths >= deaths;
			});
		return extractedList;
	}

	//updates the status of each city. If the number of deaths is greater than 300, the status should be EPIDEMIC, if it is less than 50, it should be EARLY; for anything else, the status should be MILD.
	void CovidCollection::updateStatus() {
		std::for_each(m_covidCases.begin(), m_covidCases.end(), [](Covid& c) {
			if (c.m_numOfDeaths > 300) {
				c.m_status = "EPIDEMIC";
			}
			else if (c.m_numOfDeaths < 50) {
				c.m_status = "EARLY";
			}
			else {
				c.m_status = "MILD";
			}
		});
	}


}

