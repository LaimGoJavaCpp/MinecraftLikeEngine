#pragma once

#include <iostream>

class Logger
{
public:
	Logger(bool isOn);
	static void log(const char* text);
private:
	bool isOn;
};