/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Nov 5, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H

#include "Directory.h"

namespace sdds {
	class Filesystem {
		Directory* m_root{};
		Directory* m_current{};
	public:
		//loads the content of the file: each line in the file represents a resource
		//formats:
		//FILE_PATH | FILE_CONTENTS
		//DIRECTORY_PATH
		Filesystem(const std::string filename, const std::string rootDir = "");

		//move operations
		Filesystem(Filesystem&& other);
		Filesystem& operator=(Filesystem&& other);

		//adds a resource to the current directory.
		Filesystem& operator+=(Resource* src);

		//changes the current directory to the directory (located in the current directory) whose name matches argument.
		Directory* change_directory(const std::string& str = "");

		//a query that returns the current directory.
		Directory* get_current_directory() const;

		//a destructor that deallocates memory for the root directory.
		virtual ~Filesystem() {
			delete m_root;
		}
	};
}
#endif //SDDS_FILESYSTEM_H
