/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Nov 5, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "Resource.h"

namespace sdds {
	class File:public Resource {
		//stores the contents of a file
		std::string m_contents{};
	public:

		//a custom constructor that receives two strings as parameters:
		//the name of the file
		//a text representation of the contents of a file(optional, with empty string as a default value).
		File(std::string filename, std::string contents = "") {
			m_name = filename;
			m_contents = contents;
		}

		//sets the parent path to the parameter.
		void update_parent_path(const std::string&);

		//a query that returns Flags::FILE.
		NodeType type() const;

		//a query that returns the full absolute path of the file(concatenates the absolute path locationand the file name).
		std::string path() const;

		//a query that returns the name of the file.
		std::string name() const;

		//a query that returns - 1.
		int count() const;

		//a query that returns the size of the file in bytes. For simplicity, this is the number of characters in m_contents attribute.
		size_t size() const;

		virtual ~File() = default;
	};
}
#endif //SDDS_FILE_H