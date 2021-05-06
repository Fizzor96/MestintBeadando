#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "Oprt.h"
#include "Allapot.h"
#include "Csomopont.h"

class Backtrack
{
public:
	std::vector<Allapot> utvonal;
	std::vector<Oprt> operatorok;

	Backtrack() {}

	~Backtrack() {}

    void Start()
    {
        std::cout << "Backtrack has started working!" << std::endl;
        OperatorokGeneralasa();
        Kereses();
        std::cout << "Backtrack finished with " << this->utvonal.size() << " steps!" << std::endl;
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

    bool Contains(std::vector<Csomopont> csucsok, Csomopont csomopont)
    {
        for (size_t i = 0; i < csucsok.size(); i++)
        {
            if (csucsok[i].Equals(csomopont))
            {
                return true;
            }
        }
        return false;
    }

	void Kereses()
	{
        std::vector<Csomopont> ut;
        ut.push_back(Csomopont(Allapot(), 0));
        
        while (ut.size() > 0 && !ut.back().allapot.celfeltetel())
        {
            //std::unique_ptr<Csomopont*> csuptr = std::make_unique<Csomopont*>();
            Csomopont& aktualisCsomopont = ut.back();
            if ((unsigned int)aktualisCsomopont.operatorindex < operatorok.size())
            {
                Oprt aktualisOperator = operatorok[aktualisCsomopont.operatorindex];
                if (aktualisOperator.Elofeltetel(aktualisCsomopont.allapot))
                {
                    Allapot ujAllapot = aktualisOperator.Mozgatas(aktualisCsomopont.allapot);
                    Csomopont ujCsomopont(Csomopont(ujAllapot, 0));

                    if (!Contains(ut, ujCsomopont))
                    {
                        ut.push_back(ujCsomopont);
                    }

                }
                aktualisCsomopont.operatorindex++;
                //std::cout << aktualisCsomopont->operatorindex << std::endl;
            }
            else
            {
                ut.pop_back();
            }

            for (Csomopont cs : ut)
            {
                utvonal.push_back(cs.allapot);
            }
            std::cout << utvonal.size() << " " << utvonal.back().ToString() << std::endl;
        }
	}

};