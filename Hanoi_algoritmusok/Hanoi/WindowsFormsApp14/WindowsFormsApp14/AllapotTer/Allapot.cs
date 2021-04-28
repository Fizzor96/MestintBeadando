using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp14.AllapotTer
{
    class Allapot
    {
        public static int KORONGSZAM = 3;
        
        private string[] korongok = new string[KORONGSZAM];

        public static string[] OSZLOPOK = new string[] { "P", "Q", "R" };

        public string[] Korongok { get => korongok; set => korongok = value; }
    
        public Allapot()
        {
            for (int i = 0; i < KORONGSZAM; i++)
            {
                korongok[i] = "P";
            }
        }

        public bool celfeltetel()
        {
            for (int i = 0; i < KORONGSZAM; i++)
            {
                if(korongok[i] != "R")
                {
                    return false;
                }
            }
            return true;
        }

        public override string ToString()
        {
            StringBuilder builder = new StringBuilder();
            builder.Append("(");

            for (int i = 0; i < KORONGSZAM; i++)
            {
                builder.Append(korongok[i]);
                builder.Append(",");
            }

            builder.Append(")");
            return builder.ToString();
        }

        public override bool Equals(object obj)
        {
            Allapot vizsgaltAllapot = (Allapot) obj;
            for (int i = 0; i < korongok.Length; i++)
            {
                if(this.korongok[i] != vizsgaltAllapot.korongok[i])
                {
                    return false;
                }
            }

            return true;
        }
    }
}
