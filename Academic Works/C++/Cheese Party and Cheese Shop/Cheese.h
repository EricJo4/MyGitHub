/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 6, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H

#include <iostream>
namespace sdds {
	class Cheese {
		std::string m_name;
		size_t m_weight;
		double m_price;
		std::string m_desc;

	public:
		//Constructors
		Cheese() :m_name("NaC"), m_weight(0), m_price(0.0), m_desc("") {}
		Cheese(std::string name, size_t weight, double price, std::string desc) {
			m_name = name;
			m_weight = weight;
			m_price = price;
			m_desc = desc;
		}
		Cheese(const std::string& str);

		
		//a modifier that receives as a parameter a weight/amount of cheese to slice from the current cheese object.
		Cheese slice(size_t weight);

		//A set of queries to retrieve the value of each attribute of the cheese.
		std::string getName() const {
			return m_name;
		}
		size_t getWeight() const {
			return m_weight;
		}
		double getPrice() const {
			return m_price;
		}
		std::string getDesc() const {
			return m_desc;
		}

	};
	//insertion operator to insert the contents of a Cheese object into an ostream object in the following format
	std::ostream& operator <<(std::ostream&, const Cheese&);
}

#endif //SDDS_CHEESE_H
