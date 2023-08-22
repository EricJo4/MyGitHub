// Copy the below commented "header" section to all your source code files!

/*/////////////////////////////////////////////////////////////////////////
						Assignment 1 - Milestone 1
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

char inputCharOption(const char charOptions[])
{
	char value;
	int i = 0;
	int characterFound = 0;

	while (characterFound == 0)
	{
		scanf(" %c", &value);

for (i = 0; charOptions[i] != '\0'; i++)
		{
			if (value == charOptions[i])
			{
				characterFound = 1;
			}

		}
		if (characterFound == 0)
			printf("ERROR: Character must be one of [%s]: ", charOptions);

	}
	return value;
}






void inputCString(char string[], int min, int max)
{

	int i;
	int len=0;
	
	do
	{
		clearInputBuffer();
		scanf("%[^\n]", string);
		for (i = 0; string[i] != '\0'; i++)
		{
			len = i+1;

		}

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
		for (len = 0; phoneNumber[len] != '\0'; len++);

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
