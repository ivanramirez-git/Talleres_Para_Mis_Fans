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

        private void btnPotencia_Click(object sender, EventArgs e)
        {
            float baseNum;
            int exponente;

            // Convertir los valores a float dentro de un try catch
            try
            {
                baseNum = float.Parse(txtPotenciaBase.Text);
                exponente = int.Parse(txtPotenciaExponente.Text);
            }
            catch (Exception)
            {
                MessageBox.Show("Error en los datos ingresados");
                return;
            }

            // Validar que los campos no esten vacios
            if (txtPotenciaBase.Text == "" || txtPotenciaExponente.Text == "")
            {
                MessageBox.Show("Debe ingresar ambos valores");
            }
            // En el caso de la potencia la base y el exponente no pueden ser CERO al mismo tiempo
            else if (baseNum == 0 && exponente == 0)
            {
                MessageBox.Show("La base y el exponente no pueden ser cero al mismo tiempo");
            }
            else
            {
                // Calcular la potencia
                float resultadoIterativo = potenciaIterativa(baseNum, exponente);
                float resultadoRecursivo = potenciaRecursiva(baseNum, exponente);

                // Mostrar el resultado
                lblPotenciaIterativa.Text = "Forma Iterativa: " + exponente + " elevado a " + baseNum + " = " + resultadoIterativo;
                lblPotenciaRecursiva.Text = "Forma Recursiva: " + exponente + " elevado a " + baseNum + " = " + resultadoRecursivo;
            }

        }

        // Factorial de un numero de forma iterativa
        private int factorialIterativo(int numero)
        {
            int resultado = 1;
            for (int i = 1; i <= numero; i++)
            {
                resultado *= i;
            }
            return resultado;
        }

        // Factorial de un numero de forma recursiva
        private int factorialRecursivo(int numero)
        {
            if (numero == 0)
            {
                return 1;
            }
            else
            {
                return numero * factorialRecursivo(numero - 1);
            }
        }

        private void btnFactorial_Click(object sender, EventArgs e)
        { 
            
            int numero;

            // Capturar el valor del numero dentro de un try catch
            try
            {
                numero = int.Parse(txtFactorialNumero.Text);
            }
            catch
            {
                MessageBox.Show("Debe ingresar un valor");
                return;
            }

            // Validar que los campos no esten vacios
            if (txtFactorialNumero.Text == "")
            {
                MessageBox.Show("Debe ingresar un valor");
            }
            // Factorial debe ser mayor o igual a 0
            else if(numero < 0){
                MessageBox.Show("El numero debe ser mayor o igual a 0");
            }
            else
            {
                // Calcular el factorial
                int resultadoIterativo = factorialIterativo(numero);
                int resultadoRecursivo = factorialRecursivo(numero);

                // Mostrar el resultado
                lblFactorialIterativa.Text = "Forma Iterativa: " + numero + "! = " + resultadoIterativo;
                lblFactorialRecursiva.Text = "Forma Recursiva: " + numero + "! = " + resultadoRecursivo;
            }

        }

        // Fibonacci de un numero de forma iterativa
        private int fibonacciIterativo(int numero)
        {
            int resultado = 0;
            int anterior = 0;
            int actual = 1;
            for (int i = 0; i < numero-1; i++)
            {
                resultado = anterior + actual;
                anterior = actual;
                actual = resultado;
            }
            return resultado;
        }

        // Fibonacci de un numero de forma recursiva
        private int fibonacciRecursivo(int numero)
        {
            if (numero == 0)
            {
                return 0;
            }
            else if (numero == 1)
            {
                return 1;
            }
            else
            {
                return fibonacciRecursivo(numero - 1) + fibonacciRecursivo(numero - 2);
            }
        }

        private void btnFibonacci_Click(object sender, EventArgs e)
        {
            int numero;

            // Capturar el valor del numero dentro de un try catch
            try
            {
                numero = int.Parse(txtFibonacciNumero.Text);
            }
            catch
            {
                MessageBox.Show("Debe ingresar un valor");
                return;
            }

            // Validar que los campos no esten vacios
            if (txtFibonacciNumero.Text == "")
            {
                MessageBox.Show("Debe ingresar un valor");
            }
            // Fibonacci debe ser mayor o igual a 0
            else if(numero < 0){
                MessageBox.Show("El numero debe ser mayor o igual a 0");
            }
            else
            {
                // Calcular el factorial
                int resultadoIterativo = fibonacciIterativo(numero);
                int resultadoRecursivo = fibonacciRecursivo(numero);

                // Mostrar el resultado
                lblFibonacciIterativa.Text = "Forma Iterativa: Fibonacci(" + numero + ") = " + resultadoIterativo;
                lblFibonacciRecursiva.Text = "Forma Recursiva: Fibonacci(" + numero + ") = " + resultadoRecursivo;
            }
        }

        // Los primeros n terminos de la serie de Fibonacci
        private String fibonacciSerieRecursiva(int numero)
        {
            String retorno = "";
            
            if (numero == 0)
            {
                retorno = "0";
            }
            else if (numero == 1)
            {
                retorno = "0 1";
            }
            else
            {
                retorno = fibonacciSerieRecursiva(numero - 1) + " " + fibonacciRecursivo(numero);
            }
            return retorno;
        }

        private void btnSerie_Click(object sender, EventArgs e)
        {
            int numero;
            // Convertir los valores a float
            try{
                numero = int.Parse(txtSerieNumero.Text);
            } catch
            {
                MessageBox.Show("Debe ingresar un valor");
                return;
            }

             // Validar que los campos no esten vacios
            if (txtSerieNumero.Text == "")
            {
                MessageBox.Show("Debe ingresar un valor");
            }
            else if (int.Parse(txtSerieNumero.Text) <= 0)
            {
                MessageBox.Show("El numero debe ser mayor a 0");
            }
            else
            {
                // Mostrar el resultado
                lblSerieNumero.Text = "Los " + numero + " primeros términos de la Serie de Fibonacci son: ";
                lblSerieSerie.Text = fibonacciSerieRecursiva(numero-1);
            }   
        }
    }
}