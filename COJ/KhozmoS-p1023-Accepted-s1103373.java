
import java.util.Scanner;

/**
 *
 * @author Guille
 */
public class COJ_problems {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double [] a = new double[12];
        double total = 0;
        double x = 0.0;
        for (int i = 0; i < 12; i++) {
           // a[i] =
              x = in.nextDouble();
              total += x;
        }
        System.out.printf("$%.2f%n", total / 12);
    }
}