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
