using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp14.AllapotTer
{
    class Operator
    {
        private int melyiket;
        private string mire;

        public int Melyiket { get => melyiket; set => melyiket = value; }
        public string Mire { get => mire; set => mire = value; }

        public Operator(int melyiket, string mire)
        {
            this.melyiket = melyiket;
            this.mire = mire;
        }

        public Allapot Mozgatas(Allapot allapot)
        {
            Allapot ujAllapot = new Allapot();

            for (int i = 0; i < Allapot.KORONGSZAM; i++)
            {
                ujAllapot.Korongok[i] = allapot.Korongok[i];
            }

            ujAllapot.Korongok[melyiket] = mire;

            return ujAllapot;
        }

        public bool Elofeltetel(Allapot allapot)
        {
            if(allapot.Korongok[melyiket] == mire)
            {
                return false;
            }

            for (int i = 0; i < melyiket; i++)
            {
                if (allapot.Korongok[i] == allapot.Korongok[melyiket] || allapot.Korongok[i] == mire)
                {
                    return false;
                }
            }

            return true;
        }
    }
}
