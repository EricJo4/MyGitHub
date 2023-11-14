/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Nov 5, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iomanip>
#include "Directory.h"

namespace sdds {
	//sets the parent path to the parameter. 
    //For each resource that this directory holds, this member should also set their absolute path locations to the full absolute path of this directory.
	void Directory::update_parent_path(const std::string& path) {
		m_parent_path = m_parent_path + path;
		for (size_t i = 0; i < m_contents.size(); i++) {
			m_contents[i]->update_parent_path(path);
		}
	}

	//a query that returns Flags::DIR.
	NodeType Directory::type() const {
		return NodeType::DIR;
	}

	//a query that returns the full absolute path of the directory (a concatenation of the absolute path location and the directory name).
	std::string Directory::path() const {
		std::string absolutePath = m_parent_path + m_name;
		return absolutePath;
	}

	//a query that returns the name of the directory.
	std::string Directory::name() const {
		return m_name;
	}

	//a query that returns the number of resources that this directory holds.
	int Directory::count() const {
		int numOfResources = (int)m_contents.size();
		return numOfResources;
	}

	//a query that returns the size of the directory in bytes. The size of the directory is the sum of the individual sizes of each resource that this directory holds.
	//This member returns 0u if the directory is empty.
	size_t Directory::size() const {
		size_t bytes = 0u;
		if (!m_contents.empty()) {
			for (size_t i = 0; i < m_contents.size(); i++) {
				bytes += m_contents[i]->size();
			}
			return bytes;
		}
		return bytes;

	}

	//adds a resource to the directoryand returns a reference to the current directory.
	//This member should check for existing resources in the directory with the same name :
	//if a match is found, throw and exception and do nothing else;
	//if no match is found, add the resourceand update the absolute path location of the added resource with the directory's full absolute path.
	Directory& Directory::operator+=(Resource* src) {
		bool found = false;
		for (size_t i = 0; i < m_contents.size() && found != true; i++) {
			if (m_contents[i]->name() == src->name()) {
				found = true;
			}
		}
		if (found) {
			throw std::runtime_error("Resource already exists");
		}
		else {
			if (src->type() == NodeType::DIR) {
				src->update_parent_path(m_name);
				m_contents.push_back(src);
			}
			else {
				src->update_parent_path(m_parent_path + m_name);
				m_contents.push_back(src);
			}
		}
		return *this;
	}

	//finds and returns the address of a resource in the directory whose name matches the given string or nullptr if a match is not found.
	//This member also takes an optional vector of flags that determine how the find is performed (defaults to an empty collection).
	//if the RECURSIVE flag is in the second parameter, this member will also attempt to recursively find a match in each directory that is in the m_contents vector. 
	Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& opflags) {
		bool found = false;
		if (opflags.empty()) {
			for (size_t i = 0; i < m_contents.size(); i++) {
				if (m_contents[i]->name() == name) {
					return m_contents[i];
				}
			}
			return nullptr;
		}
		else {
			size_t index = 0;
			for (size_t i = 0; i < m_contents.size(); i++) {
				if (m_contents[i]->name() == name) {
					found = true;
					index = i;
					break;
				}
				if (m_contents[i]->type() == NodeType::DIR) {
					Resource* foundInSubDir = dynamic_cast<Directory*>(m_contents[i])->find(name, opflags);
					if (foundInSubDir) {
						return foundInSubDir;
					}
				}
			}
			if (!found) {
				return nullptr;
			}
			return m_contents[index];
		}
	}

	//deletes a resource from the directory whose name matches the first argument(removing it from its contents and deallocating memory for it).
	void Directory::remove(const std::string& name, const std::vector<OpFlags>& opflags) {
		if (!opflags.empty()) {
			Resource* foundResource = find(name, opflags);
			if (!foundResource) {
				throw std::string(name + " does not exist in " + this->name());
			}
			if (foundResource->type() == NodeType::FILE) {
				for (size_t i = 0; i < m_contents.size(); i++) {
					if (m_contents[i] == foundResource) {
						m_contents.erase(m_contents.begin() + i);
						delete foundResource;
						return;
					}
				}
			}
			
			else if(foundResource->type() == NodeType::DIR){

				Directory* dirResource = dynamic_cast<Directory*>(foundResource);
				for (size_t i = 0; i < dirResource->m_contents.size(); i++) {
					dirResource->remove(dirResource->m_contents[i]->name(), opflags);
				}
				for (size_t i = 0; i < m_contents.size(); i++) {
					if (m_contents[i] == dirResource) {
						m_contents.erase(m_contents.begin() + i);
						delete foundResource;
						return;
					}
				}
			}
		}
		else {
			throw std::invalid_argument(name + " is a directory. Pass the recursive flag to delete directories.");
		}
	}

	//If the LONG flag is in the second parameter, insert into the output stream additional information about the resource :
	//D | DIR_NAME | COUNT | XX bytes | OR
	//F | FILE_NAME |    | XX bytes |
	void Directory::display(std::ostream& os, const std::vector<FormatFlags>& flags) const {
		os << "Total size: " << this->size() << " bytes" << std::endl;
		if (flags.empty()) {
			for (size_t i = 0; i < m_contents.size(); i++) {
				if (m_contents[i]->type() == NodeType::DIR) {
					os << "D" << " | " << std::setw(15) << std::left << m_contents[i]->name() << " |" << std::endl;
				}
				else {
					os << "F" << " | " << std::setw(15) << std::left << m_contents[i]->name() << " |" << std::endl;
				}
			}
		}
		else {
			for (size_t i = 0; i < m_contents.size(); i++) {
				if (m_contents[i]->type() == NodeType::DIR) {
					os << "D" << " | " << std::setw(15) << std::left << m_contents[i]->name() << " | ";
					os << std::setw(2) << std::right << m_contents[i]->count() << " | ";
					os << std::setw(10) << std::right << std::to_string(m_contents[i]->size()) + " bytes" << " | " << std::endl;
				}
				else {
					os << "F" << " | " << std::setw(15) << std::left << m_contents[i]->name() << " | ";
					os << std::setw(2) << std::right;
					((m_contents[i]->count() == -1) ? os << "  " : os << m_contents[i]->count()) << " | ";
					os << std::setw(10) << std::right << std::to_string(m_contents[i]->size()) + " bytes" << " | " << std::endl;
				}
			}
		}
	}
}