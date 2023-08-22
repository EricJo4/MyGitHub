/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    float small; float medium; float large;
    int patNumber, salNumber, tomNumber;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &small);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &medium);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &large);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("%-7s: $", "SMALL");
    printf("%.2f\n", small);
    printf("%-7s: $", "MEDIUM");
    printf("%.2f\n", medium);
    printf("%-7s: $", "LARGE");
    printf("%.2f\n", large);
    printf("\n");

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &patNumber);
    printf("\n");
    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tomNumber);
    printf("\n");
    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &salNumber);
    printf("\n");

    float patSubTotal = small * patNumber, patTaxes = patSubTotal * TAX,
        patTotal = patSubTotal + patTaxes,
        salSubTotal = medium * salNumber, salTaxes = salSubTotal * TAX,
        salTotal = salSubTotal + salTaxes,
        tomSubTotal = large * tomNumber, tomTaxes = tomSubTotal * TAX,
        tomTotal = tomSubTotal + tomTaxes;

    int patRoundedSubTotal = (int)(patSubTotal * 100 + 0.5),
        patRoundedTaxes = (int)(patTaxes * 100 + 0.5),
        patRoundedTotal = (int)(patTotal * 100 + 0.5),
        salRoundedSubTotal = (int)(salSubTotal * 100 + 0.5),
        salRoundedTaxes = (int)(salTaxes * 100 + 0.5),
        salRoundedTotal = (int)(salTotal * 100 + 0.5),
        tomRoundedSubTotal = (int)(tomSubTotal * 100 + 0.5),
        tomRoundedTaxes = (int)(tomTaxes * 100 + 0.5),
        tomRoundedTotal = (int)(tomTotal * 100 + 0.5),
        subTotal = patRoundedSubTotal + salRoundedSubTotal + tomRoundedSubTotal,
        taxes = patRoundedTaxes + salRoundedTaxes + tomRoundedTaxes,
        total = patRoundedTotal + salRoundedTotal + tomRoundedTotal;

    
    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, small, patNumber,
        (float)patRoundedSubTotal/100, (float)patRoundedTaxes/100, (float)patRoundedTotal/100);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, medium, salNumber,
        (float)salRoundedSubTotal / 100, (float)salRoundedTaxes / 100, (float)salRoundedTotal / 100);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, large, tomNumber,
        (float)tomRoundedSubTotal / 100, (float)tomRoundedTaxes / 100, (float)tomRoundedTotal / 100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n", (float)subTotal/100, (float)taxes/100, (float)total/100);
    printf("\n");
    
    
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n");
    printf("\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (float)subTotal / 100);
    printf("Toonies  %3d %9.4lf\n", (subTotal/100)/2, (float)(subTotal%200)/100);
    printf("Loonies  %3d %9.4lf\n", (subTotal % 200)/100, (float)((subTotal % 200)%100)/100);
    printf("Quarters %3d %9.4lf\n", ((subTotal % 200) % 100) / 25, (float)(((subTotal % 200)%100)%25)/100);
    printf("Dimes    %3d %9.4lf\n", (((subTotal % 200) % 100) % 25) / 10, (float)((((subTotal % 200) % 100) % 25) % 10) / 100);
    printf("Nickels  %3d %9.4lf\n", ((((subTotal % 200) % 100) % 25) % 10) / 5, (float)(((((subTotal % 200) % 100) % 25) % 10) % 5) / 100);
    printf("Pennies  %3d %9.4lf\n", (((((subTotal % 200) % 100) % 25) % 10) % 5) / 1, (float)((((((subTotal % 200) % 100) % 25) % 10) % 5) % 1) / 100);
    printf("\n");
    printf("Average cost/shirt: $%.4lf\n", (float)subTotal / (patNumber + salNumber + tomNumber) / 100);
    printf("\n");
    
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (float)total / 100);
    printf("Toonies  %3d %9.4lf\n", (total / 100) / 2, (float)(total % 200) / 100);
    printf("Loonies  %3d %9.4lf\n", (total % 200) / 100, (float)((total % 200) % 100) / 100);
    printf("Quarters %3d %9.4lf\n", ((total % 200) % 100) / 25, (float)(((total % 200) % 100) % 25) / 100);
    printf("Dimes    %3d %9.4lf\n", (((total % 200) % 100) % 25) / 10, (float)((((total % 200) % 100) % 25) % 10) / 100);
    printf("Nickels  %3d %9.4lf\n", ((((total % 200) % 100) % 25) % 10) / 5, (float)(((((total % 200) % 100) % 25) % 10) % 5) / 100);
    printf("Pennies  %3d %9.4lf\n", (((((total % 200) % 100) % 25) % 10) % 5) / 1, (float)((((((total % 200) % 100) % 25) % 10) % 5) % 1) / 100);
    printf("\n");
    printf("Average cost/shirt: $%.4lf\n", (float)total / (patNumber + salNumber + tomNumber) / 100);

    return 0;
}
    
    
