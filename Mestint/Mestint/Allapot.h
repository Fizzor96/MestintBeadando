#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include <string>

#include "Oszlop.h"
#include "Korong.h"

struct Allapot
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
			korongok.push_back(Korong(c1, "A"));
		}	
	}

	~Allapot() {}

	bool celfeltetel()
	{
		for (size_t i = 0; i < korongszam; i++)
		{
			if (korongok[i].oszlopid != "C")
			{
				return false;
			}
		}
		return true;
	}

	//bool celfeltetel()
	//{
	//	for (size_t i = 0; i < korongszam / 2; i++)
	//	{
	//		if (korongok[i].id % 2 == 1)
	//		{
	//			if (korongok[i].oszlopid != "C")
	//			{
	//				return false;
	//			}
	//		}
	//		if (korongok[i].id % 2 == 0)
	//		{
	//			if (korongok[i].oszlopid != "B")
	//			{
	//				return false;
	//			}
	//		}
	//	}
	//	return true;
	//}

	bool Equals(Allapot allapot)
	{
		for (size_t i = 0; i < korongok.size(); i++)
		{
			if (this->korongok[i].Equals(allapot.korongok[i]))
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
		{
			return *this;
		}
		
		this->korongok = other.korongok;
		this->korongszam = other.korongszam;
		this->oszlopok = other.oszlopok;
		return *this;
			
	}
};