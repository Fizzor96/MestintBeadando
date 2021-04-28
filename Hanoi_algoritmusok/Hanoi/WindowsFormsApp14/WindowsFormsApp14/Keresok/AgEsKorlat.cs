using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WindowsFormsApp14.AllapotTer;

namespace WindowsFormsApp14.Keresok
{
    class AgEsKorlat : Kereso
    {
        public AgEsKorlat()
        {
            Kereses();
        }

        public override void Kereses()
        {
            Stack<Csomopont> ut = new Stack<Csomopont>();
            ut.Push(new Csomopont(new Allapot(), 0));

            List<Csomopont> legjobbUtvonal = new List<Csomopont>();

            while (ut.Count > 0)
            {
                Csomopont aktualisCsomopont = ut.Peek();
                if (aktualisCsomopont.OperatorIndex < Operatorok.Count)
                {
                    Operator aktualisOperator = Operatorok[aktualisCsomopont.OperatorIndex];
                    if (aktualisOperator.Elofeltetel(aktualisCsomopont.Allapot))
                    {
                        Allapot ujAllapot = aktualisOperator.Mozgatas(aktualisCsomopont.Allapot);
                        Csomopont ujCsomopont = new Csomopont(ujAllapot, 0);
                        if (!ut.Contains(ujCsomopont))
                        {
                            if (legjobbUtvonal.Count == 0 || legjobbUtvonal.Count > ut.Count)
                            {
                                ut.Push(ujCsomopont);

                                if (ujCsomopont.Allapot.celfeltetel())
                                {
                                    if (legjobbUtvonal.Count == 0 || legjobbUtvonal.Count > ut.Count)
                                    {
                                        legjobbUtvonal.Clear();
                                        foreach (Csomopont cs in ut)
                                        {
                                            legjobbUtvonal.Add(cs);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    aktualisCsomopont.OperatorIndex++;
                }
                else
                {
                    // visszalépés
                    ut.Pop();
                }

            }

            foreach (Csomopont csomopont in legjobbUtvonal)
            {
                Utvonal.Add(csomopont.Allapot);
            }

            Utvonal.Reverse();

        }
    }
}
