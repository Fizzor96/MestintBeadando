#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Oprt.h"
#include "Csomopont.h"
#include "Allapot.h"

class ProbaHiba
{

public:
	std::vector<Allapot> utvonal;
	std::vector<Oprt> operatorok;

public:
	ProbaHiba()
	{
		//srand(time(NULL));
	}

	~ProbaHiba() {}

	int Random(int vectorsize)
	{
		return rand() % vectorsize;
	}

	void Start()
	{
		std::cout << "ProbaHibaRandom has started working!" << std::endl;
		OperatorokGeneralasa();
		Kereses();
		std::cout << "ProbaHibaRandom finished with " << this->utvonal.size() << " steps!" << std::endl;
	}

	void OperatorokGeneralasa()
	{
		for (size_t i = 0; i < Allapot::korongszam; i++)
		{
			for (size_t j = 0; j < Allapot::oszlopok.size(); j++)
			{
				Oprt ujOperator(i, Allapot::oszlopok[j]);
				operatorok.push_back(ujOperator);
			}
		}
	}

	void Kereses()
	{
		std::vector<Allapot> ut;
		ut.push_back(Allapot());
		srand(time(NULL));

		while (!ut.back().celfeltetel())
		{

			int randInd = Random(operatorok.size());
			//std::cout << randInd << std::endl;

			Oprt kivalszottOperator = operatorok[randInd];

			if (kivalszottOperator.Elofeltetel(ut.back()))
			{
				Allapot ujAllapot = kivalszottOperator.Mozgatas(ut.back());
				ut.push_back(ujAllapot);
			}
		}

		for (Allapot allapot : ut)
		{
			utvonal.push_back(allapot);
		}
	}
};