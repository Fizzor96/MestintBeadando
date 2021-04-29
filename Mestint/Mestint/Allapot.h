#pragma once
#include <iostream>
#include <vector>

class Allapot
{
public:
	static int korongszam;
	std::vector<std::string> korongok;
	static std::vector<std::string> oszlopok;

public:
	Allapot()
	{
		for (size_t i = 0; i < korongszam; i++)
		{
			this->korongok[i] = "A";
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
};

int Allapot::korongszam = 3;
std::vector<std::string> Allapot::oszlopok{ "A", "B", "C"}