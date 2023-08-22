/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : Eric Jo
Student ID#: 137057188
Email      : hjo9@myseneca.ca
Section    : NII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char coffee1;
    char coffee2;
    char coffee3;
    int coffee1Weight;
    int coffee2Weight;
    int coffee3Weight;
    char coffee1Cream;
    char coffee2Cream;
    char coffee3Cream;
    char userCoffee;
    char userCream;
    int userServings;
    

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee1);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee1Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee1Cream);
    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee2);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee2Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee2Cream);
    printf("\n");


    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee3);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee3Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee3Cream);
    printf("\n");

    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        coffee1 == 'l' || coffee1 == 'L', coffee1 == 'm' || coffee1 == 'M',
        coffee1 == 'r' || coffee1 == 'R', coffee1Weight, coffee1Weight/GRAMS_IN_LBS,
        coffee1Cream == 'y' || coffee1Cream == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        coffee2 == 'l' || coffee2 == 'L', coffee2 == 'm' || coffee2 == 'M',
        coffee2 == 'r' || coffee2 == 'R', coffee2Weight, coffee2Weight / GRAMS_IN_LBS,
        coffee2Cream == 'y' || coffee2Cream == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        coffee3 == 'l' || coffee3 == 'L', coffee3 == 'm' || coffee3 == 'M',
        coffee3 == 'r' || coffee3 == 'R', coffee3Weight, coffee3Weight / GRAMS_IN_LBS,
        coffee3Cream == 'y' || coffee3Cream == 'Y');
    printf("\n");
    printf("Enter how you like your coffee...\n");
    printf("\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &userCoffee);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &userCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &userServings);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",
        (userCoffee == 'l' || userCoffee == 'L') && (coffee1 == 'l' || coffee1 == 'L'),
        userServings >= 1 && userServings <= 4, (userCream == 'y' || userCream == 'Y') && (coffee1Cream == 'y' || coffee1Cream == 'Y'));
    printf(" 2|       %d         |      %d      |   %d   |\n",
        (userCoffee == 'r' || userCoffee == 'R') && (coffee2 == 'r' || coffee2 == 'R'),
        userServings >= 5 && userServings <= 9, (userCream == 'y' || userCream == 'Y') && (coffee2Cream == 'y' || coffee2Cream == 'Y'));
    printf(" 3|       %d         |      %d      |   %d   |\n",
        (userCoffee == 'm' || userCoffee == 'M') && (coffee3 == 'm' || coffee3 == 'M'),
        userServings >= 10, (userCream == 'y' || userCream == 'Y') && (coffee3Cream == 'y' || coffee3Cream == 'Y'));
    printf("\n");

    printf("Enter how you like your coffee...\n");
    printf("\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &userCoffee);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &userCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &userServings);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",
        (userCoffee == 'l' || userCoffee == 'L') && (coffee1 == 'l' || coffee1 == 'L'),
        userServings >= 1 && userServings <= 4, (userCream == 'y' || userCream == 'Y') && (coffee1Cream == 'y' || coffee1Cream == 'Y'));
    printf(" 2|       %d         |      %d      |   %d   |\n",
        (userCoffee == 'r' || userCoffee == 'R') && (coffee2 == 'r' || coffee2 == 'R'),
        userServings >= 5 && userServings <= 9, (userCream != 'y' || userCream != 'Y') && (coffee2Cream != 'y' || coffee2Cream != 'Y'));
    printf(" 3|       %d         |      %d      |   %d   |\n",
        (userCoffee == 'm' || userCoffee == 'M') && (coffee3 == 'm' || coffee3 == 'M'),
        userServings >= 10, (userCream != 'y' || userCream != 'Y') && (coffee3Cream != 'y' || coffee3Cream != 'Y'));
    printf("\n");
    printf("Hope you found a product that suits your likes!\n");
    
    return 0;
}


/*
Provided formatting parts for printf statements:
As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",
*/