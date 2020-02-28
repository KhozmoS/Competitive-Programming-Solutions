/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author mpc-tlj
 */
import java.util.Scanner;
import java.math.BigInteger;

public class JavaApplication3 {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        BigInteger val1,val2,val3;
        while(in.hasNext())
        {
            val1 = in.nextBigInteger();
            val2 = in.nextBigInteger();
            val3 = in.nextBigInteger();
            System.out.println(val2.modPow(val1, val3));
        }
        
    }
    
}
