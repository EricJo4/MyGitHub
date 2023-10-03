#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "mapping.h"
#include "Truck.h"
#include "Box.h"

// Clear input buffer
void clear() {
	while (getchar() != '\n');
}

int main(void)
{
	// Display the route of blue, green, and yellow truck
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();
	struct Map baseMap = populateMap();
	struct Map routeMap = addRoute(&baseMap, &blueRoute);
	routeMap = addRoute(&routeMap, &greenRoute);
	routeMap = addRoute(&routeMap, &yellowRoute);
	printMap(&routeMap, 1, 1);

	printf("\n=================\nSeneca Deliveries\n=================\n\n");

	int done = -1;							// used for shutting off the program
	int valuesAssignedCount = 0;			// used for storing the values assigned in the scanf
	unsigned int weight = 0;				// used for storing the shipment weight
	double size = 0.0;						// used for storing the shipment size
	struct Point destination = { 0, 0 };	// used for storing the shipment destination

	// Creating blue, green, and yellow truck
	struct Truck blueTruck = { {0}, 0, 0, 0.0, blue, getBlueRoute() };
	struct Truck greenTruck = { {0}, 0, 0, 0.0, green, getGreenRoute() };
	struct Truck yellowTruck = { {0}, 0, 0, 0.0, yellow, getYellowRoute() };

	// Array of trucks
	struct Truck trucks[] = { blueTruck, greenTruck, yellowTruck };

	while (done != 0) {
		int row = 0;
		char des[3] = { 0 }, col = 0;
		const char* ptrDes = { 0 };

		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
		valuesAssignedCount = scanf("%d%lf%s", &weight, &size, &des);

		// Extract the integer numbers from the string
		// and store it in variable "row"
		row = atoi(&des);

		// Extract the character from the string
		// and store it in variable "col"
		ptrDes = &des;
		while (*ptrDes && col == 0) {
			if ((*ptrDes >= 'A' && *ptrDes <= 'Y') || (*ptrDes >= 'a' && *ptrDes <= 'y'))
				col = *ptrDes;
			else
				ptrDes++;
		}

		// This will identify the best truck for shipment. Once the best truck has been identified, 
		// it will then ship the package.
		if (weight != 0 && size != 0 && col != 'x') {
			destination.row = row - 1;
			destination.col = col - 'A';

			if (IsValidWeight(weight) == -1) {
				printf("Invalid weight (must be 1-1000 Kg.)\n");
			}
			else if (IsValidSize(size) == -1) {
				printf("Invalid size\n");
			}
			else if (IsValidDestination(&destination) == -1) {
				printf("Invalid destination\n");
			}
			else {
				struct Box package = { weight, size, destination };
				int bestTruck = FindTruckForShipment(&trucks, 3, &destination, &package);

				if (bestTruck == 0)
					printf("Ship on BLUE LINE\n");
				else if (bestTruck == 1)
					printf("Ship on GREEN LINE\n");
				else if (bestTruck == 2)
					printf("Ship on YELLOW LINE\n");
				else
					printf("Ships tomorrow\n");
			}
		}
		else if (col == 'x') {
			done = 0;
			printf("Thanks for shipping with Seneca!\n");
		}
		else {
			printf("Invalid destination\n");
		}
		
		clear();
	}

	return 0;
}