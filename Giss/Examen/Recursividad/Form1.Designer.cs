namespace Recursividad
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.serie3 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.serie2 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.serie1 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.terminos = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.arreglo3 = new System.Windows.Forms.TextBox();
            this.arreglo2 = new System.Windows.Forms.TextBox();
            this.arreglo1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.arreglosumaordenado = new System.Windows.Forms.TextBox();
            this.arreglosuma = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.serie3);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.serie2);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Controls.Add(this.serie1);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(434, 97);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Series para poblar los arreglos";
            // 
            // serie3
            // 
            this.serie3.AutoSize = true;
            this.serie3.Location = new System.Drawing.Point(56, 68);
            this.serie3.Name = "serie3";
            this.serie3.Size = new System.Drawing.Size(114, 15);
            this.serie3.TabIndex = 1;
            this.serie3.Text = "-1, 2, -3, 4,- 5, 6, -7...";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 68);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(44, 15);
            this.label3.TabIndex = 2;
            this.label3.Text = "Serie 3:";
            // 
            // serie2
            // 
            this.serie2.AutoSize = true;
            this.serie2.Location = new System.Drawing.Point(56, 43);
            this.serie2.Name = "serie2";
            this.serie2.Size = new System.Drawing.Size(118, 15);
            this.serie2.TabIndex = 3;
            this.serie2.Text = "2, 5, 7, 12, 19, 31, 50...";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 43);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(44, 15);
            this.label2.TabIndex = 4;
            this.label2.Text = "Serie 2:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(6, 19);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(44, 15);
            this.label7.TabIndex = 5;
            this.label7.Text = "Serie 1:";
            // 
            // serie1
            // 
            this.serie1.AutoSize = true;
            this.serie1.Location = new System.Drawing.Point(56, 19);
            this.serie1.Name = "serie1";
            this.serie1.Size = new System.Drawing.Size(104, 15);
            this.serie1.TabIndex = 5;
            this.serie1.Text = "-3, -1, 1, 3, 5, 7, 9...";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 137);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(82, 15);
            this.label1.TabIndex = 6;
            this.label1.Text = "Arreglo Suma:";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.terminos);
            this.groupBox2.Location = new System.Drawing.Point(12, 115);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(434, 58);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Ingrese ctd. de términos:";
            // 
            // terminos
            // 
            this.terminos.Location = new System.Drawing.Point(6, 22);
            this.terminos.Name = "terminos";
            this.terminos.Size = new System.Drawing.Size(115, 23);
            this.terminos.TabIndex = 0;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.arreglosuma);
            this.groupBox3.Controls.Add(this.arreglo3);
            this.groupBox3.Controls.Add(this.arreglo2);
            this.groupBox3.Controls.Add(this.arreglo1);
            this.groupBox3.Controls.Add(this.button1);
            this.groupBox3.Controls.Add(this.label6);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Controls.Add(this.label4);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Location = new System.Drawing.Point(12, 179);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(434, 171);
            this.groupBox3.TabIndex = 3;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Arreglos:";
            // 
            // arreglo3
            // 
            this.arreglo3.Enabled = false;
            this.arreglo3.Location = new System.Drawing.Point(94, 108);
            this.arreglo3.Name = "arreglo3";
            this.arreglo3.Size = new System.Drawing.Size(334, 23);
            this.arreglo3.TabIndex = 0;
            // 
            // arreglo2
            // 
            this.arreglo2.Enabled = false;
            this.arreglo2.Location = new System.Drawing.Point(94, 82);
            this.arreglo2.Name = "arreglo2";
            this.arreglo2.Size = new System.Drawing.Size(334, 23);
            this.arreglo2.TabIndex = 0;
            // 
            // arreglo1
            // 
            this.arreglo1.Enabled = false;
            this.arreglo1.Location = new System.Drawing.Point(94, 56);
            this.arreglo1.Name = "arreglo1";
            this.arreglo1.Size = new System.Drawing.Size(334, 23);
            this.arreglo1.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(56, 22);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(104, 23);
            this.button1.TabIndex = 7;
            this.button1.Text = "Poblar Arreglos";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(30, 59);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(58, 15);
            this.label6.TabIndex = 6;
            this.label6.Text = "Arreglo 1:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(30, 85);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(58, 15);
            this.label5.TabIndex = 6;
            this.label5.Text = "Arreglo 2:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(30, 111);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(58, 15);
            this.label4.TabIndex = 6;
            this.label4.Text = "Arreglo 3:";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.arreglosumaordenado);
            this.groupBox4.Location = new System.Drawing.Point(18, 356);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(428, 58);
            this.groupBox4.TabIndex = 2;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Arreglo Suma ordenado por Quick Sort";
            // 
            // arreglosumaordenado
            // 
            this.arreglosumaordenado.Enabled = false;
            this.arreglosumaordenado.Location = new System.Drawing.Point(6, 22);
            this.arreglosumaordenado.Name = "arreglosumaordenado";
            this.arreglosumaordenado.Size = new System.Drawing.Size(416, 23);
            this.arreglosumaordenado.TabIndex = 0;
            // 
            // arreglosuma
            // 
            this.arreglosuma.Enabled = false;
            this.arreglosuma.Location = new System.Drawing.Point(94, 137);
            this.arreglosuma.Name = "arreglosuma";
            this.arreglosuma.Size = new System.Drawing.Size(334, 23);
            this.arreglosuma.TabIndex = 8;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(458, 425);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Recursividad (TabControl)";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private GroupBox groupBox1;
        private Label serie3;
        private Label label3;
        private Label serie2;
        private Label label2;
        private Label serie1;
        private Label label1;
        private GroupBox groupBox2;
        private TextBox terminos;
        private GroupBox groupBox3;
        private TextBox arreglo3;
        private TextBox arreglo2;
        private TextBox arreglo1;
        private Button button1;
        private Label label6;
        private Label label5;
        private Label label4;
        private GroupBox groupBox4;
        private TextBox arreglosumaordenado;
        private Label label7;
        private TextBox arreglosuma;
    }
}