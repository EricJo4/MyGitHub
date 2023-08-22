/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 30 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>

namespace sdds {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
      const char* getFileName() const;
   public:

      Text(const char* filename=nullptr);
      
      //Rull of Three
      Text(const Text& other);
      Text& operator=(const Text& other);
      virtual ~Text();

      void read();
      virtual void write(std::ostream& os)const;
   };
   std::ostream& operator <<(std::ostream& os, const Text& text);
}
#endif // !SDDS_PERSON_H__

