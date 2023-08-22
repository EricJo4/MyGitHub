/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
Full Name  : Eric Jo
Student ID#: 137057188
Email      : hjo9@myseneca.ca
Section    : NII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/




// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"




	// 1. Get user input of int type and validate for a positive non-zero number
	//    (return the number while also assigning it to the pointer argument)


int getIntPositive(int* testNumber)
{
	int number = 0;
	do
	{
		scanf_s("%d", &number);
		if (number <= 0)
			printf("ERROR: Enter a positive value: ");

	} while (number <= 0);
	if (testNumber != NULL)
		*testNumber = number;
	return number;
}







// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* testNumber)
{
	double number = 0;
	do
	{
		scanf_s("%lf", &number);
		if (number <= 0.0)
			printf("ERROR: Enter a positive value: ");

	} while (number <= 0.0);

	if (testNumber != NULL)
		*testNumber = number;
	return number;
}
// 3. Opening Message (include the number of products that need entering)


void openingMessage(void)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_NUM_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n", NUM_OF_GRAMS);

}

//4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence)
{
	struct CatFoodInfo st;
	int testInt = 0;
	double testDouble = 0;
	int i = sequence;

	for (i; i < MAX_NUM_PRODUCTS; i++)
	{
		printf("\nCat Food Product #%d\n", i + 1);
		printf("---------------------\n");
		printf("SKU           : ");
		do
		{

			if (getIntPositive(&testInt) <= 0)
				printf("ERROR: Enter a positive value: ");

		} while (testInt <= 0);
		st.sku[i] = testInt;

		printf("PRICE         : $");
		do
		{

			if (getDoublePositive(&testDouble) <= 0)
				printf("ERROR: Enter a positive value: ");

		} while (testDouble <= 0);
		st.productPrice[i] = testDouble;

		printf("WEIGHT (LBS)  : ");
		do
		{
			getDoublePositive(&testDouble);

			if (testDouble <= 0)
				printf("ERROR: Enter a positive value: ");

		} while (testDouble <= 0);
		st.productWeight[i] = testDouble;

		printf("CALORIES/SERV.: ");

		do
		{

			if (getIntPositive(&testInt) <= 0)
				printf("ERROR: Enter a positive value: ");

		} while (testInt <= 0);
		st.caloriesPerServing[i] = testInt;
	}
	return st;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int* sku, const double* productPrice, const double* productWeight, const int* caloriesPerServing)
{

	printf("%07d %10.2lf %10.1lf %8d\n", *sku, *productPrice, *productWeight, *caloriesPerServing);
}


// 7. Logic entry point

void start(void)
{
	struct CatFoodInfo product = { {0} };
	int i = 0;
	openingMessage();

	
	product = getCatFoodInfo(NULL);

	displayCatFoodHeader();

	for (i = 0; i < MAX_NUM_PRODUCTS; i++)
	{
		displayCatFoodData(&product.sku[i], &product.productPrice[i], &product.productWeight[i], &product.caloriesPerServing[i]);
	}
	
	
}
