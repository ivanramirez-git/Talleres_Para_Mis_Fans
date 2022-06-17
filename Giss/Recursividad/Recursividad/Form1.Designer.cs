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
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPotencia = new System.Windows.Forms.TabPage();
            this.txtPotenciaExponente = new System.Windows.Forms.TextBox();
            this.txtPotenciaBase = new System.Windows.Forms.TextBox();
            this.btnPotencia = new System.Windows.Forms.Button();
            this.lblPotenciaRecursiva = new System.Windows.Forms.Label();
            this.lblPotenciaIterativa = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.tabFactorial = new System.Windows.Forms.TabPage();
            this.btnFactorial = new System.Windows.Forms.Button();
            this.lblFactorialRecursiva = new System.Windows.Forms.Label();
            this.lblFactorialIterativa = new System.Windows.Forms.Label();
            this.txtFactorialNumero = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.tabFibonacci = new System.Windows.Forms.TabPage();
            this.btnFibonacci = new System.Windows.Forms.Button();
            this.lblFibonacciRecursiva = new System.Windows.Forms.Label();
            this.lblFibonacciIterativa = new System.Windows.Forms.Label();
            this.txtFibonacciNumero = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.tabSerieFibonacci = new System.Windows.Forms.TabPage();
            this.btnSerie = new System.Windows.Forms.Button();
            this.lblSerieSerie = new System.Windows.Forms.Label();
            this.lblSerieNumero = new System.Windows.Forms.Label();
            this.txtSerieNumero = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.tabControl1.SuspendLayout();
            this.tabPotencia.SuspendLayout();
            this.tabFactorial.SuspendLayout();
            this.tabFibonacci.SuspendLayout();
            this.tabSerieFibonacci.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPotencia);
            this.tabControl1.Controls.Add(this.tabFactorial);
            this.tabControl1.Controls.Add(this.tabFibonacci);
            this.tabControl1.Controls.Add(this.tabSerieFibonacci);
            this.tabControl1.Location = new System.Drawing.Point(12, 12);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(434, 396);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPotencia
            // 
            this.tabPotencia.Controls.Add(this.txtPotenciaExponente);
            this.tabPotencia.Controls.Add(this.txtPotenciaBase);
            this.tabPotencia.Controls.Add(this.btnPotencia);
            this.tabPotencia.Controls.Add(this.lblPotenciaRecursiva);
            this.tabPotencia.Controls.Add(this.lblPotenciaIterativa);
            this.tabPotencia.Controls.Add(this.label2);
            this.tabPotencia.Controls.Add(this.label1);
            this.tabPotencia.Location = new System.Drawing.Point(4, 24);
            this.tabPotencia.Name = "tabPotencia";
            this.tabPotencia.Padding = new System.Windows.Forms.Padding(3);
            this.tabPotencia.Size = new System.Drawing.Size(426, 368);
            this.tabPotencia.TabIndex = 0;
            this.tabPotencia.Text = "Potencia";
            this.tabPotencia.UseVisualStyleBackColor = true;
            // 
            // txtPotenciaExponente
            // 
            this.txtPotenciaExponente.Location = new System.Drawing.Point(123, 85);
            this.txtPotenciaExponente.Name = "txtPotenciaExponente";
            this.txtPotenciaExponente.Size = new System.Drawing.Size(100, 23);
            this.txtPotenciaExponente.TabIndex = 6;
            // 
            // txtPotenciaBase
            // 
            this.txtPotenciaBase.Location = new System.Drawing.Point(123, 54);
            this.txtPotenciaBase.Name = "txtPotenciaBase";
            this.txtPotenciaBase.Size = new System.Drawing.Size(100, 23);
            this.txtPotenciaBase.TabIndex = 5;
            // 
            // btnPotencia
            // 
            this.btnPotencia.Location = new System.Drawing.Point(115, 153);
            this.btnPotencia.Name = "btnPotencia";
            this.btnPotencia.Size = new System.Drawing.Size(75, 23);
            this.btnPotencia.TabIndex = 4;
            this.btnPotencia.Text = "Potencia";
            this.btnPotencia.UseVisualStyleBackColor = true;
            this.btnPotencia.Click += new System.EventHandler(this.btnPotencia_Click);
            // 
            // lblPotenciaRecursiva
            // 
            this.lblPotenciaRecursiva.AutoSize = true;
            this.lblPotenciaRecursiva.Location = new System.Drawing.Point(79, 223);
            this.lblPotenciaRecursiva.Name = "lblPotenciaRecursiva";
            this.lblPotenciaRecursiva.Size = new System.Drawing.Size(38, 15);
            this.lblPotenciaRecursiva.TabIndex = 3;
            this.lblPotenciaRecursiva.Text = "label4";
            // 
            // lblPotenciaIterativa
            // 
            this.lblPotenciaIterativa.AutoSize = true;
            this.lblPotenciaIterativa.Location = new System.Drawing.Point(79, 208);
            this.lblPotenciaIterativa.Name = "lblPotenciaIterativa";
            this.lblPotenciaIterativa.Size = new System.Drawing.Size(38, 15);
            this.lblPotenciaIterativa.TabIndex = 2;
            this.lblPotenciaIterativa.Text = "label3";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(51, 88);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(66, 15);
            this.label2.TabIndex = 1;
            this.label2.Text = "Exponente:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(83, 57);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(34, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "Base:";
            // 
            // tabFactorial
            // 
            this.tabFactorial.Controls.Add(this.btnFactorial);
            this.tabFactorial.Controls.Add(this.lblFactorialRecursiva);
            this.tabFactorial.Controls.Add(this.lblFactorialIterativa);
            this.tabFactorial.Controls.Add(this.txtFactorialNumero);
            this.tabFactorial.Controls.Add(this.label3);
            this.tabFactorial.Location = new System.Drawing.Point(4, 24);
            this.tabFactorial.Name = "tabFactorial";
            this.tabFactorial.Padding = new System.Windows.Forms.Padding(3);
            this.tabFactorial.Size = new System.Drawing.Size(426, 368);
            this.tabFactorial.TabIndex = 1;
            this.tabFactorial.Text = "Factorial";
            this.tabFactorial.UseVisualStyleBackColor = true;
            // 
            // btnFactorial
            // 
            this.btnFactorial.Location = new System.Drawing.Point(132, 159);
            this.btnFactorial.Name = "btnFactorial";
            this.btnFactorial.Size = new System.Drawing.Size(75, 23);
            this.btnFactorial.TabIndex = 4;
            this.btnFactorial.Text = "Factorial";
            this.btnFactorial.UseVisualStyleBackColor = true;
            this.btnFactorial.Click += new System.EventHandler(this.btnFactorial_Click);
            // 
            // lblFactorialRecursiva
            // 
            this.lblFactorialRecursiva.AutoSize = true;
            this.lblFactorialRecursiva.Location = new System.Drawing.Point(88, 205);
            this.lblFactorialRecursiva.Name = "lblFactorialRecursiva";
            this.lblFactorialRecursiva.Size = new System.Drawing.Size(38, 15);
            this.lblFactorialRecursiva.TabIndex = 3;
            this.lblFactorialRecursiva.Text = "label5";
            // 
            // lblFactorialIterativa
            // 
            this.lblFactorialIterativa.AutoSize = true;
            this.lblFactorialIterativa.Location = new System.Drawing.Point(88, 190);
            this.lblFactorialIterativa.Name = "lblFactorialIterativa";
            this.lblFactorialIterativa.Size = new System.Drawing.Size(38, 15);
            this.lblFactorialIterativa.TabIndex = 2;
            this.lblFactorialIterativa.Text = "label4";
            // 
            // txtFactorialNumero
            // 
            this.txtFactorialNumero.Location = new System.Drawing.Point(132, 84);
            this.txtFactorialNumero.Name = "txtFactorialNumero";
            this.txtFactorialNumero.Size = new System.Drawing.Size(100, 23);
            this.txtFactorialNumero.TabIndex = 1;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(72, 87);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(54, 15);
            this.label3.TabIndex = 0;
            this.label3.Text = "Número:";
            // 
            // tabFibonacci
            // 
            this.tabFibonacci.Controls.Add(this.btnFibonacci);
            this.tabFibonacci.Controls.Add(this.lblFibonacciRecursiva);
            this.tabFibonacci.Controls.Add(this.lblFibonacciIterativa);
            this.tabFibonacci.Controls.Add(this.txtFibonacciNumero);
            this.tabFibonacci.Controls.Add(this.label6);
            this.tabFibonacci.Location = new System.Drawing.Point(4, 24);
            this.tabFibonacci.Name = "tabFibonacci";
            this.tabFibonacci.Size = new System.Drawing.Size(426, 368);
            this.tabFibonacci.TabIndex = 2;
            this.tabFibonacci.Text = "Fibonacci";
            this.tabFibonacci.UseVisualStyleBackColor = true;
            // 
            // btnFibonacci
            // 
            this.btnFibonacci.Location = new System.Drawing.Point(151, 162);
            this.btnFibonacci.Name = "btnFibonacci";
            this.btnFibonacci.Size = new System.Drawing.Size(75, 23);
            this.btnFibonacci.TabIndex = 9;
            this.btnFibonacci.Text = "Fibonacci";
            this.btnFibonacci.UseVisualStyleBackColor = true;
            this.btnFibonacci.Click += new System.EventHandler(this.btnFibonacci_Click);
            // 
            // lblFibonacciRecursiva
            // 
            this.lblFibonacciRecursiva.AutoSize = true;
            this.lblFibonacciRecursiva.Location = new System.Drawing.Point(107, 208);
            this.lblFibonacciRecursiva.Name = "lblFibonacciRecursiva";
            this.lblFibonacciRecursiva.Size = new System.Drawing.Size(38, 15);
            this.lblFibonacciRecursiva.TabIndex = 8;
            this.lblFibonacciRecursiva.Text = "label5";
            // 
            // lblFibonacciIterativa
            // 
            this.lblFibonacciIterativa.AutoSize = true;
            this.lblFibonacciIterativa.Location = new System.Drawing.Point(107, 193);
            this.lblFibonacciIterativa.Name = "lblFibonacciIterativa";
            this.lblFibonacciIterativa.Size = new System.Drawing.Size(38, 15);
            this.lblFibonacciIterativa.TabIndex = 7;
            this.lblFibonacciIterativa.Text = "label4";
            // 
            // txtFibonacciNumero
            // 
            this.txtFibonacciNumero.Location = new System.Drawing.Point(151, 87);
            this.txtFibonacciNumero.Name = "txtFibonacciNumero";
            this.txtFibonacciNumero.Size = new System.Drawing.Size(100, 23);
            this.txtFibonacciNumero.TabIndex = 6;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(91, 90);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(54, 15);
            this.label6.TabIndex = 5;
            this.label6.Text = "Número:";
            // 
            // tabSerieFibonacci
            // 
            this.tabSerieFibonacci.Controls.Add(this.btnSerie);
            this.tabSerieFibonacci.Controls.Add(this.lblSerieSerie);
            this.tabSerieFibonacci.Controls.Add(this.lblSerieNumero);
            this.tabSerieFibonacci.Controls.Add(this.txtSerieNumero);
            this.tabSerieFibonacci.Controls.Add(this.label9);
            this.tabSerieFibonacci.Location = new System.Drawing.Point(4, 24);
            this.tabSerieFibonacci.Name = "tabSerieFibonacci";
            this.tabSerieFibonacci.Size = new System.Drawing.Size(426, 368);
            this.tabSerieFibonacci.TabIndex = 3;
            this.tabSerieFibonacci.Text = "Serie Fibonacci";
            this.tabSerieFibonacci.UseVisualStyleBackColor = true;
            // 
            // btnSerie
            // 
            this.btnSerie.Location = new System.Drawing.Point(156, 170);
            this.btnSerie.Name = "btnSerie";
            this.btnSerie.Size = new System.Drawing.Size(120, 23);
            this.btnSerie.TabIndex = 9;
            this.btnSerie.Text = "Serie de Fibonacci";
            this.btnSerie.UseVisualStyleBackColor = true;
            this.btnSerie.Click += new System.EventHandler(this.btnSerie_Click);
            // 
            // lblSerieSerie
            // 
            this.lblSerieSerie.AutoSize = true;
            this.lblSerieSerie.Location = new System.Drawing.Point(112, 229);
            this.lblSerieSerie.Name = "lblSerieSerie";
            this.lblSerieSerie.Size = new System.Drawing.Size(38, 15);
            this.lblSerieSerie.TabIndex = 8;
            this.lblSerieSerie.Text = "label5";
            // 
            // lblSerieNumero
            // 
            this.lblSerieNumero.AutoSize = true;
            this.lblSerieNumero.Location = new System.Drawing.Point(112, 214);
            this.lblSerieNumero.Name = "lblSerieNumero";
            this.lblSerieNumero.Size = new System.Drawing.Size(38, 15);
            this.lblSerieNumero.TabIndex = 7;
            this.lblSerieNumero.Text = "label4";
            // 
            // txtSerieNumero
            // 
            this.txtSerieNumero.Location = new System.Drawing.Point(156, 100);
            this.txtSerieNumero.Name = "txtSerieNumero";
            this.txtSerieNumero.Size = new System.Drawing.Size(100, 23);
            this.txtSerieNumero.TabIndex = 6;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(25, 103);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(125, 15);
            this.label9.TabIndex = 5;
            this.label9.Text = "Cantidad de Términos:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(458, 420);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.Text = "Recursividad (TabControl)";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tabControl1.ResumeLayout(false);
            this.tabPotencia.ResumeLayout(false);
            this.tabPotencia.PerformLayout();
            this.tabFactorial.ResumeLayout(false);
            this.tabFactorial.PerformLayout();
            this.tabFibonacci.ResumeLayout(false);
            this.tabFibonacci.PerformLayout();
            this.tabSerieFibonacci.ResumeLayout(false);
            this.tabSerieFibonacci.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private TabControl tabControl1;
        private TabPage tabPotencia;
        private TabPage tabFactorial;
        private Label lblPotenciaRecursiva;
        private Label lblPotenciaIterativa;
        private Label label2;
        private Label label1;
        private TabPage tabFibonacci;
        private TabPage tabSerieFibonacci;
        private Button btnPotencia;
        private TextBox txtPotenciaExponente;
        private TextBox txtPotenciaBase;
        private Label label3;
        private Button btnFactorial;
        private Label lblFactorialRecursiva;
        private Label lblFactorialIterativa;
        private TextBox txtFactorialNumero;
        private Button btnFibonacci;
        private Label lblFibonacciRecursiva;
        private Label lblFibonacciIterativa;
        private TextBox txtFibonacciNumero;
        private Label label6;
        private Button btnSerie;
        private Label lblSerieSerie;
        private Label lblSerieNumero;
        private TextBox txtSerieNumero;
        private Label label9;
    }
}