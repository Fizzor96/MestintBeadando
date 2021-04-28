using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp14.AllapotTer
{
    class Csomopont
    {
        Allapot allapot;
        internal Allapot Allapot { get => allapot; set => allapot = value; }
        internal Csomopont Szulo { get => szulo; set => szulo = value; }
        public int Koltseg { get => koltseg; set => koltseg = value; }
        public int OperatorIndex { get => operatorIndex; set => operatorIndex = value; }
        public int Heurisztika { get => heurisztika; set => heurisztika = value; }
        public int Osszkoltseg { get => osszkoltseg; set => osszkoltseg = value; }

        Csomopont szulo;

        //lepesek szama
        int koltseg;

        int operatorIndex;

        int heurisztika;

        int osszkoltseg;

        public Csomopont(Allapot allapot, int operatorIndex)
        {
            this.allapot = allapot;
            this.OperatorIndex = operatorIndex;
        }

        public Csomopont(Allapot allapot, Csomopont szulo)
        {
            this.allapot = allapot;
            this.szulo = szulo;

            if(szulo == null)
            {
                koltseg = 0;
            }
            else
            {
                koltseg = szulo.koltseg + 1;
            }

            this.heurisztika = 0;
            foreach(string korong in allapot.Korongok)
            {
                if(korong == "P")
                {
                    this.heurisztika += 1;
                }
                else if (korong == "Q")
                {
                    this.heurisztika += 2;
                }
                else
                {
                    this.heurisztika += 3;
                }
            }

            //koltseg = 10

            //heur1 = 8
            //heur2 = 3

            //10 - 8 = 2
            //10 - 3 = 7

            this.osszkoltseg = this.koltseg + (-1) * this.heurisztika;
        }

        public override bool Equals(object obj)
        {
            Csomopont osszehasonlitandoCsomopont = (Csomopont) obj;
            return this.allapot.Equals(osszehasonlitandoCsomopont.Allapot);
        }
    }
}
