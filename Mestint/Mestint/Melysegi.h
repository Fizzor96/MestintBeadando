#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include "Oprt.h"
#include "Kereso.h"
#include "Allapot.h"
#include "Csomopont.h"

class Melysegi : public Kereso
{
public:

	Melysegi()
	{
		Kereses();
	}

	~Melysegi() {}

    //nyiltcsucsok.Contains(ujCsomopont)
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

            //remove nyiltcsucsok last element
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
	}

};