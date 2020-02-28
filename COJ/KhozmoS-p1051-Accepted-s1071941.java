import java.util.Scanner;

/**
 *
 * @author Abel
 */
public class JavaApplication10 {
    public static void main(String[] args) {
      Scanner joel = new Scanner(System.in);
      
      int n; int sum = 0;
      n = joel.nextInt();
      for(int i = 0 ; i < n ; i += 3)
        sum++;
      
      System.out.println(n - sum);
    }
    
}
