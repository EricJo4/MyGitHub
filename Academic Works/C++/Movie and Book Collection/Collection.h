/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 15, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>
#include "Book.h"
#include "Movie.h"

namespace sdds {
	template <typename T>
	class Collection {
		std::string m_name;
		T* m_collection;
		size_t m_size;
		void (*m_observer)(const Collection<T>&, const T&) {};
	public:
		Collection(const std::string& name) : m_name(name), m_collection(nullptr), m_size(0), m_observer(nullptr) {}
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		Collection(Collection&&) = delete;
		Collection& operator=(Collection&&) = delete;
		~Collection() {
			delete[] m_collection;
		}

		size_t size() const {
			return m_size;
		}
		const std::string& name() const {
			return m_name;
		}

		//stores the address of the callback function(observer) into an attribute.
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}

		//adds a copy of item to the collection, only if the collection doesn't contain an item with the same title.
		Collection<T>& operator+=(const T& item) {
			bool found = false;

			for (size_t i = 0; i < m_size; i++) {
				if (m_collection[i].title() == item.title()) {
					found = true;
				}
			}
			if (!found) {
				T* tempCollection = new T[m_size + 1];
				for (size_t i = 0; i < m_size; i++) {
					tempCollection[i] = m_collection[i];
				}
				tempCollection[m_size] = item;
				delete[] m_collection;
				m_collection = tempCollection;
				++m_size;
				if (m_observer != nullptr) {
					m_observer(*this, item);
				}
			}

			

			return *this;
		}

		//returns the item at index idx.
		T& operator[](size_t idx) {
			if (idx >= m_size) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
			}
			return m_collection[idx];
		}

		//returns the address of the item with the title title
		T* operator[](const std::string& title) const {
			bool found = false;
			size_t foundIdx;
			for (size_t i = 0; i < m_size; i++) {
				if (m_collection[i].title() == title) {
					found = true;
					foundIdx = i;
				}
			}

			if (found) {
				return &m_collection[foundIdx];
			}

			return nullptr;
		}

		const T& getItem(size_t index) const {
			if (index < m_size) {
				return m_collection[index];
			}
			else {
				throw std::out_of_range("Index out of range.");
			}
		}
		
	};

	//Iterate over all elements in the collection and insert each one into the ostream object.
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
		for (size_t i = 0; i < collection.size(); i++) {
			os << collection.getItem(i) << std::endl;
		}
		return os;
	}
}



#endif //SDDS_COLLECTION_H
