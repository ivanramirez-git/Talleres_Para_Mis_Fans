import java.util.Scanner;

public class App {
    /*
     * Create a program that has 7 smart functions and each
     * function accepts 3 integer data and return the calculated
     * value.
     * Those functions can calculate the sum, difference,
     * product, quotient, average of the given data. Other
     * functions can return the highest and lowest given data.
     * 
     * Turn in your the .java file, screenshots of your source code
     * and the program output in here.
     */
    // sum
    public static int sum(int a, int b, int c) {
        return a + b + c;
    }

    // difference
    public static int difference(int a, int b, int c) {
        return a - b - c;
    }

    // product
    public static int product(int a, int b, int c) {
        return a * b * c;
    }

    // quotient
    public static double quotient(int a, int b, int c) {
        if (a == 0 || b == 0 || c == 0) {
            return 0;
        }
        double result = (double) a / b / c;
        return result;
    }

    // average
    public static double average(int a, int b, int c) {
        double average = (a + b + c) / 3.0;
        return average;
    }

    // highest
    public static int highest(int a, int b, int c) {
        int highest = a;
        if (b > highest) {
            highest = b;
        }
        if (c > highest) {
            highest = c;
        }
        return highest;
    }

    // lowest
    public static int lowest(int a, int b, int c) {
        int lowest = a;
        if (b < lowest) {
            lowest = b;
        }
        if (c < lowest) {
            lowest = c;
        }
        return lowest;
    }

    public static void main(String[] args) throws Exception {
        // scanner
        Scanner sc = new Scanner(System.in);

        // data
        int a, b, c;

        // input
        System.out.print("Enter the first number: ");
        a = sc.nextInt();
        System.out.print("Enter the second number: ");
        b = sc.nextInt();
        System.out.print("Enter the third number: ");
        c = sc.nextInt();

        // menu
        int option;
        do {
            System.out.println("1. Sum");
            System.out.println("2. Difference");
            System.out.println("3. Product");
            System.out.println("4. Quotient");
            System.out.println("5. Average");
            System.out.println("6. Highest");
            System.out.println("7. Lowest");
            System.out.println("0. Exit");
            System.out.print("Enter your option: ");
            option = sc.nextInt();
            System.out.println();

            // switch
            switch (option) {
                case 1:
                    System.out.println("The sum of " + a + ", " + b + ", " + c + " is " + sum(a, b, c));
                    break;
                case 2:
                    System.out.println("The difference of " + a + ", " + b + ", " + c + " is " + difference(a, b, c));
                    break;
                case 3:
                    System.out.println("The product of " + a + ", " + b + ", " + c + " is " + product(a, b, c));
                    break;
                case 4:
                    System.out.println("The quotient of " + a + ", " + b + ", " + c + " is " + quotient(a, b, c));
                    break;
                case 5:
                    System.out.println("The average of " + a + ", " + b + ", " + c + " is " + average(a, b, c));
                    break;
                case 6:
                    System.out.println("The highest of " + a + ", " + b + ", " + c + " is " + highest(a, b, c));
                    break;
                case 7:
                    System.out.println("The lowest of " + a + ", " + b + ", " + c + " is " + lowest(a, b, c));
                    break;
                case 0:
                    System.out.println("Bye!");
                    break;
                default:
                    System.out.println("Invalid option!");
                    break;
            }
            System.out.println();
        } while (option != 0);

        // close scanner
        sc.close();

    }

}
