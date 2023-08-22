/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: July 7 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }

   //Empty state
   void TextFile::setEmpty() {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
       m_noOfLines = 0;
   }
   
   //set a name of a file
   void TextFile::setFilename(const char* fname, bool isCopy) {
       int length = strLen(fname);
       int prefix = isCopy ? 2 : 0; //if isCopy is true, prefix length is 2
       m_filename = new char[length + prefix + 1];
       if (isCopy) {
           strCpy(m_filename, "C_");
           strCat(m_filename, fname);
       }
       else {
           strCpy(m_filename, fname);
       }
   }
   

   /*read the file, character by character, and accumulates the number of newlines
   in the m_noOfLines attribute.*/
   void TextFile::setNoOfLines() {
       std::ifstream fin(m_filename);
       m_noOfLines = 0;
       char c;
       if (fin.get(c)) {
           while (fin.get(c)) {
               if (c == '\n') {
                   m_noOfLines++;
               }
           }
           if (c != '\n') {
               m_noOfLines++;  // Increment line count for the last line
           }
       }
       fin.close();
       
       if (m_noOfLines == 0) {
           setEmpty();  // Set to a safe empty state if no lines found
       }
   }

   //load text from the file
   void TextFile::loadText() {
       delete[] m_textLines;
       if (m_filename != nullptr) {
           m_textLines = new Line[m_noOfLines];

           ifstream fin(m_filename);
           string str;
           for (unsigned i = 0; i < m_noOfLines; i++) {
               getline(fin, str);
               m_textLines[i] = str.c_str();
           }
           fin.close();
       }
   }

   //Save as other filename
   void TextFile::saveAs(const char* fileName)const {
       ofstream fout(fileName);
       for (unsigned i = 0; i < m_noOfLines; i++) {
           fout << m_textLines[i] << '\n';
       }
      
   }

   //constructors
   TextFile::TextFile(unsigned pageSize) {
       m_textLines = nullptr;
       m_filename = nullptr;
       m_noOfLines = 0;
       m_pageSize = pageSize;
   }

   TextFile::TextFile(const char* filename, unsigned pageSize) {
       m_textLines = nullptr;
       m_filename = nullptr;
       m_noOfLines = 0;
       m_pageSize = pageSize;
       if (filename != nullptr) {
           setFilename(filename);
           setNoOfLines();
           loadText();
       }
   }

   //copy constructor
   TextFile::TextFile(const TextFile& src) {
       m_pageSize = src.m_pageSize;
       m_textLines = nullptr;
       m_filename = nullptr;
       m_noOfLines = 0;
       if (src.m_textLines != nullptr && src.m_filename != nullptr && src.m_noOfLines != 0) {

           setFilename(src.m_filename, true);
           m_noOfLines = src.m_noOfLines;
           //load text from src(existing file)
           delete[] m_textLines;
           if (src.m_filename != nullptr) {
               m_textLines = new Line[m_noOfLines];

               ifstream fin(src.m_filename);
               string str;
               for (unsigned i = 0; i < m_noOfLines; i++) {
                   getline(fin, str);
                   m_textLines[i] = str.c_str();
               }
               fin.close();
           }
           saveAs(m_filename);
       }
   }

   //copy assignment operator
   TextFile& TextFile::operator=(const TextFile& src) {
       if (this != &src && m_filename != nullptr) {
           if (src.m_textLines != nullptr && src.m_filename != nullptr && src.m_noOfLines != 0) {
               delete[] m_textLines;
               m_textLines = nullptr;
               
               m_noOfLines = src.m_noOfLines;

               //load texts
               if (src.m_filename != nullptr) {
                   m_textLines = new Line[m_noOfLines];

                   ifstream fin(src.m_filename);
                   string str;
                   for (unsigned i = 0; i < m_noOfLines; i++) {
                       getline(fin, str);
                       m_textLines[i] = str.c_str();
                   }
                   fin.close();
               }
               //Save as m_filename
               ofstream fout(m_filename);
               for (unsigned i = 0; i < m_noOfLines; i++) {
                   fout << m_textLines[i] << '\n';
               }
           }
       }
       return *this;
   }

   //Text File Destructor
   TextFile::~TextFile() {
       setEmpty();
   }
   
   
   unsigned TextFile::lines()const {
       return m_noOfLines;
   }

   //Display text lines
   std::ostream& TextFile::view(std::ostream& ostr)const {
       if (m_textLines != nullptr && m_filename != nullptr && m_noOfLines != 0) {
           ostr << m_filename << endl;
           for (int i = 0; i < strLen(m_filename); i++) {
               ostr << "=";
           }
           ostr << endl;

           
           for (unsigned i = 0; i < m_noOfLines; i++) {
               ostr << m_textLines[i] << endl;
               if ((i + 1) % m_pageSize == 0 && i < m_noOfLines) {

                   ostr << "Hit ENTER to continue...";
                   cin.ignore();
                   if(cin.peek() == EOF){
                       cin.ignore();
                   }
               }
           }
           return ostr;
       }
       return ostr;
   }

   //
   std::istream& TextFile::getFile(std::istream& istr) {
       string filename;
       istr >> filename;
       setFilename(filename.c_str());
       setNoOfLines();
       loadText();
       return istr;
   }

   const char* TextFile::operator[](unsigned index)const {
       if (m_textLines == nullptr) {
           return nullptr;
       }

       if (index >= m_noOfLines) {
           index %= m_noOfLines;
       }
       return m_textLines[index];
   }

   TextFile::operator bool()const {
       if (m_filename == nullptr && m_noOfLines == 0) {
           return false;
       }
       return true;
   }

   const char* TextFile::name()const {
       return m_filename;
   }

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
       return text.view(ostr);
   }

   std::istream& operator>>(std::istream& istr, TextFile& text) {
       return text.getFile(istr);
   }

}
