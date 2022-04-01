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
    public partial class FormDistancia : Form
    {
        public FormDistancia()
        {
            InitializeComponent();
        }

        private void lblMEM_Click(object sender, EventArgs e)
        {

        }

        private void btnclear_Click(object sender, EventArgs e)
        {
            this.Size = new Size(400, this.Size.Height);
            txta1.Text = "";
            txta2.Text = "";
            txtb1.Text = "";
            txtb2.Text = "";
            txtRespuesta.Text = "";
        }

        private void btnrespuesta_Click(object sender, EventArgs e)
        {
            double a1 = 0;
            double a2 = 0;
            double b1 = 0;
            double b2 = 0;
            double respuesta = 0;

            if(txta1.Text != "")
                a1 = double.Parse(txta1.Text);

            if(txta2.Text !="")
                a2 = double.Parse(txta2.Text);

            if(txtb1.Text !="")
                b1 = double.Parse(txtb1.Text);

            if(txtb2.Text !="")
                b2 = double.Parse(txtb2.Text);

            respuesta = Math.Sqrt(((b1-a1)*(b1-a1))+((b2-a2)*(b2-a2)));

            txtRespuesta.Text = respuesta + "";

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            int xcentro = pictureBox1.Width / 2;
            int ycentro = pictureBox1.Height / 2;

            Pen lapiz = new Pen(Color.White,2);
            e.Graphics.TranslateTransform(xcentro, ycentro);
            e.Graphics.ScaleTransform(1, -1);

            // Ejes
            // Horizontal
            e.Graphics.DrawLine(lapiz, xcentro * -1, 0, xcentro * 2, 0);
            // Vertical
            e.Graphics.DrawLine(lapiz, 0, ycentro, 0, ycentro * -1);

            // Distancias
            for(int i = -xcentro; i < xcentro; i+=8)
            {
                // -y
                e.Graphics.DrawLine(lapiz, 5, i, -5, i);
                // x
                e.Graphics.DrawLine(lapiz, i, 5, i, -5);
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            
            float xcentro = pictureBox1.Width / 2;
            float ycentro = pictureBox1.Height / 2;

            float a1 = 0, a2 = 0, b1 = 0, b2 = 0;
            if(txta1.Text!="" && txta2.Text!="" && txtb1.Text!="" && txtb2.Text != "")
            {
                this.Size = new Size(733,this.Size.Height);
                a1 = float.Parse(txta1.Text) + xcentro;
                a2 = -float.Parse(txta2.Text) + ycentro;
                b1 = float.Parse(txtb1.Text) + xcentro;
                b2 = -float.Parse(txtb2.Text) + ycentro;
                Pen lapiz = new Pen(Color.Yellow, 2);
                Graphics vector = pictureBox1.CreateGraphics();

                vector.DrawLine(lapiz, a1, a2, b1, b2);

                lapiz.Dispose();
                vector.Dispose();
            }
            else
            {
                Console.Beep();
            }
            
        }

        private void FormDistancia_Load(object sender, EventArgs e)
        {
            this.Size = new Size(400, this.Size.Height);
        }
    }
}
