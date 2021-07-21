#include "Pilot.hpp"

std::string Pilot::getGradeDisplayName()
{
	switch (grade)
	{
	case PilotGrade::Grade_1:
		return "Grade 1";
		break;
	case PilotGrade::Grade_2:
		return "Grade 2";
		break;
	case PilotGrade::Grade_3:
		return "Grade 2";
		break;
	}
}
