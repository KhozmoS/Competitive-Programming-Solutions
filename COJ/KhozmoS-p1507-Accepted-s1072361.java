
import java.util.Scanner;


public class Tarea {

    
    public static void main(String[] args) {
    Scanner tarea = new Scanner(System.in);
    int n = tarea.nextInt();
    for(int t = 0 ; t < n ; t++)
    {
      int k = tarea.nextInt();  
      String [] ar = new String[55];   
      for(int j = 0 ; j < k ; j++)
      ar[j] = tarea.next();
      
      for(int i = 0 ; i < k - 1 ; i++)     
       for(int j = i ; j < k ; j++)
       {
         if(comparar(ar[i] , ar[j]))
         {
          String aux = ar[i];
          ar[i] = ar[j];
          ar[j] = aux;
         }   
       }
     for(int i = 0 ; i < k ; i++)
      System.out.print(ar[i] + " ");
     
     System.out.println();
    }
    }
    public static boolean comparar(String a , String b)
    {
       char [] abc = {'A' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K'};
       char [] abc2 = {'S' , 'H' , 'C' , 'D'};
       
       int fa = 0;
       int fb = 0;
       int sa = 0;
       int sb = 0;
       for(int i = 0 ; i < 13 ; i++)
        if(abc[i] == a.charAt(0))
         fa = i;   
       for(int i = 0 ; i < 13 ; i++)
        if(abc[i] == b.charAt(0))
         fb = i;   
       for(int i = 0 ; i < 4 ; i++) 
       if(abc2[i] == a.charAt(1))
         sa = i;  
       for(int i = 0 ; i < 4 ; i++) 
       if(abc2[i] == b.charAt(1))
         sb = i;
       
      if(fa == fb)
       {
        if(sa < sb)
          return false;  
       }
      if(fa < fb)
          return false;
      
      return true;
      
      
      
    }       
}
