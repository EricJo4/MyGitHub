/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 30 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
      char* m_title;
      int getFileLength()const;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);

      //Rule of three
      HtmlText(const HtmlText& other);
      HtmlText& operator=(const HtmlText& other);
      virtual ~HtmlText();

      virtual void write(std::ostream& os)const;
   };
}
#endif // !SDDS_HTMLTEXT_H__
