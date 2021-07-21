#pragma once

#include "Person.hpp"
#include "Structs.hpp"

class Employee : public Person
{
public:
	Employee(const basicEmployeeInformation& basicEmployeeInfo)
		: Person(basicEmployeeInfo.basicInfo), basicEmployeeInfo(basicEmployeeInfo) { }

protected:
	basicEmployeeInformation basicEmployeeInfo;

	std::vector<class Flight*> jobs;

public:
	std::string getPersonnelId() { return basicEmployeeInfo.personnelId; }
	std::string getBirthDate() { return basicEmployeeInfo.birthDate; }
	std::string getEmployeementDate() { return basicEmployeeInfo.employeementDate; }
};
