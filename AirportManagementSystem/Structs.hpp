#pragma once

#include "includes.hpp"

struct basicInformation
{
	basicInformation() { }
	basicInformation(
		const std::string& name,
		const std::string& familyName,
		const std::string& idNumber)
		: name(name), familyName(familyName), idNumber(idNumber) { }

	std::string name;
	std::string familyName;
	std::string idNumber;
};

struct basicEmployeeInformation
{
	basicEmployeeInformation() { }
	basicEmployeeInformation(
		const basicInformation& basicInfo,
		const std::string& personnelId,
		const std::string& birthDate,
		const std::string& employeementDate)
		: basicInfo(basicInfo), personnelId(personnelId), birthDate(birthDate), employeementDate(employeementDate) { }

	basicInformation basicInfo;

	std::string personnelId;
	std::string birthDate;
	std::string employeementDate;
};

enum class PilotGrade
{
	Grade_1,
	Grade_2,
	Grade_3
};
