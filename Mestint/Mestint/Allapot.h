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
	bool celfeltetel()
	{
		for (size_t i = 0; i < korongszam; i++)
		{
			if (i % 2 == 0 && korongok[i] != "A")
			{
				return false;
			}
			if (i % 2 == 1 && korongok[i] != "B")
			{
				return false;
			}
		}

		return true;	
	}

	Allapot()
	{
		for (size_t i = 0; i < korongszam; i++)
		{
			if (i < korongszam / 2)
			{
				this->korongok.push_back(std::string("A"));
			}
			else
			{
				this->korongok.push_back(std::string("B"));
			}
		}
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
		res += "[";
		for (size_t i = 0; i < korongszam - 1; i++)
		{
			res += korongok[i] + " ";
		}
		res += korongok[korongszam - 1];
		res += "]";
		return res;
	}
};

unsigned int Allapot::korongszam = 6;
std::vector<std::string> Allapot::oszlopok{ "A", "B", "C" };