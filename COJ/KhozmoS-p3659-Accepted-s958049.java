import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author estudiante
 */
public class Factorial {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        BigInteger f = new BigInteger("1");
        BigInteger sol[] = new BigInteger[50];
        int cont = 1;
        sol[1] = f;
        for(int i = 2; i <= 45; i++)
        {
            BigInteger x = new BigInteger(Integer.toString(i));
            f = f.multiply(x);
            //System.out.print(i + " ");
            //System.out.println(f);
            sol[i] = f;
        }
        
        int t = in.nextInt();
        for(int i = 0; i < t; i++)
        {
            int n = in.nextInt();
            System.out.println(sol[n].toString());
            
        }
    }
}
