/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 15, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <cstring>
#include <iomanip>
#include "SpellChecker.h"

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (file) {
			std::string wordline;
			do {
				std::getline(file, wordline);
				if (wordline.size() > 0) {
					if (m_cnt < 6) {
						//Convert multiple spaces between a bad word and a good word to a single space
						std::string trimmedWordline = std::regex_replace(wordline, std::regex("\\s+"), " ");
						size_t spacePos = trimmedWordline.find(" ");

						//deep copying to each element of each array attribute.
						m_badWords[m_cnt] = new char[std::strlen(trimmedWordline.substr(0, spacePos).c_str()) + 1];
						strcpy(m_badWords[m_cnt], trimmedWordline.substr(0, spacePos).c_str());
						m_goodWords[m_cnt] = new char[std::strlen(trimmedWordline.substr(spacePos + 1).c_str()) + 1];
						strcpy(m_goodWords[m_cnt], trimmedWordline.substr(spacePos + 1).c_str());

						++m_cnt;
					}
					else {
						std::cerr << "WARNING: Too many words in the input file. Some words were not loaded.\n";
						break;
					}
				}
			} while (file);
		}
		else {
			throw "Bad file name!";
		}

	}

	void SpellChecker::operator()(std::string& text) {
		for (size_t i = 0; i < m_cnt; ++i) {
			size_t pos = 0;
			while ((pos = text.find(m_badWords[i])) != std::string::npos) {
				text.replace(pos, strlen(m_badWords[i]), m_goodWords[i]);
				m_statistics[i]++;
				pos += strlen(m_goodWords[i]);
			}
		}
	}
	
	void SpellChecker::showStatistics(std::ostream& out) const {
		for (size_t i = 0; i < m_cnt; i++) {
			out << std::setw(15) << std::right << m_badWords[i] << ": " << m_statistics[i] << " " << "replacements" << std::endl;
		}
	}
}