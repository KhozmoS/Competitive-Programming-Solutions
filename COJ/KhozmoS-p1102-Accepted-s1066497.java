import java.math.BigInteger;

import java.util.Scanner;


public class JavaApplication2 {

    
    public static void main(String[] args) {
       Scanner joel = new Scanner(System.in);
       
       BigInteger N; 
       BigInteger once = new BigInteger("11");
       BigInteger zero = new BigInteger("0");
       while(true)
       {
        N = joel.nextBigInteger();
        if(N.equals(zero))
            break;
        
        if(N.mod(once).equals(zero))
          System.out.println(N + " is a multiple of 11.");
        else
          System.out.println(N + " is not a multiple of 11.");
       }
    }
}
