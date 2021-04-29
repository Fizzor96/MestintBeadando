#pragma once

#include "Allapot.h"

class Csomopont
{
public:
	Allapot allapot;
	Csomopont* szulo;
	int koltseg;
	int operatorindex;
	int heurisztika;
	int osszkoltseg;

public:
	Csomopont() {}

	Csomopont(const Allapot& all, int operatorindex)
	{
		this->allapot = all;
		this->operatorindex = operatorindex;
	}

	Csomopont(Allapot allapot, Csomopont szulo)
	{
		this->allapot = allapot;
		this->szulo = &szulo;

		if (&szulo == nullptr)
		{
			koltseg = 0;
		}
		else
		{
			koltseg = szulo.koltseg + 1;
		}

		//this->heurisztika = 0;
		//for (Korong korong : this->allapot->korongok)
		//{
		//	if (korong.oszlopid == "P")
		//	{
		//		this->heurisztika += 1;
		//	}
		//	else if (korong.oszlopid == "Q")
		//	{
		//		this->heurisztika += 2;
		//	}
		//	else
		//	{
		//		this->heurisztika += 3;
		//	}
		//}
	}

	~Csomopont() {}

	bool Equals(Csomopont csomopont)
	{
		if (this->allapot.Equals(csomopont.allapot))
		{
			return true;
		}
		return false;
	}
};