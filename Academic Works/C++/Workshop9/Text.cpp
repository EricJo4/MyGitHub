/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 30 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <fstream>
#include <stdexcept>
#include "Text.h"
#include "cstring.h"

using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char* Text::getFileName() const {
       return m_filename;
   }


   //Constructor has the parameter which has a default value, nullptr
   Text::Text(const char* filename): m_filename(nullptr), m_content(nullptr) {
       if (filename != nullptr)
       {
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
           read();
       }
   }

   //Rule of Three
   Text::Text(const Text& other): m_filename(nullptr), m_content(nullptr) {
       *this = other;
   }
   Text& Text::operator=(const Text& other) {
       if (this == &other) {
           return *this;
       }
       delete[] m_filename;

           if (other.m_filename != nullptr) {
               m_filename = new char[strLen(other.m_filename) + 1];
               strCpy(m_filename, other.m_filename);
               read();
           }
       return *this;
   }
   Text::~Text() {
       delete[] m_filename;
       delete[] m_content;
   }

   //This index operator provides read-only access to the content of the text for the derived classes of Text. The behaviour of the operator is not defined if the index goes out of bounds.
   const char& Text::operator[](int index)const {
       if (index < 0 && index >= getFileLength()) {
           throw std::out_of_range("Index out of bounds.");
       }
       return m_content[index];
   }


   //First, read will the current content of the file and then allocates memory to the size of the file on the disk + 1 (for the null byte).
   //Then it will read the contents of the file character by character into the newly allocated memoryand terminates it with a null byte at the end.
   void Text::read() {
       delete[] m_content;
       ifstream fin(m_filename);
       if(fin) {
           int length = getFileLength();
           m_content = new char[length + 1];
           fin.read(m_content, length);
           m_content[length] = '\0';   
       }
    }

   //This virtual function will insert the content of the Text class into the ostream if m_content is not null.
   void Text::write(ostream& os)const {
       if (m_content != nullptr) {
           os << m_content;
       }
   }

   //Overload the insertion operator for a Text object into ostream.
   std::ostream& operator <<(ostream& os, const Text& text) {
       text.write(os);
       return os;
   }
}