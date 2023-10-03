#include <stdio.h>
#include <stdlib.h>
#include "Box.h"
#include "Truck.h"

const double boxSizes[3] = {0.25, 0.5, 1};

/*
 * Validate the size entered by the client
 *
 * @param size - the size of package entered by the client
 *
 * @return - 0 if the size is valid, otherwise -1
 */
int IsValidSize(double size)
{
    int valid = -1;

    for (int i = 0; i < 3; i++)
    {
        if (size == boxSizes[i])
        {
            valid = 0; // Valid size
        }
    }

    return valid; // Invalid size
}

/*
 * Validate the weight entered by the client
 *
 * @param weight - the weight of package entered by the client
 *
 * @return 0 if the weight is valid, otherwise -1
 */
int IsValidWeight(unsigned int weight)
{
    int valid = -1;

    if (weight > 0 && weight <= MAX_WEIGHT)
    {
        valid = 0; // Valid size
    }

    return valid;
}

/*
 * Validate the weight entered by the client. This will be called before 
 * creating a Box object to validate user input data.
 *
 * @param destination - holds a reference to the destination entered by the client.
 *
 * @return an integer type that represents successful validation. Check if 
 * the row and column entered by the client are valid. If the row is greater 
 * than 0 and less than or equal to 25 then the row is valid. It then checks if 
 * the column is greater than or equal to ‘A?and less than or equal to ‘Y? then 
 * it is a valid column. If both row and column are valid then return 0, otherwise -1.
 */
int IsValidDestination(const struct Point *destination)
{
    int valid = -1;

    if (destination->row >= 0 && destination->row <= 24) {
        if (destination->col >= ('A' - 'A') && destination->col <= ('Y' - 'A')) {
            valid = 0;
        }
    }

    return valid;
}