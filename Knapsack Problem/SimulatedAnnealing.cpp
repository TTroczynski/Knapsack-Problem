#include "SimulatedAnnealing.h"
#include <fstream>
#include <sstream>
#include <iostream>

SimulatedAnnealing::SimulatedAnnealing(double initialTemperature, unsigned timesToDescreaseTemp, unsigned neighbours, double decreaseAmount, double probabilityTemp): 
	kInitialTemperature{initialTemperature}, 
	kTimesToDecreaseTemp{timesToDescreaseTemp},
	kNeighbours{neighbours},
	kDecreaseAmount{decreaseAmount},
	kProbabilityTemp{probabilityTemp}
{
	yes = 0;
	no = 0;

}

Solution SimulatedAnnealing::run(unsigned maxWeight)
{
	Solution currentSolution(maxWeight);

	std::ofstream csv("results.csv", std::ofstream::out);

	double currentTemperature = kInitialTemperature;

	for (unsigned i = 0; i < kTimesToDecreaseTemp; i++) {
		std::cout << "------------------Temperature = " << currentTemperature << std::endl;
		std::cout << "Solution = " << currentSolution.toString() << std::endl;

		for (unsigned j = 0; j < kNeighbours; j++) {

			Solution candidate = currentSolution.randomWalk();
			std::cout << "Candidate = " << candidate.toString() << std::endl;

			if (candidate.value() > currentSolution.value()) {
				std::cout << "Found a better solution" << std::endl;
				currentSolution = candidate;
			}
			else {
				double frac = (-1 * candidate.value()) + currentSolution.value();
				double probability = 1 / exp(frac / currentTemperature);

				std::cout << "New Candidate < current solution. Selection Probability = " << probability << std::endl;
				kProbabilityTemp = probability;

				double r = (double)(rand() % 1000) / 1000;

				if (r < probability) {
					std::cout << "Taking the worse solution" << std::endl;
					currentSolution = candidate;
					yes++;
				}
				else {
					std::cout << "Taking better solution" << std::endl;
					no++;
				}
			}
		}
		std::cout << " Worse solution? yes: " << yes << " no: " << no << std::endl;
		currentTemperature = currentTemperature * kDecreaseAmount;
		csv << currentSolution.value() << ", " << yes << ", " << no << ", " << kProbabilityTemp << '\n';
	}
	csv.close();
	return currentSolution;
}


