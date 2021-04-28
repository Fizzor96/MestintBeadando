using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WindowsFormsApp14.AllapotTer;

namespace WindowsFormsApp14.Keresok
{
    class Aalgoritmus : Kereso
    {

        public Aalgoritmus()
        {
            Kereses();
        }

        public override void Kereses()
        {
            Stack<Csomopont> nyiltcsucsok = new Stack<Csomopont>();
            List<Csomopont> zartcsucsok = new List<Csomopont>();

            nyiltcsucsok.Push(new Csomopont(new Allapot(), null));
            while (nyiltcsucsok.Count > 0 && !nyiltcsucsok.Peek().Allapot.celfeltetel())
            {
                Csomopont aktualisCsomopont = nyiltcsucsok.Pop();
                List<Csomopont> aktualisCsomopontGyerekei = new List<Csomopont>();
                foreach (Operator op in Operatorok)
                {
                    if (op.Elofeltetel(aktualisCsomopont.Allapot))
                    {
                        Allapot ujAllpot = op.Mozgatas(aktualisCsomopont.Allapot);
                        //szülőt beállítjuk
                        Csomopont ujCsomopont = new Csomopont(ujAllpot, aktualisCsomopont);
                        if (!nyiltcsucsok.Contains(ujCsomopont) && !zartcsucsok.Contains(ujCsomopont))
                        {
                            aktualisCsomopontGyerekei.Add(ujCsomopont);
                        }
                    }
                }

                aktualisCsomopontGyerekei.Sort(
                    delegate (Csomopont cs1, Csomopont cs2)
                    {
                        if (cs1.Osszkoltseg > cs2.Osszkoltseg)
                        {
                            return -1;
                        }
                        else if (cs1.Osszkoltseg < cs2.Osszkoltseg)
                        {
                            return 1;
                        }
                        else
                        {
                            return 0;
                        }
                    });


                foreach (Csomopont cs in aktualisCsomopontGyerekei)
                {
                    nyiltcsucsok.Push(cs);
                }

                zartcsucsok.Add(aktualisCsomopont);
            }

            if (nyiltcsucsok.Count > 0)
            {
                Csomopont celCsomopont = nyiltcsucsok.Peek();
                while (celCsomopont != null)
                {
                    this.Utvonal.Add(celCsomopont.Allapot);
                    celCsomopont = celCsomopont.Szulo;
                }
                this.Utvonal.Reverse();
            }
        }
    }
}
