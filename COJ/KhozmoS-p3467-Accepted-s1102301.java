import java.util.Scanner;

/**
 *
 * @author Llull
 */
public class COJ {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner cin =new Scanner(System.in);
       int casos=cin.nextInt();
       for(int i=1;i<=casos;i++){
           float D=cin.nextLong();
           float Aa=cin.nextLong();
           float Ab=cin.nextLong();
           if(Aa>Ab){
           float t=(float)Math.sqrt((2*D)/(Aa-Ab));
           System.out.printf("Case #"+(i)+": "+"%1.2f",+t);
               System.out.println("");
           }else{
               System.out.println("Case #"+(i)+": impossible");
           }
       }
    }
}