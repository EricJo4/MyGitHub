#include <stdio.h>
#include "Truck.h"

const unsigned int MAX_WEIGHT = 1000;	// maximum weight of cargo that a truck can hold
const double MAX_VOLUME = 36;			// maximum size in cubic meters that a truck can hold

int FindClosestTruck(struct Truck trucks[], const unsigned int numOfTrucks, const struct Point *destination)
{
	int found = -1;
	double blueTruckDistance = 0;
	double yellowTruckDistance = 0;
	double greenTruckDistance = 0;

	if (IsValidDestination(destination) == 0 && numOfTrucks == 3)
	{
		for (int i = 0; i < 50 && found == -1; i++)
		{
			blueTruckDistance = distance(&trucks[0].route.points[i], destination);
			greenTruckDistance = distance(&trucks[1].route.points[i], destination);
			yellowTruckDistance = distance(&trucks[2].route.points[i], destination);

			if ((blueTruckDistance != greenTruckDistance) && (blueTruckDistance != yellowTruckDistance) && (greenTruckDistance != yellowTruckDistance))
			{
				if (blueTruckDistance < yellowTruckDistance)
				{
					if (blueTruckDistance != greenTruckDistance)
					{
						if (blueTruckDistance < greenTruckDistance)
						{
							found = 0;
						}
						else
						{
							found = 1;
						}
					}
				}
				else
				{
					if (yellowTruckDistance != greenTruckDistance)
					{
						if (yellowTruckDistance < greenTruckDistance)
						{
							found = 2;
						}
						else
						{
							found = 1;
						}
					}
				}
			}
			else
			{
				if ((trucks[0].route.points[i].row == destination->row) && (trucks[0].route.points[i].col == destination->col) &&
					(trucks[1].route.points[i].row == destination->row) && (trucks[1].route.points[i].col == destination->col) &&
					(trucks[2].route.points[i].row == destination->row) && (trucks[2].route.points[i].col == destination->col))
				{

					found = 0;
					if (trucks[1].weight < trucks[2].weight && trucks[1].weight < trucks[0].weight) {
						found = 1;
					}
					else if (trucks[2].weight < trucks[1].weight && trucks[2].weight < trucks[0].weight) {
						found = 2;
					}
				}
			}
		}
	}

	return found;
}

int FindTruckForShipment(struct Truck *trucks, const unsigned int numOfTrucks, const struct Point *destination, const struct Box *package)
{
	int bestTruck = -1, success = -1;

	if (IsValidDestination(destination) == 0 && IsValidWeight(package->weight) == 0 && IsValidSize(package->size) == 0)
	{
		bestTruck = FindClosestTruck(trucks, numOfTrucks, destination);

		if (bestTruck != -1) {
			success = addPackageToTruck(&trucks[bestTruck], package);
			if (success == -1)
			{
				for (int i = 0; i < numOfTrucks; i++)
				{
					if (i != bestTruck)
					{
						success = addPackageToTruck(&trucks[i], package);
						if (success == 0)
						{
							bestTruck = i;
							break;
						}
					}
				}
				if (success == -1)
				{
					bestTruck = success;
				}
			}
		}
	}
	return bestTruck;
}

int addPackageToTruck(struct Truck* truck, const struct Box* package) {
	int success = -1;

	if (IsValidWeight(package->weight) == 0 && IsValidSize(package->size) == 0) {
		if (truck->weight < MAX_WEIGHT && truck->volume < MAX_VOLUME) {
			unsigned int totalTruckWeight = truck->weight + package->weight;
			double totalTruckVolume = truck->volume + package->size;

			if (totalTruckWeight <= MAX_WEIGHT && totalTruckVolume <= MAX_VOLUME) {
				truck->packages[truck->numOfPackages] = *package;
				++truck->numOfPackages;
				truck->weight = totalTruckWeight;
				truck->volume = totalTruckVolume;
				success = 0;
			}
		}
	}

	return success;
}