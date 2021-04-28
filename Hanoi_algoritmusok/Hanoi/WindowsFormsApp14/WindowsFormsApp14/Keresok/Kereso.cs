using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WindowsFormsApp14.AllapotTer;

namespace WindowsFormsApp14.Keresok
{
    abstract class Kereso
    {
        List<Allapot> utvonal = new List<Allapot>(); // adatbázis

        internal List<Allapot> Utvonal { get => utvonal; set => utvonal = value; }
        internal List<Operator> Operatorok { get => operatorok; set => operatorok = value; }

        List<Operator> operatorok = new List<Operator>();

        public Kereso()
        {
            operatorokGeneralasa();
        }

        private void operatorokGeneralasa()
        {
            for (int i = 0; i < Allapot.KORONGSZAM; i++)
            {
                for (int j = 0; j < Allapot.OSZLOPOK.Length; j++)
                {
                    Operator ujOperator = new Operator(i, Allapot.OSZLOPOK[j]);
                    operatorok.Add(ujOperator);
                }
            }
        }

        public abstract void Kereses();

        public override string ToString()
        {
            StringBuilder builder = new StringBuilder();
            foreach(Allapot allapot in Utvonal)
            {
                builder.Append(allapot).Append("\n");
            }
            builder.Append("Kereső lépés: ").Append(Utvonal.Count);
            return builder.ToString();
        }
    }
}
