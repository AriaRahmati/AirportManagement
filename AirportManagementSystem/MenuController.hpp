#pragma once

#include "includes.hpp"

class ObjectHandler;

class MenuController
{
public:
	MenuController(ObjectHandler* objectHandler) : objectHandler(objectHandler) { }

private:
	ObjectHandler* objectHandler;

public:
	void MainMenu();
	void AddObjectMenu();
	void ReportsMenu();

private:
	void AddPilot();
	void AddTicket();
	void AddFlightAttendant();
	void AddFlight();
	void AddPlane();
	void AddPassenger();

	void ClearScreen();
	void ErrorMessage(const std::string& error = "Unknown Error");
	void SuccessMessage(const std::string& title, const std::string& message);

	template <class T>
	void ChooseMenu(const std::vector<T*>& list, const std::string& title, std::vector<T*>& candidates);

	template <typename T>
	void getInput(const std::string& message, T& output);
};
