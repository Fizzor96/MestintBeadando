using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WindowsFormsApp14.AllapotTer;
using WindowsFormsApp14.Keresok;

namespace WindowsFormsApp14
{
    public partial class Form1 : Form
    {
        List<Kereso> keresok = new List<Kereso>();

        List<Allapot> megoldas = new List<Allapot>();

        int aktualisAllapot = 0;

        public Form1()
        {
            InitializeComponent();

            keresok.Add(new ProbaHibaRandom());
            keresok.Add(new Melysegi());
            keresok.Add(new Szelessegi());
            keresok.Add(new Optimalis());
            keresok.Add(new Backtrack());
            keresok.Add(new AgEsKorlat());
            keresok.Add(new BestFirst());
            keresok.Add(new Aalgoritmus());

            megoldas = keresok[0].Utvonal;

            foreach (Kereso kereso in keresok)
            {
                comboBox1.Items.Add(kereso.GetType().Name);
            }

            comboBox1.SelectedIndex = 0;
            //Console.WriteLine(probahiba);
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(aktualisAllapot > 0) aktualisAllapot--;
            Kirajzol();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(aktualisAllapot < megoldas.Count - 1) aktualisAllapot++;
            Kirajzol();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            megoldas = keresok[comboBox1.SelectedIndex].Utvonal;
            aktualisAllapot = 0;
            Kirajzol();
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            Kirajzol();
        }

        Graphics graphics;

        private void Kirajzol()
        {
            Bitmap image = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            pictureBox1.Image = image;
            graphics = Graphics.FromImage(image);

            for (int i = 0; i < Allapot.OSZLOPOK.Length; i++)
            {
                graphics.FillRectangle(new SolidBrush(Color.Red), new Rectangle(i * 150 + 60, 60, 20, 150));
            }

            string[] korongok = megoldas[aktualisAllapot].Korongok;

            for (int i = 0; i < korongok.Length; i++)
            {
                int oszlopIndex = 0;
                if(korongok[i] == "Q")
                {
                    oszlopIndex = 1;
                }
                else if (korongok[i] == "R")
                {
                    oszlopIndex = 2;
                }

                int eltolas = 0;
                for (int j = i + 1; j < korongok.Length; j++)
                {
                    if (korongok[j] == korongok[i]) eltolas++;
                }


                graphics.FillRectangle(new SolidBrush(Color.Green), new Rectangle(40 + oszlopIndex * 150 - i * 15, 180 - eltolas * 30, i * 30 + 60, 30));

                label1.Text = "Lépések száma (Kezdőállapottal együtt): " + megoldas.Count;
            }
        }
    }
}
