/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 15 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator~() const;
      Account& operator=(int number);
      Account& operator=(Account& account);
      Account& operator+=(double balance);
      Account& operator-=(double balance);
      Account& operator<<(Account& account);
      Account& operator>>(Account& account);
      
      
   };
   double operator+(const Account& left, const Account& right);
   double& operator+=(double& left, const Account& right);
   
}
#endif // SDDS_ACCOUNT_H_