#include "MenuController.hpp"

#include "includes.hpp"

#include "Structs.hpp"
#include "ObjectHandler.hpp"
#include "FlightAttendant.hpp"
#include "Passenger.hpp"

void MenuController::MainMenu()
{
	ClearScreen();

	std::cout << "\tAirport Management App\n\n";
	std::cout << "1) Add Object\n";
	std::cout << "2) Reports\n";

	while (true)
		switch (_getch())
		{
		case '1':
			AddObjectMenu();
			break;
		case '2':
			ReportsMenu();
			break;
		}
}

void MenuController::AddObjectMenu()
{
	ClearScreen();

	std::cout << "\tAdd Objects\n\n";
	std::cout << "1) Add a Pilot\n";
	std::cout << "2) Add a Ticket\n";
	std::cout << "3) Add a Flight Attendant\n";
	std::cout << "4) Add a Flight\n";
	std::cout << "5) Add a Plane\n";
	std::cout << "6) Add a Passenger\n";
	std::cout << "0) Return\n";

	while (true)
		switch (_getch())
		{
		case '1':
			AddPilot();
			break;
		case '2':
			AddTicket();
			break;
		case '3':
			AddFlightAttendant();
			break;
		case '4':
			AddFlight();
			break;
		case '5':
			AddPlane();
			break;
		case '6':
			AddPassenger();
			break;
		case '0':
			MainMenu();
			break;
		}
}

void MenuController::ReportsMenu()
{
	ClearScreen();
}

void MenuController::AddPilot()
{
	ClearScreen();
	std::cout << "\tAdd a Pilot\n\n";

	basicEmployeeInformation pilotInfo;
	int grade;

	std::cout << "Please Enter Pilot's info\n";
	getInput("Name", pilotInfo.basicInfo.name);
	getInput("Family Name", pilotInfo.basicInfo.familyName);
	getInput("ID Number", pilotInfo.basicInfo.idNumber);
	getInput("Personnel Number", pilotInfo.personnelId);
	getInput("Birth Date (ex: 04/11/1980)", pilotInfo.birthDate);
	getInput("Emplyeement Date (ex: 04/11/1980)", pilotInfo.employeementDate);
	getInput("Grade (1, 2, 3)", grade);

	std::string error;
	if (objectHandler->createPilot(pilotInfo, grade, error))
	{
		SuccessMessage("Pilot", pilotInfo.basicInfo.name + " " + pilotInfo.basicInfo.familyName);
		_getch();
	}
	else
		ErrorMessage(error);

	AddObjectMenu();
}

void MenuController::AddTicket()
{
}

void MenuController::AddFlightAttendant()
{
	ClearScreen();
	std::cout << "\tAdd a Fligh Attendant\n\n";

	basicEmployeeInformation flightAttendantInfo;

	std::cout << "Please Enter Flight Attendant's info\n";
	getInput("Name", flightAttendantInfo.basicInfo.name);
	getInput("Family Name", flightAttendantInfo.basicInfo.familyName);
	getInput("ID Number", flightAttendantInfo.basicInfo.idNumber);
	getInput("Personnel Number", flightAttendantInfo.personnelId);
	getInput("Birth Date (ex: 04/11/1980)", flightAttendantInfo.birthDate);
	getInput("Emplyeement Date (ex: 04/11/1980)", flightAttendantInfo.employeementDate);

	std::string error;
	if (objectHandler->createFlightAttendant(flightAttendantInfo, error))
	{
		SuccessMessage("Flight Attendant", flightAttendantInfo.basicInfo.name + " " + flightAttendantInfo.basicInfo.familyName);
		_getch();
	}
	else
		ErrorMessage(error);

	AddObjectMenu();
}

