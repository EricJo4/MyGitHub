/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 1 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H

#include "Collection.h"
namespace sdds {
	template <typename T>
	class OrderedCollection : public Collection<T, 72> {
	public:
		//Add a new element and sort the elements of the collection in ascending order 
		bool operator+=(const T& item) {
			if (this->size() < this->capacity()) {
				unsigned index = this->size();
				while (index > 0 && item < this->operator[](index - 1)) {
					this->operator[](index) = this->operator[](index - 1);
					index--;
				}
				this->setSmallestItem(item);
				this->setLargestItem(item);
				this->operator[](index) = item;
				this->incrSize();

				return true;
			}
			return false;
		}
	};
}
#endif //SDDS_ORDEREDCOLLECTION_H
