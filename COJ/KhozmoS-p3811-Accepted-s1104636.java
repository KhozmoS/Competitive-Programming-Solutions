import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Ray
 */
public class JavaApplication2 {
    static int [] ar = new int [3000];
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        int n , x;
        n = s.nextInt();
        x = s.nextInt();
        for(int i = 0 ; i < n ; i++) ar[i] = s.nextInt();
        boolean flag = false;
        for(int i = 0 ; i < n ; i++)
            for(int j = i + 1 ; j < n ; j++)
                for(int k = j + 1 ; k < n ; k++)
                    if((ar[i] ^ ar[j] ^ ar[k]) == x)
                        flag = true;
        
        if(flag) System.out.println("YES");
        else System.out.println("NO");
    }

}
