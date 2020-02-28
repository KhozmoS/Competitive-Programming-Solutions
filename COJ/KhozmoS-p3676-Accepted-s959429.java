import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Anita
 */
public class Coj {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int i = 1; i <= t; i++){
            System.out.print("Case " + i + ": ");
            String cad = in.next();
            BigInteger n = new BigInteger(cad);
            BigInteger DOS = new BigInteger("2");
            BigInteger CINCO = new BigInteger("5");
            //n = n.divide(CINCO);
            BigInteger arr[] = new BigInteger[1000];
            arr = n.divideAndRemainder(CINCO);


            System.out.print(arr[0].toString());

            if(arr[1].toString().equals("0"))System.out.println();
            else{
                arr[1] = arr[1].multiply(DOS);
                System.out.println("," + arr[1].toString());
            }
        }
    }
    
}