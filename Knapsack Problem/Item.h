#pragma once
#include <string>

class Item
{
private:
	double mValue;
	double mWeight;
	bool mIsPresent;

public:
	Item(double value, double weight, bool isPresent);
	double getValue() const;
	double getWeight() const;
	bool isPresent() const;
	void setPresent(bool newValue);
	std::string toString() const;

};

