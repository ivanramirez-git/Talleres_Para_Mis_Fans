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
        // Potencia de un numero de forma iterativa
        private float potenciaIterativa(float baseNum, int exponente)
        {
            float resultado = 1;
            for (int i = 0; i < exponente; i++)
            {
                resultado *= baseNum;
            }
            return resultado;
        }

        // Potencia de un numero de forma recursiva
        private float potenciaRecursiva(float baseNum, int exponente)
        {
            if (exponente == 0)
            {
                return 1;
            }
            else
            {
                return baseNum * potenciaRecursiva(baseNum, exponente - 1);
            }
        }

        // serie 1: -3, -1, 1, 3, 5, 7, 9...

        private int[] serie1Fun(int n)
        {
            int inicio = -3;
            int[] serie = new int[n];
            for (int i = 0; i < n; i++)
            {
                serie[i] = inicio;
                inicio += 2;
            }
            return serie;
        }

        // serie 2: 2, 5, 7, 12, 19, 31, 50...

        private int[] serie2Fun(int n)
        {

            int[] serie = new int[n];
            serie[0] = 2;
            if (n > 1)
            {
                serie[1] = 5;
            }
            else
            {
                return serie;
            }
            for (int i = 2; i < n; i++)
            {
                serie[i] = serie[i - 1] + serie[i - 2];
            }
            return serie;
        }

        // seire 3: -1, 2, -3, 4,- 5, 6, -7...
        private int[] serie3Fun(int n)
        {
            int inicio = -1;
            int[] serie = new int[n];
            for (int i = 0; i < n; i++)
            {
                serie[i] = inicio * (i + 1);
                inicio = -inicio;
            }
            return serie;
        }

        // funcion que recibe un int [] y retorna un string, coma
        private string imprimirSerieComa(int[] serie)
        {
            string resultado = "";
            for (int i = 0; i < serie.Length; i++)
            {
                if (i < serie.Length - 1)
                {
                    resultado += serie[i] + ", ";
                }
                else
                {
                    resultado += serie[i];
                }
            }
            return resultado;
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

        // ordenamiento quick sort
        private int[] quickSort(int[] serie)
        {
            int[] resultado = serie;
            quickSort(resultado, 0, resultado.Length - 1);
            return resultado;
        }
        private void quickSort(int[] serie, int inicio, int fin)
        {
            if (inicio < fin)
            {
                int pivote = particion(serie, inicio, fin);
                quickSort(serie, inicio, pivote - 1);
                quickSort(serie, pivote + 1, fin);
            }
        }
        private int particion(int[] serie, int inicio, int fin)
        {
            int pivote = serie[inicio];
            int i = inicio + 1;
            int j = fin;
            while (i <= j)
            {
                while (i <= j && serie[i] <= pivote)
                {
                    i++;
                }
                while (i <= j && serie[j] >= pivote)
                {
                    j--;
                }
                if (i < j)
                {
                    int aux = serie[i];
                    serie[i] = serie[j];
                    serie[j] = aux;
                }
            }
            int aux2 = serie[inicio];
            serie[inicio] = serie[j];
            serie[j] = aux2;
            return j;
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
            int[] serie2Arr = serie2Fun(ctdTerminos);
            int[] serie3Arr = serie3Fun(ctdTerminos);
            // sumar
            int[] serieSuma = new int[ctdTerminos];
            for (int i = 0; i < ctdTerminos; i++)
            {
                serieSuma[i] = serie1Arr[i] + serie2Arr[i] + serie3Arr[i];
            }
            // ordenar
            int[] serieOrdenada = quickSort(serieSuma);
            // cambiar los arreglos en los textbox
            arreglo1.Text = imprimirSerieParentesis(serie1Arr);
            arreglo2.Text = imprimirSerieParentesis(serie2Arr);
            arreglo3.Text = imprimirSerieParentesis(serie3Arr);
            arreglosuma.Text = imprimirSerieParentesis(serieSuma);
            arreglosumaordenado.Text = imprimirSerieParentesis(serieOrdenada);
        }
    }
}