/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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
    char loopType;
    int number;
    int i = 1;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    printf("\n");
    
    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &number);

        if (loopType == 'D')
        {
            if (number >= 3 && number <= 20)
            {
                printf("DO-WHILE: ");
                while (i != number)
                {
                    printf("D");
                    i += 1;
                }
                printf("D\n");
                i = 1;
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }
        else if (loopType == 'W')
        {
            if (number >= 3 && number <= 20)
            {
                printf("WHILE   : ");
                while (i != number)
                {
                    printf("W");
                    i += 1;
                }
                printf("W\n");
                i = 1;
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }
        else if (loopType == 'F')
        {
            if (number >= 3 && number <= 20)
            {
                printf("FOR     : ");
                while (i != number)
                {
                    printf("F");
                    i += 1;
                }
                printf("F\n");
                i = 1;
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }
        else if (loopType == 'Q')
        {
            if (number == 0)
            {
                printf("\n");
                printf("+--------------------+\n");
                printf("Loop application ENDED\n");
                printf("+--------------------+\n");
            }
            else
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            }
        }
        else
        {
            printf("ERROR: Invalid entered value(s)!\n");
        }
        printf("\n");
    }
    while (!(loopType == 'Q' && number == 0));
    

    
    return 0;
}