#pragma once

#include <iostream>
#include <thread>
#include <string>
#include <Windows.h>

using namespace std;

class Functions
{
public:

	void mainMenu();		// ------------------------------------> Start app 
	void backToMainMenu();	// ------------------------------------> Return to main menu
	void delay();			// ------------------------------------> Delay through thread
	void info();			// ------------------------------------> information about APP

};