
import java.math.BigInteger;
import java.util.Scanner;


public class JavaApplication2 {

    
    public static void main(String[] args) {
       Scanner joel = new Scanner(System.in);
       int t = joel.nextInt();
       
       BigInteger N = new BigInteger("0");; 
       //BigInteger once = new BigInteger("11");
       BigInteger sum = new BigInteger("0");
       while(t > 0)
       {
           N = joel.nextBigInteger();
           sum = sum.add(N);
           t--;
       }
       System.out.println(sum);
    }
}