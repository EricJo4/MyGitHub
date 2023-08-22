/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: May 25 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(char employee[]);
   bool read(int &employeeNumber);
   bool read(double &employeeSalary);

}
#endif // !SDDS_FILE_H_
