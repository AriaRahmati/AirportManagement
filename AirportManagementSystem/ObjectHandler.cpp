#include "ObjectHandler.hpp"

#include "Person.hpp"
#include "Employee.hpp"
#include "Pilot.hpp"
#include "Ticket.hpp"
#include "FlightAttendant.hpp"
#include "Flight.hpp"
#include "Plane.hpp"
#include "Passenger.hpp"

ObjectHandler::ObjectHandler()
{
    _addFakeFlightAttendants();
    _addFakePassengers();
}

Pilot* ObjectHandler::createPilot(const basicEmployeeInformation& pilotInfo, int grade, std::string& error)
{
    if (grade < 1 || grade > 3)
    {
        error = "Pilot's grade must either 1, 2 or 3";
        return nullptr;
    }

    if (!checkIdNumber(pilotInfo.basicInfo.idNumber))
    {
        error = "ID Number is duplicate";
        return nullptr;
    }
    
    Pilot* newPilot = new Pilot(pilotInfo, (PilotGrade)grade);
    if (newPilot)
        AddPilot(newPilot);

    return newPilot;
}

FlightAttendant* ObjectHandler::createFlightAttendant(const basicEmployeeInformation& flightAttendantInfo, std::string& error)
{
    if (!checkIdNumber(flightAttendantInfo.basicInfo.idNumber))
    {
        error = "ID Number is duplicate";
        return nullptr;
    }

    FlightAttendant* newFlightAttandant = new FlightAttendant(flightAttendantInfo);
    if (newFlightAttandant)
        AddFlightAttendant(newFlightAttandant);

    return newFlightAttandant;
}

Plane* ObjectHandler::createPlane(const std::string& serialNumber, int seats, std::string& error)
{
    if (!checkPlaneSerialNumber(serialNumber))
    {
        error = "Serial Number is duplicate";
        return nullptr;
    }

    Plane* newPlane = new Plane(serialNumber, seats);
    if (newPlane)
        AddPlane(newPlane);

    return newPlane;
}

Passenger* ObjectHandler::createPassenger(const basicInformation& basicInfo, std::string& error)
{
    if (!checkIdNumber(basicInfo.idNumber))
    {
        error = "ID Number is duplicate";
        return nullptr;
    }

    Passenger* newPassenger = new Passenger(basicInfo);
    if (newPassenger)
        AddPassenger(newPassenger);

    return newPassenger;
}

Flight* ObjectHandler::createFlight(
    const std::string& planeSerialNumber, const std::string& pilotUniqueNumber, const std::string& serialNumber,
    const std::string& origin, const std::string& dest, const std::string& date, const std::string& time,
    std::vector<FlightAttendant*>& flightAttendants, std::vector<Passenger*>& passengers, std::string& error)
{
    // Check the plain's serial number is valid and keep its pointer
    // Check pilots unique number in his/her idNumber or personnelNumber if its valid and keep its pointer
    return nullptr;
}

void ObjectHandler::_addFakeFlightAttendants()
{
    std::string names[] = { "Abtin", "Ali", "Reza", "Mohsen" };
    std::string familyNames[] = { "Akbari", "Moradi", "Asgari", "Javadi" };
    std::string idNumbers[] = { "111", "222", "333", "444" };
    std::string personnelNumbers[] = { "11111", "22222", "33333", "44444" };
    std::string birthDates[] = { "25/01/2000", "10/02/1999", "05/08/1990", "15/12/2001" };
    std::string exployeementDates[] = { "25/01/2000", "10/02/1999", "05/08/1990", "15/12/2001" };

    for (int i = 0; i < 4; ++i)
    {
        std::string error;
        basicInformation info_1(names[i], familyNames[i], idNumbers[i]);
        basicEmployeeInformation info_2(info_1, personnelNumbers[i], birthDates[i], exployeementDates[i]);
        createFlightAttendant(info_2, error);
    }
}

void ObjectHandler::_addFakePassengers()
{
    std::string names[] = { "Arta", "Arad", "Farnood", "Hooman" };
    std::string familyNames[] = { "Seyedi", "Rezayi", "Shirazi", "Semnani" };
    std::string idNumbers[] = { "555", "666", "777", "888" };

    for (int i = 0; i < 4; ++i)
    {
        std::string error;
        basicInformation info(names[i], familyNames[i], idNumbers[i]);
        createPassenger(info, error);
    }
}

bool ObjectHandler::checkIdNumber(const std::string& idNumber)
{
    for (Person* person : People)
    {
        if (idNumber == person->getIdNumber())
            return false;
    }

    return true;
}

bool ObjectHandler::checkPlaneSerialNumber(const std::string& serialNumber)
{
    for (Plane* plane : Planes)
    {
        if (serialNumber == plane->getSerialNumber())
            return false;
    }

    return true;
}

bool ObjectHandler::checkFlightSerialNumber(const std::string& serialNumber)
{
    for (Flight* flight : Flights)
    {
        if (serialNumber == flight->getSerialNumber())
            return false;
    }

    return true;
}

void ObjectHandler::AddPerson(Person* person)
{
    People.push_back(person);
}

void ObjectHandler::AddEmployee(Employee* employee)
{
    Employees.push_back(employee);
    AddPerson(employee);
}

void ObjectHandler::AddPilot(Pilot* pilot)
{
    Pilots.push_back(pilot);
    AddEmployee(pilot);
}

void ObjectHandler::AddTicket(Ticket* ticket)
{
    Tickets.push_back(ticket);
}

void ObjectHandler::AddFlightAttendant(FlightAttendant* flightAttendant)
{
    FlightAttendants.push_back(flightAttendant);
    AddEmployee(flightAttendant);
}

void ObjectHandler::AddPlane(Plane* plane)
{
    Planes.push_back(plane);
}

void ObjectHandler::AddPassenger(Passenger* passenger)
{
    Passengers.push_back(passenger);
    AddPerson(passenger);
}

void ObjectHandler::AddFlight(Flight* flight)
{
    Flights.push_back(flight);
}