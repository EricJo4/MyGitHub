/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Nov 5, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "File.h"

namespace sdds {
	//sets the parent path to the parameter.
	void File::update_parent_path(const std::string& path) {
		m_parent_path = path;
	}

	//a query that returns Flags::FILE.
	NodeType File::type() const {
		return NodeType::FILE;
	}

	//a query that returns the full absolute path of the file(concatenates the absolute path locationand the file name).
	std::string File::path() const {
		std::string absolutePath = m_parent_path + m_name;
		return absolutePath;
	}

	//a query that returns the name of the file.
	std::string File::name() const {
		return m_name;
	}

	//a query that returns - 1.
	int File::count() const {
		return -1;
	}

	//a query that returns the size of the file in bytes. For simplicity, this is the number of characters in m_contents attribute.
	size_t File::size() const {
		size_t bytes = m_contents.size();
		return bytes;
	}
}