#pragma once

class Passenger;
class Flight;

class Ticket
{
public:
	Ticket(Passenger* passenger, Flight* flight) : passenger(passenger), flight(flight) { }

protected:
	Passenger* passenger;
	Flight* flight;
};
