import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int z, ac = 0, v = 0, ac1 = 0;
        Scanner u = new Scanner(System.in);
        do {
            System.out.println("Ingrese dimensión");
            z = u.nextInt();
        } while (z < 1 || 2 % 2 == 1);

        int mat[][] = new int[z][z];
        for (int f = 0; f < mat.length; f++) {
            for (int c = 0; c < mat.length; c++) {
                System.out.println("Ingrese dato a la matriz" + f + c);
                mat[f][c] = u.nextInt();
                ac += mat[f][c];
            }
        }

        for (int y = 1; y < ac; y++) {
            if (ac % y == 0) {
                ac1 += y;
            }
        }

        if (ac1 == ac) {
            for (int f = 0; f < mat.length; f++) {
                for (int c = 0; c < mat.length; c++) {
                    mat[f][c] = 0;
                }
            }
            System.out.println("El numero es perfecto] " + ac);
        } else {
            System.out.println("El numero no es perfecto] " + ac);
        }
        System.out.println("Los resultados son");
        for (int f = 0; f < mat.length; f++) {
            for (int c = 0; c < mat.length; c++) {
                System.out.println(mat[f][c]);
            }
        }

        // Sumar 2 matrices
        int mat1[][] = new int[z][z];
        for (int f = 0; f < mat1.length; f++) {
            for (int c = 0; c < mat1.length; c++) {
                System.out.println("Ingrese dato a la matriz" + f + c);
                mat1[f][c] = u.nextInt();
                ac += mat1[f][c];
            }
        }

        for (int f = 0; f < mat1.length; f++) {
            for (int c = 0; c < mat1.length; c++) {
                mat[f][c] += mat1[f][c];
            }
        }

        System.out.println("Los resultados son");
        for (int f = 0; f < mat.length; f++) {
            for (int c = 0; c < mat.length; c++) {
                System.out.println(mat[f][c]);
            }
        }

    }
}
