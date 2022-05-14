#include "SimulatedAnnealing.h"
#include "Solution.h"
#include <iostream>



int main(void) {

	double kInitialTemperature = 100;
	unsigned kTimesToDecreaseTemp = 100;
	unsigned kNeighbours = 10;
	double kDecreaseAmount = 0.85;
	double kProbabilityTemp = 0;
	unsigned maxWeight = 100;

	srand(time(NULL));

	SimulatedAnnealing sa(kInitialTemperature, kTimesToDecreaseTemp, kNeighbours, kDecreaseAmount, kProbabilityTemp);

	Solution bestSolution = sa.run(maxWeight);

	std::cout << "Best Solution: " << bestSolution.toString() << std::endl;
	std::cout << "With a Max Weight of: " << maxWeight;

	return 0;
}