void MenuController::AddFlight()
{
	ClearScreen();
	std::cout << "\tAdd a Flight\n\n";

	std::string setialNumber, origin, dest, date, time;
	std::string plainSerialNumber, pilotUniqueNumber;
	std::vector<std::string> flightAttendantsUniqueNumber, passengersIdNumber;

	std::cout << "Please Enter Flight's info\n";
	getInput("Serial Number", setialNumber);
	getInput("Origin", origin);
	getInput("Destination", dest);
	getInput("Date (ex: 04/11/1980)", date);
	getInput("Time (ex: 20:15)", time);
	getInput("Plain's Serial Number", plainSerialNumber);
	getInput("Pilot's ID Number or Personnel Number", pilotUniqueNumber);

	std::vector<FlightAttendant*> flightAttendants = objectHandler->getAllFlightAttendants();
	std::vector<FlightAttendant*> fa_candidates; // flightAttendants_candidates
	ChooseMenu<FlightAttendant>(flightAttendants, "Flight Attendant", fa_candidates);

	std::vector<Passenger*> passengers = objectHandler->getAllPassengers();
	std::vector<Passenger*> p_candidates; // passengers_candidates
	ChooseMenu<Passenger>(passengers, "Passenger", p_candidates);

	//std::string error;
	//if (objectHandler->createPilot(pilotInfo, grade, error))
	//{
	//	SuccessMessage("Pilot", pilotInfo.basicInfo.name + " " + pilotInfo.basicInfo.familyName);
	//	_getch();
	//	AddObjectMenu();
	//}
	//else
	//{
	//	ErrorMessage(error);
	//	getInput("Grade (1, 2, 3)", grade); // We know that the only input that throws error in AddObject::pilot is grade
	//}
}

void MenuController::AddPlane()
{
	ClearScreen();
	std::cout << "\tAdd a Plane\n\n";

	std::string serialNumber;
	int seats;

	std::cout << "Please Enter Plane's info\n";
	getInput("Serial Number", serialNumber);
	getInput("Number of Seats", seats);

	std::string error;
	if (objectHandler->createPlane(serialNumber, seats, error))
	{
		SuccessMessage("Plane", serialNumber);
		_getch();
	}
	else
		ErrorMessage(error);

	AddObjectMenu();
}

void MenuController::AddPassenger()
{
	ClearScreen();
	std::cout << "\tAdd a Passenger\n\n";

	basicInformation passengerInfo;

	std::cout << "Please Enter Passenger's info\n";
	getInput("Name", passengerInfo.name);
	getInput("Family Name", passengerInfo.familyName);
	getInput("ID Number", passengerInfo.idNumber);

	std::string error;
	if (objectHandler->createPassenger(passengerInfo, error))
	{
		SuccessMessage("Passenger", passengerInfo.name + " " + passengerInfo.familyName);
		_getch();
	}
	else
		ErrorMessage(error);

	AddObjectMenu();
}

template <class T>
void MenuController::ChooseMenu(const std::vector<T*>& list, const std::string& title, std::vector<T*>& candidates)
{
	ClearScreen();

	for (int i = 0; i < list.size(); ++i)
	{
		T* element = list.at(i);
		Person* castElement = static_cast<Person*>(element);
		std::cout << std::setw(3) << i + 1 << ") " << castElement->getName() + " " + castElement->getFamilyName() + " (" + castElement->getIdNumber() + ")\n";
	}

	std::cout << "Enter " + title + "'s Number one by one (Enter 0 to finish adding)\n";

	int fa_Number = -1; // flightAttandantNumber
	do
	{
		getInput("Number", fa_Number);
		if (fa_Number == 0)
			break;

		if (fa_Number > 0 && fa_Number <= list.size())
		{
			T* candidate = list.at(fa_Number - 1);
			if (std::find(candidates.begin(), candidates.end(), candidate) != candidates.end())
				ErrorMessage(title + " \'" + candidate->getName() + " " + candidate->getFamilyName() + "\' has already been added");
			else
				candidates.push_back(candidate);
		}
		else
			ErrorMessage("Out of range");
	} while (fa_Number != 0);

	ClearScreen();
}

template <typename T>
void MenuController::getInput(const std::string& message, T& output)
{
	std::cout << message << ": ";
	std::cin >> output;
}

void MenuController::ClearScreen()
{
	system("cls");
}

void MenuController::ErrorMessage(const std::string& error)
{
	std::cout << " > Error! " << error << "\t| Press Enter to continue\n";
	while (true)
		if (_getch() == 13) // Enter
			break;
}


void MenuController::SuccessMessage(const std::string& title, const std::string& message)
{
	std::cout << " > " << title << " \'" << message << "\' successfully added\n";
}
