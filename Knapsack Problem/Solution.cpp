#include "Solution.h"
#include "Item.h"
#include <sstream>
#include <string>

unsigned Solution::kMaxWeight;

Solution::Solution(unsigned maxWeight) {

	std::vector<Item> temp{
{randomInt(), randomInt(), randomBool()},
{ randomInt(), randomInt(), randomBool() },
{ randomInt(), randomInt(), randomBool() },
{ randomInt(), randomInt(), randomBool() },
{ randomInt(), randomInt(), randomBool() },
{ randomInt(), randomInt(), randomBool() },
{ randomInt(), randomInt(), randomBool() },
	};

	mItems = temp;
	kMaxWeight = maxWeight;
}

Solution::Solution(std::vector<Item> items): mItems{items}
{
}

double Solution::getTotalWeight() const
{
	double weightSum = 0;
	for (Item const& i : mItems) {
		if (i.isPresent()) {
			weightSum += i.getWeight();
		}
	}
	return weightSum;
}

std::string Solution::toString() const
{
	std::ostringstream stream;
	stream << "Items: ";
	for (Item const& i : mItems) {
		stream << i.toString() << " ";
	}
	stream << std::endl << " Total weight & Value = " << getTotalWeight() << " & " << value() << std::endl;

	return stream.str();
}

double Solution::value() const
{
	double valueSum = 0;
	for (Item const& i : mItems) {
		if (i.isPresent()) {
			valueSum += i.getValue();
		}
	}

	//This is a constraint
	//1. Penalty method - if solution invalid, reduce the value
	//2. Discard method - discard invalid solutions
	//3. Repair method - perform a corrective action to make the solution valid

	//Penalty Method
	if (getTotalWeight() > kMaxWeight) {
		return -10; //return valueSum - 10 if you want to just penalize the current solution set, but this introduces the possibility of selecting an invalid solution as a valid one.
	}
	return valueSum;
}

//Randomly adds or removes an item to the knapsack
Solution Solution::randomWalk() const
{
	std::vector<Item> itemsCopy = this->mItems;
	unsigned index = rand() % itemsCopy.size();

	//flips the bool value. if 1 then 0, if 0 then 1
	itemsCopy[index].setPresent(!itemsCopy[index].isPresent());

	Solution newSolution(itemsCopy);

	//Repair invalid solution
	while (newSolution.value() < 0) {
		for (Item& i : itemsCopy) {
			if (i.isPresent()) {
				i.setPresent(false);	//scan through the items in the set and the first one found present, gets removed from the set. present = false.
				break;
			}
		}
		newSolution.mItems = itemsCopy;	//Needto update the solutions set so that the repaired set is taken as the solution.
	}
	
	return newSolution;

}
