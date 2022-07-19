namespace Recursividad
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void tabPotencia_Click(object sender, EventArgs e)
        {

        }
        // serie 1: n primeros primos
        private int[] serie1Fun(int n)
        {
            int[] primos = new int[n];
            int i = 0;
            int j = 2;
            while (i < n)
            {
                if (esPrimo(j))
                {
                    primos[i] = j;
                    i++;
                }
                j++;
            }
            return primos;
        }

        // es primo
        bool esPrimo(int n)
        {
            if (n == 1)
                return false;
            if (n == 2)
                return true;
            for (int i = 2; i < n; i++)
            {
                if (n % i == 0)
                    return false;
            }
            return true;
        }
        // funcion que recibe un int [] y retorna un string, parentesis
        private string imprimirSerieParentesis(int[] serie)
        {
            string resultado = "";
            for (int i = 0; i < serie.Length; i++)
            {
                resultado += "(" + serie[i] + ") ";
            }
            return resultado;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Validar txt terminos
            if (terminos.Text == "")
            {
                MessageBox.Show("La cantidad de terminos no puede estar vacia");
                terminos.Focus();
                return;
            }
            int ctdTerminos;
            try
            {
                ctdTerminos = Convert.ToInt32(terminos.Text);
                if (ctdTerminos <= 0)
                {
                    MessageBox.Show("Debe ingresar un numero mayor a 0");
                    terminos.Focus();
                    return;
                }
            }
            catch (Exception)
            {
                MessageBox.Show("Debe ingresar un numero");
                terminos.Focus();
                return;
            }
            // series
            int[] serie1Arr = serie1Fun(ctdTerminos);
            // cambiar los arreglos en los textbox
            arreglo1.Text = imprimirSerieParentesis(serie1Arr);
        }

        private void serie1_Click(object sender, EventArgs e)
        {

        }
    }
}