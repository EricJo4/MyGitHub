/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 15 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }

   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }

   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   //valid or not
   Account::operator bool() const {
       if (m_number == -1 || m_number == 0 || m_balance < 0.0) {
           return false;
       }
       return true;
   }

   Account::operator int() const {
       return m_number;
   }

   Account::operator double() const {
       return m_balance;
   }

   //new or not
   bool Account::operator~() const {
       if (m_number == 0) {
           return true;
       }
       return false;
   }

   Account& Account::operator=(int number) {
       //if the current object is new
       if (~*this) {

           if (number >= 10000 && number <= 99999) {
               m_number = number;
           }
           else {
               setEmpty();
           }
       }
       return *this;
       
   }

   Account& Account::operator=(Account& account) {
       //if the current object is new and the argument is not the current object
       if (account && ~*this && this != &account) {
           m_balance = account.m_balance;
           m_number = account.m_number;
           account.m_balance = 0.0;
           account.m_number = 0;
       }
       return *this;
   }

   Account& Account::operator+=(double balance) {
       //if the current object is valid and balance is valid
       if (*this && balance >= 0) {
           m_balance += balance;
       }
       return *this;
   }

   Account& Account::operator-=(double balance) {
       /*if the current object is valid, balance is valid,
       and the balance of current object is more or equal to balance*/
       if (*this && balance >= 0 && m_balance >= balance) {
           m_balance -= balance;
       }
       return *this;
   }

   Account& Account::operator<<(Account& account) {
       //Test self-assignment, validity of the current object and account
       if (this != &account && *this && account) {
           m_balance += account.m_balance;
           account.m_balance = 0.0; 
       }
       return *this;
   }

   Account& Account::operator>>(Account& account) {
       //Test self-assignment, validity of the current object and account
       if (this != &account && *this && account) {
           account.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }

   double operator+(const Account& left, const Account& right) {
       //if the both reference are valid
       if (left.operator int() != -1 && right.operator int() != -1) {
           return left.operator double() + right.operator double();
       }
       return 0.0;
   }

   double& operator+=(double& left, const Account& right) {
       //if the reference on the right is valid
       if (right)
           left += right.operator double();
       return left;
   } 
}