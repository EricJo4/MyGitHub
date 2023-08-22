/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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
#define MAX_NUM 10


int main(void)
{
    const double MIN_INCOME = 500.00,
        MAX_INCOME = 400000.00,
        MIN_COST = 100.00;
    double netIncome = 0;
    int numOfItems =0;
    int itemNum[MAX_NUM];
    double itemCost[MAX_NUM];
    int i;
    int importance[MAX_NUM];
    char financing[MAX_NUM];
    double sumCost = 0;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");
    while (netIncome< MIN_INCOME || netIncome > MAX_INCOME)
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);
        if (netIncome < MIN_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
            printf("\n");
        }
        if (netIncome > MAX_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
            printf("\n");
        }

    }

    printf("\n");

    while (numOfItems < 1 || numOfItems > MAX_NUM)
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numOfItems);
        if (numOfItems < 1 || numOfItems > MAX_NUM)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
            printf("\n");
        }
    }
    printf("\n");

    for (i = 0; i < numOfItems; i++)
    {
        itemNum[i] = i + 1;
        printf("Item-%d Details:\n", i + 1);
        while (itemCost[i] < MIN_COST)
        {
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i]);
            if (itemCost[i] < MIN_COST)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        }
        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &importance[i]);
            if (importance[i] < 1 || importance[i] >3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        }while (importance[i] < 1 || importance[i] > 3);
        
        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financing[i]);
            if(financing[i] != 'y' && financing[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }

        }while (financing[i] != 'y' && financing[i] != 'n');
        printf("\n");
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < numOfItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", itemNum[i], importance[i], financing[i], itemCost[i]);
        sumCost += itemCost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", sumCost);
    printf("Best of luck in all your future endeavours!\n");

    return 0;

}
