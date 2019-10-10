#pragma once

#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <list>
#include <fstream>
#include <ctime>

template<typename T> static int sign(T);
static void processText(std::string);
static void pause(int);
static void writeToFile(std::list<std::string>);
static std::string getDateTimeString();

template<typename T> static int sign(T value)
{
	return (T(0) < value) - (T(0) > value);
}

static void processText(std::string text)
{
	std::cout << text;
}

static void pause(int duration)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(duration));
}

static void writeToFile(std::list<std::string> lines)
{
	std::ofstream file;

	std::string filename = "match_" + getDateTimeString() + ".txt";

	file.open(filename);

	if (file)
	{
		for (auto line : lines)
		{
			file << line;
		}
	}

	file.close();

	std::cout << filename << " erfolgreich gespeichert.\n";
}

static std::string getDateTimeString()
{
	time_t time;
	std::time(&time);
	struct std::tm now;
	localtime_s(&now, &time);

	char buffer[32];
	snprintf(buffer, 32, "%02d_%02d_%04d_%02d_%02d_%02d", now.tm_mday, now.tm_mon + 1, now.tm_year + 1900, now.tm_hour, now.tm_min, now.tm_sec);
	
	return buffer;
}