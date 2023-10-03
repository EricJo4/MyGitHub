#ifndef BOX_H
#define BOX_H
#include "mapping.h"

// valid box sizes for a package, anything else is invalid
extern const double boxSizes[3];

struct Box
{
	int weight;
	double size;
	struct Point destination;
};

/*
 * Validate the size entered by the client
 *
 * @param size - the size of package entered by the client
 *
 * @return - 0 if the size is valid, otherwise -1
 */
int IsValidSize(double size);

/*
 * Validate the weight entered by the client
 *
 * @param weight - the weight of package entered by the client
 *
 * @return 0 if the weight is valid, otherwise -1
 */
int IsValidWeight(unsigned int weight);

/*
 * Validate the destination entered by the client
 *
 * @param destination - the destination of package entered by the client
 *
 * @return 0 if the destination is valid, otherwise -1
 */
int IsValidDestination(const struct Point *destination);

#endif
