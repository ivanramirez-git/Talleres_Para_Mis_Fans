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
    public partial class FormFormulaCuadratica : Form
    {
        public FormFormulaCuadratica()
        {
            InitializeComponent();
        }

        private void FormFormulaCuadratica_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnclear_Click(object sender, EventArgs e)
        {
            txta.Text = "";
            txtb.Text = "";
            txtc.Text = "";
            txtX1.Text = "";
            txtX2.Text = "";
        }

        private void btnrespuesta_Click(object sender, EventArgs e)
        {
            double a = 0;
            double b = 0;
            double c = 0;
            double X1 = 0;
            double X2 = 0;

            if (txta.Text != "")
                a = double.Parse(txta.Text);

            if (txtb.Text !="")
                b = double.Parse(txtb.Text);

            if (txtc.Text !="")
                c = double.Parse(txtc.Text);

            // Calculo de formula cuadratica
            X1 = ((-1*b)+(Math.Sqrt((b*b)-(4*a*c))))/(2*a);
            X2 = ((-1*b)-(Math.Sqrt((b*b)-(4*a*c))))/(2*a);

            txtX1.Text = X1 + "";
            txtX2.Text = X2 + "";


        }
    }
}
