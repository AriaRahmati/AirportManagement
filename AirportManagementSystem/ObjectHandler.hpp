#pragma once

#include "includes.hpp"

class Person;
class Employee;
class Pilot;
class Ticket;
class FlightAttendant;
class Plane;
class Passenger;
class Flight;
struct basicInformation;
struct basicEmployeeInformation;

class ObjectHandler
{
public:
	ObjectHandler();

public:
	Pilot* createPilot(const basicEmployeeInformation& pilotInfo, int grade, std::string& error);
	FlightAttendant* createFlightAttendant(const basicEmployeeInformation& flightAttendantInfo, std::string& error);
	Plane* createPlane(const std::string& serialNumber, int seats, std::string& error);
	Passenger* createPassenger(const basicInformation& basicInfo, std::string& error);
	Flight* createFlight(
		const std::string& planeSerialNumber,
		const std::string& pilotUniqueNumber,
		const std::string& serialNumber,
		const std::string& origin,
		const std::string& dest,
		const std::string& date,
		const std::string& time,
		std::vector<FlightAttendant*>& flightAttendants,
		std::vector<Passenger*>& passengers,
		std::string& error);

private:
	void _addFakeFlightAttendants();
	void _addFakePassengers();

private:
	std::vector<Person*> People;
	std::vector<Employee*> Employees;

	std::vector<Pilot*> Pilots;
	std::vector<Ticket*> Tickets;
	std::vector<FlightAttendant*> FlightAttendants;
	std::vector<Plane*> Planes;
	std::vector<Passenger*> Passengers;
	std::vector<Flight*> Flights;

private:
	bool checkIdNumber(const std::string& idNumber);
	bool checkPlaneSerialNumber(const std::string& serialNumber);
	bool checkFlightSerialNumber(const std::string& serialNumber);

	void AddPerson(Person* person);
	void AddEmployee(Employee* employee);

	void AddPilot(Pilot* pilot);
	void AddTicket(Ticket* ticket);
	void AddFlightAttendant(FlightAttendant* flightAttendant);
	void AddPlane(Plane* plane);
	void AddPassenger(Passenger* passenger);
	void AddFlight(Flight* flight);

public:
	std::vector<Person*> getAllPeople() { return People; }
	std::vector<Employee*> getAllEmployees() { return Employees; }

	std::vector<Pilot*> getAllPilots() {return Pilots; }
	std::vector<Ticket*> getAllTickets() {return Tickets; }
	std::vector<FlightAttendant*> getAllFlightAttendants() {return FlightAttendants; }
	std::vector<Plane*> getAllPlanes() {return Planes; }
	std::vector<Passenger*> getAllPassengers() {return Passengers; }
	std::vector<Flight*> getAllFlights() {return Flights; }
};

