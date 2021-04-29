#pragma once
#include "Allapot.h"
#include "Melysegi.h"

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

	Csomopont(Allapot allapot, int operatorindex)
	{
		this->allapot = allapot;
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

		this->heurisztika = 0;
		for (std::string korong : this->allapot.korongok)
		{
			if (korong == "P")
			{
				this->heurisztika += 1;
			}
			else if (korong == "Q")
			{
				this->heurisztika += 2;
			}
			else
			{
				this->heurisztika += 3;
			}
		}
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