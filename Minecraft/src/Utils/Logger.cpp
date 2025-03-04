#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

Logger::Logger(bool isOn)
{
	this->isOn = isOn;
}

void Logger::log(const char* text)
{
	auto now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);
	std::tm local_tm = *std::localtime(&now_time);
	std::ostringstream oss;  
	oss << "[" << std::put_time(&local_tm, "%H:%M:%S") << "]";
	std::string time_str = oss.str();
	std::cout << time_str + " " + "Logger" + " : " + text + "\n";
}