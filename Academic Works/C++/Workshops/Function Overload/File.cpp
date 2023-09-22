/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: May 25 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   /* TODO: read functions go here    
   bool read(................) {
      return .....
   }
   bool read(................) {
      return .....
   }
   bool read(................) {
      return .....
   }
   */
   bool read(char employee[]) {
       bool result = fscanf(fptr, "%[^\n]\n", employee);

       return result;
   }
   bool read(int &employeeNumber) {
       bool result = fscanf(fptr, "%d,", &employeeNumber);

       return result;
   }
   bool read(double &employeeSalary) {
       bool result = fscanf(fptr, "%lf,", &employeeSalary);

       return result;
   }
}