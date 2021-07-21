#pragma once

#include "Person.hpp"

class Passenger : public Person
{
public:
	Passenger(const basicInformation& basicInfo) : Person(basicInfo) { }
};
