#ifndef TRUCK_H
#define TRUCK_H

#include "mapping.h"
#include "Box.h"

extern const unsigned int MAX_WEIGHT;	// maximum weight of cargo that a truck can hold
extern const double MAX_VOLUME;			// maximum size in cubic meters that a truck can hold
enum Color {blue, yellow, green};		// type of a truck

struct Truck {
	struct Box packages[1000];	// holds an array of boxes
	unsigned int numOfPackages; // holds the number of packages currently stored
	unsigned int weight;		// holds the current weight 
	double volume;				// holds the current size
	enum Color colorOfTruck;	// holds the color of the truck
	struct Route route;			// holds the route of the truck
};

/**
* Finds the closest truck to the destination of the package.
* 
* @param truck - an array of trucks which holds the blue, yellow, and green truck.
* @param numOfTrucks - holds the number of trucks currently stored in the trucks array.
* @param destination - holds the destination of the package.
* 
* @returns - an integer type that represents the index of the closest truck. 
* If the destination supplied in the argument is invalid, then it returns -1.
*/
int FindClosestTruck(struct Truck trucks[], const unsigned int numOfTrucks, const struct Point* destination);

/**
* Find the best truck for shipping the package. It considers looking for the closest 
* truck to the destination and the truck that has the most space which can fit the package.
* 
* @param trucks - an array of trucks.
* @param numOfTrucks - the number of trucks in the array.
* @param destination - the destination of the package.
* @param package - a data structure containing the weight and size of the package.
* 
* @returns - an integer type that represents the index of the truck that will 
* be used for shipping the package. If the truck cannot ship the package because 
* of an invalid destination or the package is too big for the truck then return -1.
*/
int FindTruckForShipment(struct Truck* trucks, const unsigned int numOfTrucks,  const struct Point* destination, const struct Box* package);

/*
* Checks if the package can fit into the truck. If the package can fit into the truck
* then add the package to the truck
* 
* @param truck - holds a reference to the truck that will ship the package.
* @param package - holds the package that will be shipped.
* 
* @returns - an integer type that represents the successful loading of the package. 
* If the package has been successfully loaded onto the truck, then return 0, otherwise 
* return -1.
*/
int addPackageToTruck(struct Truck* truck, const struct Box* package);

#endif