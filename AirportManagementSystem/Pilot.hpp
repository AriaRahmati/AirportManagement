#pragma once

#include "Employee.hpp"

class Pilot : public Employee
{
public:
	Pilot(const basicEmployeeInformation& basicEmployeeInfo, PilotGrade grade)
		: Employee(basicEmployeeInfo), grade(grade) { }

protected:
	PilotGrade grade;

public:
	PilotGrade getGrade() { return grade; }
	std::string getGradeDisplayName();
};
