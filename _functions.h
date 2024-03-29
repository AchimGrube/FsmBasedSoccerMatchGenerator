#pragma once

#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <list>
#include <fstream>
#include <ctime>

#include "Match.h"

template<typename T> static int sign(T);
static void processText(std::string, Match& match);
static void pause(int);
static void writeToFile(std::list<std::string>);
static std::string getDateTimeString();


// Signumfunktion
// value > 0 return 1
// value = 0 return 0
// value < 0 return -1
template<typename T> static int sign(T value)
{
	return (T(0) < value) - (T(0) > value);
}

// Textausgabe auf der Konsole und hinterlegen in einer Liste, die am Ende in eine Datei geschrieben werden kann
static void processText(std::string text, Match& match)
{
	std::cout << text;
	match.addTextOutput(text);
}

// Programm pausiert f�r x Millisekunden
static void pause(int duration)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(duration));
}

// Textausgabe aus Liste in Datei schreiben
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

// Datum und Uhrzeit f�r Dateinamen in einen String schreiben
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