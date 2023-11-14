/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: Oct 1 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
// Collection.h
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include "Book.h"

namespace sdds {
    template <typename T, unsigned C>
    class Collection {
        T m_items[C]{};
        unsigned m_size{};
        unsigned m_capacity{ C };

        static T m_smallestItem;
        static T m_largestItem;
    protected:
        void setSmallestItem(const T& item) {
            if (item < m_smallestItem) {
                m_smallestItem = item;
            }
        }
        void setLargestItem(const T& item) {
            if (item > m_largestItem) {
                m_largestItem = item;
            }
        }

        //return the element of the collection matching with the index argument
        T& operator[](const unsigned index) {
            return m_items[index];
        }

        //increase the size when new elements are added
        void incrSize() {
            m_size++;
        }

    public:
        unsigned size() const {
            return m_size;
        }
        unsigned capacity() const {
            return m_capacity;
        }
        bool operator+=(const T& item) {
            if (m_size >= m_capacity) {

                return false;
            }
            setSmallestItem(item);
            setLargestItem(item);
            m_items[m_size++] = item;
            return true;
        }

        //print elements of the collection
        void print(std::ostream& os) const {
            os << "[";
            for (unsigned i = 0; i < m_size; ++i) {
                os << m_items[i];
                if (i != m_size - 1) {
                    os << ",";
                }
            }
            os << "]" << std::endl;
        }

        static T getSmallestItem() {
            return m_smallestItem;
        }
        static T getLargestItem() {
            return m_largestItem;
        }
    };
    //Initialization of m_smallestItem and m_largestItem
    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem = 9999;

    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem = -9999;

    // Specialization for T = Book and C = 10
    template <>
    Book Collection<Book, 10u>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 10u>::m_largestItem = Book("", 10000, 1);

    // Specialization for T = Book and C = 72
    template <>
    Book Collection<Book, 72u>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 72u>::m_largestItem = Book("", 10000, 1);

    // Specialization to print the multiple rows of the collection of books.
    template<>
    void Collection<Book, 10u>::print(std::ostream& os) const {
        os.width(77);
        os.fill('-');
        os << "| ";
        os << "|" << std::endl;
        os.fill(' ');
        for (unsigned i = 0; i < m_size; i++) {
            os << "| ";
            m_items[i].print(os);
            os << " |" << std::endl;
        }
        os.width(77);
        os.fill('-');
        os << "| ";
        os << "|" << std::endl;
        os.fill(' ');
    }

    template<>
    void Collection<Book, 72u>::print(std::ostream& os) const {
        os.width(77);
        os.fill('-');
        os << "| ";
        os << "|" << std::endl;
        os.fill(' ');
        for (unsigned i = 0; i < m_size; i++) {
            os << "| ";
            m_items[i].print(os);
            os << " |" << std::endl;
        }
        os.width(77);
        os.fill('-');
        os << "| ";
        os << "|" << std::endl;
        os.fill(' ');
    }
    
} // namespace sdds

#endif // SDDS_COLLECTION_H