using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{

    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();

        }        
        private void button1_Click(object sender, EventArgs e)
        {
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void toolStripStatusLabel1_Click(object sender, EventArgs e)
        {

        }

        private void toolStripStatusLabel2_Click(object sender, EventArgs e)
        {

        }

        private void paisaButton_Click(object sender, EventArgs e)
        {
            tabControl1.SelectedIndex = 1;

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            tabControl1.SelectedIndex = 2;
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            // "Pedido Realizado con Exito a nombre de " 
            if (textBox1.Text!="")
            {
                MessageBox.Show("Pedido Realizado con Exito a nombre de " + textBox1.Text);
                listBox1.Items.Add(textBox1.Text);
            }
            else
            {
                MessageBox.Show("Error al realizar el pedido");
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            // "Pedido Realizado con Exito a nombre de " 
            if (textBox2.Text != "")
            {
                MessageBox.Show("Pedido Realizado con Exito a nombre de " + textBox2.Text);
                listBox1.Items.Add(textBox2.Text);
            }
            else
            {
                MessageBox.Show("Error al realizar el pedido");
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            monthCalendar1.Visible = false;
            tabControl1.SelectedIndex = 3;
        }

        private void monthCalendar1_DateChanged(object sender, DateRangeEventArgs e)
        {
            label12.Text = monthCalendar1.SelectionRange.Start.ToShortDateString();
        }

        private void Eventos_Click(object sender, EventArgs e)
        {
            monthCalendar1.Visible = false;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            monthCalendar1.Visible = !monthCalendar1.Visible;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            String temp="";
            if (checkBox6.Checked)
            {
                temp = "Paisa: " + numericUpDown1.Value;
            }
            if (checkBox7.Checked)
            {
                temp = temp + ", Cubano: " + numericUpDown2.Value;
            }
            if (!temp.Equals(""))
            {
                temp = "Fecha: " + label12.Text + ", " + temp;
            }
            if (!temp.Equals(""))
            {
                MessageBox.Show("Programacion Realizada con Exito");
                listBox2.Items.Add(temp);
            }
        }
    }
}
