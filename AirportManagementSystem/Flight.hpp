#pragma once

#include "includes.hpp"

class Plane;
class Pilot;
class FlightAttendant;
class Passenger;

class Flight
{
public:
	Flight(
		Plane* plane,
		Pilot* pilot,
		std::vector<FlightAttendant*> flightAttendants,
		std::vector<Passenger*> passengers,
		const std::string& serialNumber = "",
		const std::string& origin = "",
		const std::string& dest = "",
		const std::string& date = "",
		const std::string& time = "")
		: plane(plane), pilot(pilot), flightAttendants(flightAttendants), passengers(passengers),
		serialNumber(serialNumber), origin(origin), dest(dest), date(date), time(time) { }

protected:
	std::string serialNumber;

	std::string origin;
	std::string dest;
	std::string date;
	std::string time;

	Plane* plane;
	Pilot* pilot;
	std::vector<FlightAttendant*> flightAttendants;
	std::vector<Passenger*> passengers;

public:
	std::string getSerialNumber() { return serialNumber; }

	std::string getOrigin() { return origin; }
	std::string getDestination() { return dest; }
	std::string getDate() { return date; }
	std::string getTime() { return time; }

	std::string getPlaneSerialNumber();
	int getPlaneSeats();
};

