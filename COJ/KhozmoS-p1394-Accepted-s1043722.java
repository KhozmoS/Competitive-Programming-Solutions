import java.math.BigInteger;
import java.util.Scanner;



/**
 *
 * @author Lorenzo
 */
public class JavaApplication2 {

    
    public static void main(String[] args) {
        Scanner joel = new Scanner(System.in);
        BigInteger n;
        BigInteger N;
        BigInteger two = new BigInteger("2");
        BigInteger one = new BigInteger("1");
        BigInteger end = new BigInteger("-1");
        int t = 0;
        
        while(true){
     
        n = joel.nextBigInteger();
        
        if(n.equals(end))
            break;
        
        if(t > 0)
          System.out.println();
        
        t++;
        N = n;
        n = n.add(one);
        n = n.divide(two);
        
        System.out.println("f(" + N + ") = " + n);
        
    
        }
    }
}