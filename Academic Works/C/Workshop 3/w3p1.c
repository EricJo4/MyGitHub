/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Eric Jo
Student ID#: 137057188
Email      : hjo9@myseneca.ca
Section    : NII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const int idProduct1 = 111, idProduct2 = 222, idProduct3 = 111;
    const double priceProduct1 = 111.49, priceProduct2 = 222.99, priceProduct3 = 334.49;
    const char taxProduct1 = 'Y', taxProduct2 = 'N', taxProduct3 = 'N';
    const double averagePrice = (priceProduct1 + priceProduct2 + priceProduct3) / 3;
    
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", idProduct1);
    printf("  Taxed: %c\n", taxProduct1);
    printf("  Price: $%.4lf\n", priceProduct1);
    printf("\n");

    printf("Product-2 (ID:%d)\n", idProduct2);
    printf("  Taxed: %c\n", taxProduct2);
    printf("  Price: $%.4lf\n", priceProduct2);
    printf("\n");

    printf("Product-3 (ID:%d)\n", idProduct3);
    printf("  Taxed: %c\n", taxProduct3);
    printf("  Price: $%.4lf\n", priceProduct3);
    printf("\n");

    printf("The average of all prices is: $%.4lf\n", averagePrice);
    printf("\n");

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n", taxProduct1 == 'Y');
    printf("\n");
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", taxProduct2 == 'N' && taxProduct3 == 'N');
    printf("\n");
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n", testValue, priceProduct3 < testValue);
    printf("\n");
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n",
        priceProduct3 > priceProduct1 + priceProduct2);
    printf("\n");
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n",
        priceProduct1 >= priceProduct3 - priceProduct2, priceProduct3-priceProduct2);
    printf("\n");
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n", priceProduct2 >= averagePrice);
    printf("\n");
    printf("7. Based on product ID, product 1 is unique -> %d\n", idProduct1 != idProduct2 && idProduct1 != idProduct3);
    printf("\n");
    printf("8. Based on product ID, product 2 is unique -> %d\n", idProduct2 != idProduct1 && idProduct2 != idProduct3);
    printf("\n");
    printf("9. Based on product ID, product 3 is unique -> %d\n", idProduct3 != idProduct1 && idProduct3 != idProduct2);

    return 0;
}