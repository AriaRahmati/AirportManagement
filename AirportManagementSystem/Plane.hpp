#pragma once

#include "includes.hpp"

class Plane
{
public:
	Plane(const std::string& serialNumber, int seats) : serialNumber(serialNumber), seats(seats) { }

protected:
	std::string serialNumber;
	int seats;

	std::vector<class Flight*> flights;

public:
	std::string getSerialNumber() { return serialNumber; }
	int getSeats() { return seats; }
};

