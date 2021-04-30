#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <thread>

#include "Oprt.h"
#include "Allapot.h"
#include "Csomopont.h"
#include "Oszlop.h"

class Melysegi
{
public:

    std::vector<Allapot> utvonal;
    std::vector<Oprt> operatorok;

	Melysegi() {}

	~Melysegi() {}

    void Start()
    {
        Allapot::oszlopok.push_back(Oszlop("A", 150.f));
        Allapot::oszlopok.push_back(Oszlop("B", 500.f));
        Allapot::oszlopok.push_back(Oszlop("C", 850.f));
        OperatorokGeneralasa();
        Kereses();
    }

    void OperatorokGeneralasa()
    {
        for (size_t i = 0; i < Allapot::korongszam; i++)
        {
            for (size_t j = 0; j < Allapot::oszlopok.size(); j++)
            {
                Oprt ujOperator(i, Allapot::oszlopok[j].nev);
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
        std::vector<Csomopont> nyiltcsucsok;
        std::vector<Csomopont> zartcsucsok;

        nyiltcsucsok.push_back(Csomopont(Allapot(), -1));

        while (nyiltcsucsok.size() > 0 && !nyiltcsucsok.back().allapot.celfeltetel())
        {
            
            Csomopont aktualisCsomopont(nyiltcsucsok.back());

            nyiltcsucsok.pop_back();

            for (Oprt op : operatorok)
            {
                if (op.Elofeltetel(aktualisCsomopont.allapot))
                {
                    Allapot ujAllapot = op.Mozgatas(aktualisCsomopont.allapot);

                    Csomopont ujCsomopont(ujAllapot, aktualisCsomopont);

                    if (!Contains(nyiltcsucsok, ujCsomopont) && !Contains(zartcsucsok, ujCsomopont))
                    {
                        nyiltcsucsok.push_back(ujCsomopont);
                        
                    }
                }
                std::cout << aktualisCsomopont.allapot.ToString() << std::endl;
            }
            zartcsucsok.push_back(aktualisCsomopont);
        }

        if (nyiltcsucsok.size() > 0)
        {
            Csomopont celCsomopont = nyiltcsucsok.back();
            
            utvonal.push_back(celCsomopont.allapot);
            celCsomopont = *celCsomopont.szulo;

            std::reverse(utvonal.begin(), utvonal.end());
        }
        std::cout << "Depthsearch Done!" << std::endl;
	}

};