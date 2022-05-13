#include "Utils.h"
#include <stdlib.h>

bool randomBool()
{
	if (rand() % 2)
	{
		return true;
	}
	return false;
}

double randomInt() {
	int randomValue = (int)rand() % 50;

	return randomValue;
}
