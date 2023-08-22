
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    int JAN = 1, DEC = 12;
    int year, month, day;
    float morning, evening;
    float morningSum=0, eveningSum=0;


    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        switch (year < MIN_YEAR || year > MAX_YEAR)
        {
        case 1:
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            break;

        }

        switch (month < JAN || month > DEC)
        {
        case 1:
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
            break;

        }
    } while (year < MIN_YEAR || year > MAX_YEAR || month<JAN || month > DEC);

    printf("\n");
    printf("*** Log date set! ***\n");
    
    
    for (day = 1; day <= LOG_DAYS; day++)
    {
        printf("\n");
        switch (month)
        {
        case 1:
            printf("%d-JAN-%02d\n", year, day);
            break;
        case 2:
            printf("%d-FEB-%02d\n", year, day);
            break;
        case 3:

            printf("%d-MAR-%02d\n", year, day);
            break;
        case 4:
            printf("%d-APR-%02d\n", year, day);
            break;
        case 5:
            printf("%d-MAY-%02d\n", year, day);
            break;
        case 6:
            printf("%d-JUN-%02d\n", year, day);
            break;
        case 7:
            printf("%d-JUL-%02d\n", year, day);
            break;
        case 8:
            printf("%d-AUG-%02d\n", year, day);
            break;
        case 9:
            printf("%d-SEP-%02d\n", year, day);
            break;
        case 10:
            printf("%d-OCT-%02d\n", year, day);
            break;
        case 11:
            printf("%d-NOV-%02d\n", year, day);
            break;
        case 12:
            printf("%d-DEC-%02d\n", year, day);
        }
        printf("\n");

        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%f", &morning);
            if (morning < 0.0 || morning > 5.0)
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
        } while (morning < 0.0 || morning > 5.0);
        morningSum += morning;

        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%f", &evening);
            if (evening < 0.0 || evening > 5.0)
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
        } while (evening < 0.0 || evening > 5.0);
        eveningSum += evening;

    }

    printf("\n");
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %.3f\n", morningSum);
    printf("Evening total rating:  %.3f\n", eveningSum);
    printf("----------------------------\n");
    printf("Overall total rating: %.3f\n", morningSum + eveningSum);
    printf("\n");
    printf("Average morning rating:  %.1f\n", morningSum/LOG_DAYS);
    printf("Average evening rating:  %.1f\n", eveningSum/LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1f\n", ((morningSum/LOG_DAYS + eveningSum/LOG_DAYS))/2);
    

    return 0;
}