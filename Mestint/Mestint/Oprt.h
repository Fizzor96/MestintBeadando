#pragma once

#include <iostream>
#include <string>
#include "Allapot.h"
#include "Kereso.h"
#include "Melysegi.h"
#include "Csomopont.h"

class Oprt
{
public:
	int melyiket;
	int mire;

public:

	Oprt(int melyiket, int mire)
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
		//auto a = ujAllapot.korongok[melyiket];
		ujAllapot.korongok[melyiket] = allapot.korongok[mire];
		return ujAllapot;
	}

	bool Elofeltetel(Allapot allapot)
	{
		if (allapot.korongok[melyiket].Equals(allapot.korongok[mire]))
		{
			return false;
		}

		for (int i = 0; i < melyiket; i++)
		{
			if (allapot.korongok[i].Equals(allapot.korongok[melyiket]) || allapot.korongok[i].Equals(allapot.korongok[mire]))
			{
				return false;
			}
		}
		return true;
	}

};