using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Proyecto_Apps_Calculadoras
{
    public partial class FormCientifica : Form
    {
        public double DATO1;
        public double DATO2;
        public double OPE;
        public double RES;
        public FormCientifica()
        {
            InitializeComponent();
        }

        private void btnuno_Click(object sender, EventArgs e)
        {
            txtpantalla.Text = txtpantalla.Text + "1";
        }

        private void btnodos_Click(object sender, EventArgs e)
        {
            txtpantalla.Text = txtpantalla.Text + "2";
        }

        private void btntres_Click(object sender, EventArgs e)
        {
            txtpantalla.Text = txtpantalla.Text + "3";
        }

        private void btncuatro_Click(object sender, EventArgs e)
        {
            txtpantalla.Text = txtpantalla.Text + "4";
        }

        private void btncinco_Click(object sender, EventArgs e)
        {
            txtpantalla.Text = txtpantalla.Text + "5";
        }

        private void btnseis_Click(object sender, EventArgs e)
        {
            txtpantalla.Text = txtpantalla.Text + "6";
        }

        private void btnsiete_Click(object sender, EventArgs e)
        {
            txtpantalla.Text = txtpantalla.Text + "7";
        }

        private void btnocho_Click(object sender, EventArgs e)
        {
            txtpantalla.Text = txtpantalla.Text + "8";
        }

        private void btnnueve_Click(object sender, EventArgs e)
        {
            txtpantalla.Text = txtpantalla.Text + "9";
        }

        private void btncero_Click(object sender, EventArgs e)
        {
            txtpantalla.Text = txtpantalla.Text + "0";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnpunto_Click(object sender, EventArgs e)
        {
            try
            {
                if (txtpantalla.Text.IndexOf(".") > 0)
                {
                    // Alerta que ya tiene un punto
                    Console.Beep();
                }
                else if (txtpantalla.Text!=".")
                {
                    txtpantalla.Text = txtpantalla.Text + ".";
                }
                else
                {
                    txtpantalla.Text = "0.";
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btnsuma_Click(object sender, EventArgs e)
        {
            OPE = 1;
            DATO1 = double.Parse(txtpantalla.Text);
            txtpantalla.Clear();

            txtref.Text = DATO1 + "+";
        }

        private void btnresta_Click(object sender, EventArgs e)
        {
            OPE = 2;
            DATO1 = double.Parse(txtpantalla.Text);
            txtpantalla.Clear();

            txtref.Text = DATO1 + " - ";
        }

        private void btnmultiplicacion_Click(object sender, EventArgs e)
        {
            OPE = 3;
            DATO1 = double.Parse(txtpantalla.Text);
            txtpantalla.Clear();

            txtref.Text = DATO1 + " Æ ";
        }

        private void btndivision_Click(object sender, EventArgs e)
        {
            OPE = 4;
            DATO1 = double.Parse(txtpantalla.Text);
            txtpantalla.Clear();

            txtref.Text = DATO1 + " Ä ";
        }
    }
}
