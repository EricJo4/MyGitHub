/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Nov 5, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_DIRECTORY_H
#define SDDS_DIRECTORY_H

#include <vector>
#include "File.h"

namespace sdds {
	class Directory:public Resource{
		//an object of type std::vector that holds pointers to Resource objects. Each element of the vector can either be a Directory or a File.
		std::vector<Resource*> m_contents;
	public:
		//a custom constructor that receives the name of the directory as a string and uses it to initialize the Directory object.
		//Note : assume all directory names end with a / .
		Directory(const std::string dirname) {
			m_name = dirname;
		}

		//sets the parent path to the parameter. 
		//For each resource that this directory holds, this member should also set their absolute path locations to the full absolute path of this directory.
		void update_parent_path(const std::string&);

		//a query that returns Flags::DIR.
		NodeType type() const;

		//a query that returns the full absolute path of the directory (a concatenation of the absolute path location and the directory name).
		std::string path() const;

		//a query that returns the name of the directory.
		std::string name() const;

		//a query that returns the number of resources that this directory holds.
		int count() const;

		//a query that returns the size of the directory in bytes. The size of the directory is the sum of the individual sizes of each resource that this directory holds.
		//This member returns 0u if the directory is empty.
		size_t size() const;

		//adds a resource to the directoryand returns a reference to the current directory.
		//This member should check for existing resources in the directory with the same name :
		//if a match is found, throw and exception and do nothing else;
		//if no match is found, add the resourceand update the absolute path location of the added resource with the directory's full absolute path.
		Directory& operator+=(Resource*);

		//finds and returns the address of a resource in the directory whose name matches the given string or nullptr if a match is not found.
		//This member also takes an optional vector of flags that determine how the find is performed (defaults to an empty collection).
		//if the RECURSIVE flag is in the second parameter, this member will also attempt to recursively find a match in each directory that is in the m_contents vector. 
		Resource* find(const std::string&, const std::vector<OpFlags>& = std::vector<OpFlags>{});

		//deletes a resource from the directory whose name matches the first argument(removing it from its contents and deallocating memory for it).
		void remove(const std::string&, const std::vector<OpFlags>& = std::vector<OpFlags>{});

		//If the LONG flag is in the second parameter, insert into the output stream additional information about the resource :
		//D | DIR_NAME | COUNT | XX bytes | OR
		//F | FILE_NAME |    | XX bytes |
		void display(std::ostream&, const std::vector<FormatFlags>& = std::vector<FormatFlags>{}) const;

		//a destructor that deallocates memory for each resource that this directory holds.
		virtual ~Directory() {
			for (int i = 0; i < this->count(); i++) {
				delete m_contents[i];
				m_contents[i] = nullptr;
			}
		}
	};
}
#endif //SDDS_DIRECTORY_H