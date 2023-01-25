import java.math.BigDecimal;
import java.math.RoundingMode;

public class ConstantesMatematicas {

    // Método para calcular el valor de "e" utilizando la fórmula dada
    public static BigDecimal calcularE(int iteraciones) {
        BigDecimal e = new BigDecimal(1);
        BigDecimal factorial = new BigDecimal(1);

        for (int i = 1; i <= iteraciones; i++) {
            factorial = factorial.multiply(new BigDecimal(i));
            e = e.add(new BigDecimal(1).divide(factorial, 10, RoundingMode.HALF_UP));
        }

        return e;
    }

    // Método para calcular el valor de "PI" utilizando la fórmula dada
    public static BigDecimal calcularPI(int iteraciones) {
        BigDecimal pi = new BigDecimal(0);
        int signo = 1;

        for (int i = 1; i <= iteraciones; i++) {
            pi = pi.add(new BigDecimal(4 * signo).divide(new BigDecimal(2 * i - 1), 10, RoundingMode.HALF_UP));
            signo *= -1;
        }

        return pi;
    }

}