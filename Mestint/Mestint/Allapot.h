#pragma once

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Hanoi.h"
#include "Oszlop.h"

class Allapot
{
public:
	//static unsigned int korongszam;
	//static std::vector<std::string> oszlopok;
	//std::vector<std::string> korongok;

	static unsigned int korongszam;
	static std::vector<Oszlop> oszlopok;
	std::vector<Korong> korongok;

	const sf::Color c1 = sf::Color::Green;
	const sf::Color c2 = sf::Color::Blue;
	

public:
	//Allapot()
	//{
	//	for (size_t i = 0; i < korongszam; i++)
	//	{
	//		//this->korongok[i] = std::string("A");
	//		this->korongok.push_back(std::string("A"));
	//	}
	//}

	Allapot()
	{
		for (size_t i = 0; i < korongszam; i++)
		{
			if (i % 2 == 0)
			{
				korongok.push_back(Korong(c1, "A"));
			}
			else
			{
				korongok.push_back(Korong(c2, "B"));
			}
		}
	}

	//bool celfeltetel()
	//{
	//	for (size_t i = 0; i < korongszam; i++)
	//	{
	//		if (korongok[i] != "C")
	//		{
	//			return false;
	//		}
	//	}
	//	return true;
	//}

	bool celfeltetel()
	{
		bool sum = false;
		bool t1 = true;
		bool t2 = true;
		for (size_t i = 0; i < korongszam / 2; i++)
		{
			if (korongok[i].id % 2 == 0 && korongok[i].oszlopid != "C")
			{
				t1 = false;
			}
			if (korongok[i].id % 2 == 1 && korongok[i].oszlopid != "B")
			{
				t2 = false;
			}
		}
		if (t1 == true && t2 == true)
		{
			sum = true;
		}
		return sum;
	}

	bool Equals(Allapot allapot)
	{
		for (size_t i = 0; i < korongok.size(); i++)
		{
			if (this->korongok[i].oszlopid != allapot.korongok[i].oszlopid && this->korongok[i].szin != allapot.korongok[i].szin)
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
			res += korongok[i].oszlopid + " ";
		}
		res += korongok[korongszam - 1].oszlopid;
		res += ")";
		return res;
	}

	Allapot& operator=(const Allapot& other)
	{
		if (this == &other)
			return *this;
	}
};

unsigned int Allapot::korongszam = 8;

std::vector<Oszlop> Allapot::oszlopok{ Oszlop("A", 150.f), Oszlop("B", 500.f), Oszlop("C", 850.f) };