#include "Flight.hpp"

#include "Plane.hpp"

std::string Flight::getPlaneSerialNumber()
{
	return plane->getSerialNumber();
}

int Flight::getPlaneSeats()
{
	return plane->getSeats();
}
