/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Nov 5, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <fstream>
#include "Filesystem.h"

namespace sdds {
	//loads the content of the file: each line in the file represents a resource
	//formats:
	//FILE_PATH | FILE_CONTENTS
	//DIRECTORY_PATH
	Filesystem::Filesystem(const std::string filename, const std::string rootDir) {
		std::ifstream file(filename);
		if (file.is_open()) {
			m_root = new Directory(rootDir);//root directory
			m_current = m_root;//initailize current directory to root

			std::string line;
			while (std::getline(file, line)) {
				if (!line.empty()) {
					size_t delimiterPos = line.find("|");//"|" is included in the line if it indicates a file
					//If it's a file
					if (delimiterPos != std::string::npos) {
						std::string path = line.substr(0, delimiterPos);
						std::string content = line.substr(delimiterPos + 1);

						//remove leading and trailing space
						size_t pathStart = path.find_first_not_of(" \t");
						size_t pathEnd = path.find_last_not_of(" \t");
						if (pathStart != std::string::npos && pathEnd != std::string::npos) {
							path = path.substr(pathStart, pathEnd - pathStart + 1);
						}
						size_t contentStart = content.find_first_not_of(" \t");
						size_t contentEnd = content.find_last_not_of(" \t");
						if (contentStart != std::string::npos && contentEnd != std::string::npos) {
							content = content.substr(contentStart, contentEnd - contentStart + 1);
						}

						size_t newPos = 0;//beginning of the path string
						while (path.find("/", newPos) != std::string::npos) {
							size_t delimPos = path.find("/", newPos);
							std::string dirName = path.substr(newPos, delimPos - newPos + 1);
							Resource* found = m_current->find(dirName); //identify if the extracted name is already in the current directory
							if (found == nullptr) {
								Directory* newDir = new Directory(dirName); //create a new directory with extracted name.
								m_current->operator+=(newDir); //add to current directory
								m_current = std::move(newDir); //move the reference of the newly created directory to current one.
							}
							else {
								m_current = dynamic_cast<Directory*>(found); //change current directory to the found one.
							}
							newPos = delimPos + 1;//update the beginning of the string to the position right after "/"
						}
						size_t slashPos = path.find_last_of("/"); //beginning position of file string
						Resource* found = m_current->find(path.substr(slashPos + 1)); //identify if the filename is already in the current directory
						if (found == nullptr) {
							m_current->operator+=(new File(path.substr(slashPos + 1), content)); //add to current directory
							m_current = m_root; //Return to root
						}
						else {
							m_current = m_root; //Return to root
							throw std::runtime_error("The file already exists!");
						}
					}
					//Only directories
					else {
						std::string path = line;
						//remove leading and trailing space
						size_t pathStart = path.find_first_not_of(" \t");
						size_t pathEnd = path.find_last_not_of(" \t");
						if (pathStart != std::string::npos && pathEnd != std::string::npos) {
							path = path.substr(pathStart, pathEnd - pathStart + 1);
						}

						size_t newPos = 0; //beginning of the path string
						while (path.find("/", newPos) != std::string::npos) {
							size_t delimPos = path.find("/", newPos); 
							std::string dirName = path.substr(newPos, delimPos - newPos + 1);
							Resource* found = m_current->find(dirName); //identify if the extracted name is already in the current directory
							if (found == nullptr) {
								Directory* newDir = new Directory(dirName); //create a new directory with extracted name.
								m_current->operator+=(newDir); //add to current directory
								m_current = std::move(newDir); //move the reference of the newly created directory to current one.
							}
							else {
								m_current = dynamic_cast<Directory*>(found); //change current directory to the found one.
							}
							newPos = delimPos + 1; //update the beginning of the string to the position right after "/"
						}
						m_current = m_root; //Return to root
					}
				}
			}
		}
		else {
			throw std::runtime_error("No file");
		}
		file.close();
	}

	//move operations
	Filesystem::Filesystem(Filesystem && other) {
		*this = std::move(other);
	}
	Filesystem& Filesystem::operator=(Filesystem&& other) {
		if (this != &other){
			delete m_root;
			delete m_current;
			if (other.m_root != nullptr && other.m_current) {
				m_root = other.m_root;
				other.m_root = nullptr;
				m_current = other.m_current;
				other.m_current = nullptr;
			}
			else {
				m_root = nullptr;
				m_current = nullptr;
			}
		}
		return *this;
	}

	//adds a resource to the current directory.
	Filesystem& Filesystem::operator+=(Resource* src) {
		m_current->operator+=(src);
		return *this;
	}

	//changes the current directory to the directory(located in the current directory) whose name matches argument.
	Directory* Filesystem::change_directory(const std::string& str) {
		if (str.empty()) {
			m_current = m_root;
		}
		else if (m_root->find(str)){
			m_current = dynamic_cast<Directory*>(m_root->find(str));
		}
		else {
			throw std::invalid_argument("Cannot change directory! DIR_NAME not found!");
		}
		return m_current;
	}

	//a query that returns the current directory.
	Directory* Filesystem::get_current_directory() const {
		return m_current;
	}

}