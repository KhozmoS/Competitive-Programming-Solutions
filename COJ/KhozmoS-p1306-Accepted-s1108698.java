/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package div.pkg6;
import java.math.BigInteger;
import java.util.Scanner;
/**
 *
 * @author Familia
 */
public class Div6 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner z=new Scanner(System.in);
        BigInteger a=new BigInteger("0");
        BigInteger b=new BigInteger("4");
        BigInteger c=new BigInteger("0");
        int s=0;
        s=z.nextInt();
        for(int i=0;i<s;i++){
        a=z.nextBigInteger();
        if(a.mod(b).equals(c))
          System.out.println("YES");
        else
          System.out.println("NO");
     
        }
        // TODO code application logic here
    }
    
}
