#pragma once

#include <iostream>
#include <vector>
#include "Oprt.h"
#include "Allapot.h"
#include "Csomopont.h"
#include <thread>

class Melysegi
{
public:

    std::vector<Allapot> utvonal;
    std::vector<Oprt> operatorok;
    Allapot kezdo;

    Melysegi() {

        kezdo = Allapot();
    }

    ~Melysegi() {}

    void Start()
    {
        std::cout << "Depthsearch has started!" << std::endl;
        OperatorokGeneralasa();
        Kereses();

        std::cout << kezdo.ToString() << std::endl;
        for (size_t i = 0; i < utvonal.size(); i++)
        {
            std::cout << utvonal[i].ToString() << std::endl;
        }

        std::cout << "Depthsearch Done!" << std::endl;
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

        nyiltcsucsok.push_back(Csomopont(kezdo, -1));

        //std::cout << nyiltcsucsok.back().allapot.ToString() << std::endl;

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
            }
            zartcsucsok.push_back(aktualisCsomopont);
            //LOG
            //std::cout << nyiltcsucsok.back().allapot.ToString() << std::endl;
            if (nyiltcsucsok.size() > 0)
            {
                Csomopont celCsomopont = nyiltcsucsok.back();

                utvonal.push_back(celCsomopont.allapot);
                celCsomopont = *celCsomopont.szulo;

                //std::reverse(utvonal.begin(), utvonal.end());
            }
        }
    }

};