
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Ray
 */
public class JavaApplication2 {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        BigInteger [] ans  = new BigInteger[105];
        BigInteger [] TA  = new BigInteger[105];
        ans[0] = new BigInteger("1");
        ans[1] = new BigInteger("1");
        ans[2] = new BigInteger("2");
        TA[1] = ans[1];
        TA[0] = new BigInteger("1");
        TA[2] = new BigInteger("3");
        for(int i = 3 ; i < 105 ; i++)
        {
          BigInteger x = ans[i - 1];
          x = x.add(ans[i - 2]);
          ans[i] = x;
          TA[i] = x;
          TA[i] = TA[i].add(TA[i - 1]);
        }
        int t = s.nextInt();
        while(t > 0)
        {
            int i = s.nextInt();
            System.out.print(ans[i - 1].toString() + " ");
            if(i == 1)
            System.out.println(ans[i - 1].toString());    
            else if(i == 2)
            System.out.println(2);        
            else
            System.out.println(TA[i - 1].add(BigInteger.ONE).toString());
            t--;
        }
    }

}
