/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 15, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

namespace sdds {
	class SpellChecker {
		char* m_badWords[6];
		char* m_goodWords[6];
		size_t m_statistics[6] = { 0 };
		size_t m_cnt = 0;
	public:
		//receives the address of a C-style null-terminated string that holds the name of the file that contains the misspelled words
		SpellChecker(const char* filename);

		//Find badwords and fix them to good words
		void operator()(std::string& text);

		//Show how many each bad word was fixed
		void showStatistics(std::ostream& out) const;

		~SpellChecker() {
			for (size_t i = 0; i < m_cnt; i++) {
				delete[] m_badWords[i];
				delete[] m_goodWords[i];
			}
		}
	};
}
#endif //SDDS_SPELLCHECKER_H