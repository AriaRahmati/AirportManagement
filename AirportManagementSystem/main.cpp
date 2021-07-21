#include <iostream>

#include "ObjectHandler.hpp"
#include "MenuController.hpp"

int main()
{
	ObjectHandler* objectHandler = new ObjectHandler();
	MenuController* menu = new MenuController(objectHandler);
	menu->MainMenu();

	/*std::string name = "Aria", familyName = "Rahmaty", idNumber = "0312088515";
	std::string pId = "123", bD = "01/02/2000", eD = "15/05/2018";
	basicInformation FABI(name, familyName, idNumber);
	basicEmployeeInformation FABEI(FABI, pId, bD, eD);
	Pilot FA(FABEI, PilotGrade::Grade_2);

	std::cout << FA.getName() << " "
		<< FA.getFamilyName() << " "
		<< FA.getIdNumber() << " "
		<< FA.getPersonnelId() << " "
		<< FA.getBirthDate() << " "
		<< FA.getEmployeementDate() << " "
		<< FA.getGradeName() << " ";*/

	std::cin.get();
}
