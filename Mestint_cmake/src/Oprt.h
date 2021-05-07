#pragma once

#include <iostream>
#include <string>
#include "Allapot.h"
#include "Kereso.h"
#include "Melysegi.h"
#include "Csomopont.h"

/// <summary>
/// Pakolas implementacioja ide kerul
/// </summary>
class Oprt
{
public:
	int melyiket;
	std::string mire;

public:

	Oprt(int melyiket, std::string mire)
	{
		this->melyiket = melyiket;
		this->mire = mire;
	}

	~Oprt() {}

	Allapot Mozgatas(Allapot allapot)
	{
		Allapot ujAllapot;

		for (size_t i = 0; i < Allapot::korongszam; i++)
		{
			ujAllapot.korongok[i] = allapot.korongok[i];
		}
		ujAllapot.korongok[melyiket] = mire;
		return ujAllapot;
	}

	bool Elofeltetel(Allapot allapot)
	{
		if (allapot.korongok[melyiket] == mire)
		{
			return false;
		}

		for (int i = 0; i < melyiket; i++)
		{
			if (allapot.korongok[i] == allapot.korongok[melyiket] || allapot.korongok[i] == mire)
			{
				return false;
			}
		}
		return true;
	}

};