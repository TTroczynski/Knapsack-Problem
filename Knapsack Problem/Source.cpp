#include "SimulatedAnnealing.h"
#include "Solution.h"
#include <iostream>



int main(void) {

	double kInitialTemperature = 100;
	unsigned kTimesToDecreaseTemp = 100;
	unsigned kNeighbours = 4;
	double kDecreaseAmount = 1;
	double kProbabilityTemp = 0.7;
	unsigned maxWeight = 100;

	srand(time(NULL));

	SimulatedAnnealing sa(kInitialTemperature, kTimesToDecreaseTemp, kNeighbours, kDecreaseAmount, kProbabilityTemp);

	Solution bestSolution = sa.run(maxWeight);

	std::cout << "Best Solution: " << bestSolution.toString();

	return 0;
}