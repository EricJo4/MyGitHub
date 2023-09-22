/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: May 30 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Item.h"
using namespace sdds;
int main() {
   Item A;
   A.setEmpty();
   A.display();
   A.set("Hot dog buns", 4.99, false);
   A.display();
   return 0;
}


/*
Output:
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| Hot dog buns........ |    4.99 | No  |

*/