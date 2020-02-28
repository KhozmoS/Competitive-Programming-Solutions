import java.math.BigInteger;
import java.util.Scanner;

public class Clase_Practica {

    
    
    public static void main(String[] args) {
     
        int t;
        Scanner joel = new Scanner(System.in);
       BigInteger k = new BigInteger("495");
       BigInteger c = new BigInteger("0"); 
       t = joel.nextInt();
       for(int i = 0 ; i < t ; i++){
       BigInteger n = joel.nextBigInteger();
       if((n.mod(k)).equals(c))
        System.out.println("YES");
       else
        System.out.println("NO");   
       }
    }
    
}
