/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 6, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <cstring>
#include <string>
#include <iomanip>
#include <regex>
#include "Cheese.h"


namespace sdds {
	//string format: Name, Weight, Price, Features
	Cheese::Cheese(const std::string& str) {
		//find comma positions before features
		size_t commaPos1 = str.find(",");
		size_t commaPos2 = str.find(",", commaPos1 + 1);
		size_t commaPos3 = str.find(",", commaPos2 + 1);

		//assign substrings until commaposition to each attributes
		m_name = str.substr(0, commaPos1);
		m_weight = std::stoul(str.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1));
		m_price = std::stod(str.substr(commaPos2 + 1, commaPos3 - commaPos1 - 1));
		std::string features = str.substr(commaPos3 + 1);// ex) Hard, Sharp, Smooth

		//replace commas to a single space
		std::replace(features.begin(), features.end(), ',', ' ');
		//find and erase commas in features string
		/*size_t fcommaPos1 = features.find(",");
		if (fcommaPos1 != std::string::npos) {
			size_t fcommaPos2 = features.find(",", fcommaPos1 + 1);
			if (fcommaPos2 != std::string::npos) {
				features.erase(fcommaPos2 - 1,1);
			}
		}
		*/

		//assign processed features to m_desc
		m_desc = features;

		//Remove all leading and trailing spaces from the beginning and end.
		size_t name_start = m_name.find_first_not_of(" \t");
		size_t name_end = m_name.find_last_not_of(" \t");
		if (name_start != std::string::npos && name_end != std::string::npos) {
			m_name = m_name.substr(name_start, name_end - name_start + 1);
		}

		size_t desc_start = m_desc.find_first_not_of(" \t");
		size_t desc_end = m_desc.find_last_not_of(" \t");
		if (desc_start != std::string::npos && desc_end != std::string::npos) {
			m_desc = m_desc.substr(desc_start, desc_end - desc_start + 1);
			m_desc = std::regex_replace(m_desc, std::regex("\\s+"), " "); // convert multiple spaces between features to a single space.
		}
	}

	Cheese Cheese::slice(size_t weight) {
		if (weight <= m_weight) {
			Cheese slicedCheese = *this;
			slicedCheese.m_weight = weight;
			m_weight -=weight;
			return slicedCheese;
		}
		else {
			return Cheese();
		}
	}

	std::ostream& operator <<(std::ostream& os, const Cheese& cheese ) {
		os << "|" << std::setw(21) << std::left << cheese.getName();
		os << "|" << std::setw(5) << cheese.getWeight();
		os << "|" << std::setw(5) << std::fixed << std::setprecision(2) << cheese.getPrice();
		os << "|" << std::setw(33) << std::right << cheese.getDesc() << " |" << std::endl;
		return os;
	}
}