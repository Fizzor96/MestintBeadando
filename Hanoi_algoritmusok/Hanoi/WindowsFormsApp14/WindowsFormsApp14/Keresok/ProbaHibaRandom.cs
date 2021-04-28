using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WindowsFormsApp14.AllapotTer;

namespace WindowsFormsApp14.Keresok
{
    class ProbaHibaRandom : Kereso
    {
        public ProbaHibaRandom()
        {
            Kereses();
        }

        public override void Kereses()
        {
            Allapot kezdoAllapot = new Allapot();
            List<Allapot> ut = new List<Allapot>();

            ut.Add(kezdoAllapot);

            Random random = new Random();

            while (!ut.Last().celfeltetel())
            {
                int randInd = random.Next(0, Operatorok.Count);
                Operator kivalszottOperator = Operatorok[randInd];

                if (kivalszottOperator.Elofeltetel(ut.Last()))
                {
                    Allapot ujAllapot = kivalszottOperator.Mozgatas(ut.Last());
                    ut.Add(ujAllapot);
                }
            }

            foreach(Allapot allapot in ut)
            {
                Utvonal.Add(allapot);
            }
        }
    }
}
