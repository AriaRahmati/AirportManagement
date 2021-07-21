#pragma once

#include "Structs.hpp"

class Person
{
public:
	Person(const basicInformation& basicInfo): basicInfo(basicInfo) { }

protected:
	basicInformation basicInfo;

public:
	std::string getName() { return basicInfo.name; }
	std::string getFamilyName() { return basicInfo.familyName; }
	std::string getIdNumber() { return basicInfo.idNumber; }
};
