/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
//Validate integer value
int inputInt(void)
{
	char newLine = 'x';
	int value;

	while (newLine != '\n')
	{
		scanf("%d%c", &value, &newLine);
		if (newLine != '\n')
		{
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}
	}

	return value;
}

//Validate positive value
int inputIntPositive(void)
{
	int value;

	do
	{
		scanf("%d", &value);

		clearInputBuffer();
		if (value <= 0)
		{
			printf("ERROR! Value must be > 0: ");
		}


	} while (value <= 0);

	return value;
}

//Validate integer range
int inputIntRange(int min, int max)
{
	char newLine = 'x';
	int value;
	while (newLine != '\n')
	{
		scanf("%d%c", &value, &newLine);
		if (value < min || value > max)
		{
			clearInputBuffer();
			printf("Error! Input a whole number: ");
			while (value < min || value > max)
			{
				scanf("%d%c", &value, &newLine);

				if (value < min || value > max)
				{
					printf("ERROR! Value must be between -3 and 11 inclusive: ");
				}
			}
		}
	}

	return value;
}

//Validate if a character is included in a given string
char inputCharOption(const char charOptions[])
{
	char value[10];
	int i = 0;
	int characterFound = 0;

	while (characterFound == 0)
	{
		scanf("%s", value);

		if (value[1] == '\0')
		{
			for (i = 0; charOptions[i] != '\0'; i++)
			{
				if (value[0] == charOptions[i])
				{
					characterFound = 1;
				}

			}
			if (characterFound == 0)
				printf("ERROR: Character must be one of [%s]: ", charOptions);
		}
		else
		{
			printf("ERROR: Character must be one of [%s]: ", charOptions);
		}
	}
	
	return value[0];
}

//Validate if the length of a string is in a specific range
void inputCString(char* string, int min, int max)
{

	int len;

	do
	{

		scanf("%[^\n]", string);
		clearInputBuffer();
		len = strlen(string);

		if (len < min || len> max)
		{
			if (min == max)
			{
				printf("ERROR: String length must be exactly %d chars: ", min);
			}
			else if (len > max)
			{
				printf("ERROR: String length must be no more than %d chars: ", max);
			}
			else
			{
				printf("ERROR: String length must be between %d and %d chars: ", min, max);
			}
		}


	} while (len < min || len> max);
}

//Validate if the phone number is in valid format
void displayFormattedPhone(const char phoneNumber[])
{
	int i;
	int len;
	int validNumber = 0;

	if (phoneNumber == NULL)
	{
		printf("(___)___-____");
	}

	else
	{
		len = strlen(phoneNumber);

		for (i = 0; i < phoneNumber[i]; i++)
		{
			if (phoneNumber[i] >= '0' && phoneNumber[i] <= '9')
			{
				validNumber += 1;
			}
		}

		if (validNumber != 10 || len != 10)
		{
			printf("(___)___-____");

		}
		else
		{
			printf("(%c%c%c)%c%c%c-%c%c%c%c", phoneNumber[0], phoneNumber[1], phoneNumber[2],
				phoneNumber[3], phoneNumber[4], phoneNumber[5], phoneNumber[6], phoneNumber[7],
				phoneNumber[8], phoneNumber[9]);
		}
	}
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////
void inputMonth(int* year, int* month)
{
	if (*month < 1 || *month > 12)
	{
		while (*month < 1 || *month > 12)
		{
			printf("ERROR! Value must be between 1 and 12 inclusive: ");
			scanf("%d", month);
		}
	}
	else
	{
		if (*month == 2)
		{
			if (*year % 4 == 0)
			{
				printf("Day (1-29)  : ");
			}
			else
			{
				printf("Day (1-28)  : ");
			}
		}
		else if (*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8 || *month == 10 ||
			*month == 12)
		{
			printf("Day (1-31)  : ");
		}
		else
		{
			printf("Day (1-30)  : ");
		}
	}
}

void inputDay(int *year, int* month, int* day)
{
	if (*year % 4 == 0 && *month == 2)
	{
		while (*day < 1 || *day > 29)
		{
			printf("ERROR! Value must be between 1 and 29 inclusive: ");
			scanf("%d", day);
		}
	}
	else if (*year % 4 != 0 && *month == 2)
	{
		while (*day < 1 || *day > 28)
		{
			printf("ERROR! Value must be between 1 and 28 inclusive: ");
			scanf("%d", day);
		}
	}
	else if ((*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8 || *month == 10 ||
		*month == 12))
	{
		while (*day < 1 || *day > 31)
		{
			printf("ERROR! Value must be between 1 and 31 inclusive: ");
			scanf("%d", day);
		}
	}
	else
	{
		while (*day < 1 || *day > 30)
		{
			printf("ERROR! Value must be between 1 and 30 inclusive: ");
			scanf("%d", day);
		}
	}
}