#pragma once

#include "Employee.hpp"

class FlightAttendant : public Employee
{
public:
	FlightAttendant(const basicEmployeeInformation& basicEmployeeInfo) : Employee(basicEmployeeInfo) { }
};
