#pragma once
#include <vector>
#include <string>
#include "Item.h"
#include "Utils.h"

class Solution
{
private:
	std::vector<Item> mItems;
	static unsigned kMaxWeight;

private:
	double getTotalWeight() const;

public:
	Solution(unsigned maxWeight);
	Solution(std::vector<Item> items);
	std::string toString() const;
	double value() const;
	Solution randomWalk() const;
};

