
import java.util.Scanner;


/**
 *
 * @author Ray
 */
public class JavaApplication2 {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        double x = s.nextDouble();
        double y = s.nextDouble();
        //int a = s.nextInt();
        while (x != 0 || y != 0) {
            if (x == 0 || y == 0) {
                System.out.println("AXIS");
               
            }
            if (x > 0 && y > 0) {
                System.out.println("Q1");

            }
            if (y > 0 && x < 0) {
                System.out.println("Q2");

            }
            if (y < 0 && x < 0) {
                System.out.println("Q3");

            }
            if (y < 0 && x > 0) {
                System.out.println("Q4");

            }
            x = s.nextDouble();
            y = s.nextDouble();
        }
System.out.println("AXIS");
    }

}