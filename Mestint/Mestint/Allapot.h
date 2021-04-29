#pragma once

#include <iostream>
#include <vector>
#include "Hanoi.h"

class Allapot
{
public:
	static unsigned int korongszam;
	static std::vector<std::string> oszlopok;
	std::vector<std::string> korongok;
	

public:
	Allapot()
	{
		for (size_t i = 0; i < korongszam; i++)
		{
			//this->korongok[i] = std::string("A");
			this->korongok.push_back(std::string("A"));
		}
	}

	bool celfeltetel()
	{
		for (size_t i = 0; i < korongszam; i++)
		{
			if (korongok[i] != "C")
			{
				return false;
			}
		}
		return true;
	}

	bool Equals(Allapot allapot)
	{
		for (size_t i = 0; i < korongok.size(); i++)
		{
			if (this->korongok[i] != allapot.korongok[i])
			{
				return false;
			}
		}
		return true;
	}

	std::string ToString()
	{
		std::string res = "";
		res += "(";
		for (size_t i = 0; i < korongszam - 1; i++)
		{
			res += korongok[i] + " ";
		}
		res += korongok[korongszam - 1];
		res += ")";
		return res;
	}
};

unsigned int Allapot::korongszam = 5;
std::vector<std::string> Allapot::oszlopok{ "A", "B", "C" };