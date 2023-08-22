/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Eric Jo
Student ID#: 137057188
Email      : hjo9@myseneca.ca
Section    : NII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int numOfApples, numOfOranges, numOfPears, numOfTomatoes, numOfCabbages;
    int pickedApples, pickedOranges, pickedPears, pickedTomatoes, pickedCabbages;
    int shoppingAgain;

        do
        {
            printf("Grocery Shopping\n");
            printf("================\n");

            printf("How many APPLES do you need? : ");
            scanf("%d", &numOfApples);
            while (numOfApples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
                printf("How many APPLES do you need? : ");
                scanf("%d", &numOfApples);
            }
            printf("\n");

            printf("How many ORANGES do you need? : ");
            scanf("%d", &numOfOranges);
            while (numOfOranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
                printf("How many ORANGES do you need? : ");
                scanf("%d", &numOfOranges);
            }
            printf("\n");

            printf("How many PEARS do you need? : ");
            scanf("%d", &numOfPears);
            while (numOfPears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
                printf("How many PEARS do you need? : ");
                scanf("%d", &numOfPears);
            }
            printf("\n");

            printf("How many TOMATOES do you need? : ");
            scanf("%d", &numOfTomatoes);
            while (numOfTomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
                printf("How many TOMATOES do you need? : ");
                scanf("%d", &numOfTomatoes);
            }
            printf("\n");

            printf("How many CABBAGES do you need? : ");
            scanf("%d", &numOfCabbages);
            while (numOfCabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
                printf("How many CABBAGES do you need? : ");
                scanf("%d", &numOfCabbages);
            }
            printf("\n");

            printf("--------------------------\n");
            printf("Time to pick the products!\n");
            printf("--------------------------\n");
            printf("\n");

            /* Apples */
            if (numOfApples > 0)
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickedApples);

                while (pickedApples != numOfApples)
                {
                    if (pickedApples <= 0)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                        printf("Pick some APPLES... how many did you pick? : ");
                        scanf("%d", &pickedApples);
                    }
                    else if (pickedApples > numOfApples)
                    {
                        printf("You picked too many... only %d more APPLE(S) are needed.\n", numOfApples);
                        printf("Pick some APPLES... how many did you pick? : ");
                        scanf("%d", &pickedApples);
                    }
                    else
                    {
                        numOfApples = numOfApples - pickedApples;
                        printf("Looks like we still need some APPLES...\n");
                        printf("Pick some APPLES... how many did you pick? : ");
                        scanf("%d", &pickedApples);

                    }
                }
                printf("Great, that's the apples done!\n");
                printf("\n");
            }

            /* Oranges */
            if (numOfOranges > 0)
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickedOranges);

                while (pickedOranges != numOfOranges)
                {
                    if (pickedOranges <= 0)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                        printf("Pick some ORANGES... how many did you pick? : ");
                        scanf("%d", &pickedOranges);
                    }
                    else if (pickedOranges > numOfOranges)
                    {
                        printf("You picked too many... only %d more ORANGE(S) are needed.\n", numOfOranges);
                        printf("Pick some ORANGES... how many did you pick? : ");
                        scanf("%d", &pickedOranges);
                    }
                    else
                    {
                        numOfOranges = numOfOranges - pickedOranges;
                        printf("Looks like we still need some ORANGES...\n");
                        printf("Pick some ORANGES... how many did you pick? : ");
                        scanf("%d", &pickedOranges);

                    }
                }
                printf("Great, that's the oranges done!\n");
                printf("\n");
            }

            /* Pears */
            if (numOfPears > 0)
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickedPears);

                while (pickedPears != numOfPears)
                {
                    if (pickedPears <= 0)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                        printf("Pick some PEARS... how many did you pick? : ");
                        scanf("%d", &pickedPears);
                    }
                    else if (pickedPears > numOfPears)
                    {
                        printf("You picked too many... only %d more PEAR(S) are needed.\n", numOfPears);
                        printf("Pick some PEARS... how many did you pick? : ");
                        scanf("%d", &pickedPears);
                    }
                    else
                    {
                        numOfPears = numOfPears - pickedPears;
                        printf("Looks like we still need some PEARS...\n");
                        printf("Pick some PEARS... how many did you pick? : ");
                        scanf("%d", &pickedPears);

                    }
                }
                printf("Great, that's the pears done!\n");
                printf("\n");
            }

            /* Tomatoes */
            if (numOfTomatoes > 0)
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickedTomatoes);

                while (pickedTomatoes != numOfTomatoes)
                {
                    if (pickedTomatoes <= 0)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                        printf("Pick some TOMATOES... how many did you pick? : ");
                        scanf("%d", &pickedTomatoes);
                    }
                    else if (pickedTomatoes > numOfTomatoes)
                    {
                        printf("You picked too many... only %d more TOMATO(ES) are needed.\n", numOfTomatoes);
                        printf("Pick some TOMATOES... how many did you pick? : ");
                        scanf("%d", &pickedTomatoes);
                    }
                    else
                    {
                        numOfTomatoes = numOfTomatoes - pickedTomatoes;
                        printf("Looks like we still need some TOMATOES...\n");
                        printf("Pick some TOMATOES... how many did you pick? : ");
                        scanf("%d", &pickedTomatoes);

                    }
                }
                printf("Great, that's the tomatoes done!\n");
                printf("\n");
            }

            /* Cabbages */
            if (numOfCabbages > 0)
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickedCabbages);

                while (pickedCabbages != numOfCabbages)
                {
                    if (pickedCabbages <= 0)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                        printf("Pick some CABBAGES... how many did you pick? : ");
                        scanf("%d", &pickedCabbages);
                    }
                    else if (pickedCabbages > numOfCabbages)
                    {
                        printf("You picked too many... only %d more CABBAGE(S) are needed.\n", numOfCabbages);
                        printf("Pick some CABBAGES... how many did you pick? : ");
                        scanf("%d", &pickedCabbages);
                    }
                    else
                    {
                        numOfCabbages = numOfCabbages - pickedCabbages;
                        printf("Looks like we still need some CABBAGES...\n");
                        printf("Pick some CABBAGES... how many did you pick? : ");
                        scanf("%d", &pickedCabbages);

                    }
                }
                printf("Great, that's the cabbages done!\n");
                printf("\n");
            }
            printf("All the items are picked!\n");
            printf("\n");
            printf("Do another shopping? (0=NO): ");
            scanf("%d", &shoppingAgain);
            printf("\n");
        } while (shoppingAgain != 0);
        printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}