/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: May 25 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& employees) {
       bool ok = false;
       char name[128];
       int number;
       double salary;

       if (read(number) && read(salary) && read(name)) {
           
           employees.m_name = new char[strLen(name) + 1];
           employees.m_empNo = number;
           employees.m_salary = salary;
           strCpy(employees.m_name, name);
           
           ok = true;
       }

       return ok;
   }
             
      
      /* if reading of employee number, salay and name are successful
              allocate memory to the size of the name + 1
              and keep its address in the name of the Employee Reference

              copy the name into the newly allocated memroy

              make sure the "ok" flag is set to true
         end if
      */
    
      
    
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
       bool ok = false;
       int i = 0;
       if (openFile(DATAFILE)) {
           noOfEmployees = noOfRecords();
           employees = new Employee [noOfEmployees];

           for (; i < noOfEmployees; i++) {
               load(employees[i]);
           }
           ok = true;
       }
       else {
         cout << "Could not open data file: " << DATAFILE<< endl;
       }
       closeFile();
      return ok;

      /*
        Set the noOfEmployees to the number of recoreds in the file.
        dyanamically allocated an array of employees into the global
        Employee pointer; "employees" to the size of the noOfEmployees.

        In a loop load the employee records from the file into
        the dynamic array.

        If the number of the records does not match the number of reads
           print the message
          "Error: incorrect number of records read; the data is possibly corrupted"
        Otherwise
           set the ok flag to true
        End if

        close the file
        */
   }

   // TODO: Implementation for the display functions go here
   void display(Employee& employees) {
      
       cout << employees.m_empNo << ": " << employees.m_name << ", " << employees.m_salary << endl;
       
   }

   void display() {
       int i;
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;

       sort();
       for (i = 0; i < noOfEmployees; i++) {
           cout << i+1 << "- ";
           display(employees[i]);
       }
     
   }
   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       if (employees != nullptr) {
           for (int i = 0; i < noOfEmployees; i++) {
               delete[] employees[i].m_name;
           }
           delete[] employees;
           employees = nullptr;
       }
   }

}