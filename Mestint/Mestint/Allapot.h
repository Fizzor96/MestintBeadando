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
		for (size_t i = 0; i < korongszam / 2; i++)
		{
			//this->korongok[i] = std::string("A");
			this->korongok.push_back(std::string("A"));
		}
		for (size_t i = 0; i < korongszam / 2; i++)
		{
			//this->korongok[i] = std::string("A");
			this->korongok.push_back(std::string("B"));
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

	/// <summary>
	/// Cel: egy olyan celfeltetel konstrualasa, melyben minden masodik korong mas szinu es szeparalasuk megvalosuljon az eddigi feltetelek mellett
	/// </summary>
	/// <returns></returns>
	bool celfeltetel_original()
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

	/// <summary>
	/// Mukodo celfeltetel egyszinu toronyra, melyek el vannak szeparalva
	/// </summary>
	/// <returns></returns>
	bool celfeltetel()
	{
		bool sum = false;
		bool t1 = true;
		bool t2 = true;
		for (size_t i = 0; i < korongszam / 2; i++)
		{
			if (korongok[i] != "C")
			{
				t1 = false;
			}
		}
		for (size_t i = korongszam / 2; i < korongszam; i++)
		{
			if (korongok[i] != "B")
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

unsigned int Allapot::korongszam = 8;
std::vector<std::string> Allapot::oszlopok{ "A", "B", "C" };