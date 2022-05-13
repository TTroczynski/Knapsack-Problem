#pragma once
#include <vector>
#include "Item.h"
#include "Utils.h"
#include "Solution.h"

class SimulatedAnnealing
{

	double kInitialTemperature;
	unsigned kTimesToDecreaseTemp;
	unsigned kNeighbours;
	double kDecreaseAmount;
	unsigned yes;
	unsigned no;
	double kProbabilityTemp;

public:

	SimulatedAnnealing(double initialTemperature, unsigned timesToDecreaseTemp, unsigned neighbours, double decreaseAmount, double probabilityTemp);

	Solution run(unsigned maxWeight);
	
};

