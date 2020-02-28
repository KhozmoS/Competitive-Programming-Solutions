import java.util.Scanner;


public class COJ3541 {

    public static String Change(String a){
    String ret="";    
    for(int i=0;i<a.length();i++){  
    if(a.charAt(i)>=65 && a.charAt(i)<=90){
    ret+=(char) (a.charAt(i)+32);
    }
    else if(a.charAt(i)>=97 && a.charAt(i)<=122)    
    ret+=(char) (a.charAt(i)-32);
    else 
        ret+=a.charAt(i);
        }
    return ret;
    
    }
   
    public static void main(String[] args) {
    Scanner s=new Scanner(System.in);
    int x=s.nextInt();
    String arr []=new String[x];
    s.nextLine();
    for(int i=0;i<x;i++){
    arr[i]=s.nextLine();
    
    }
    for(int i=0;i<x;i++){
    System.out.println(Change(arr[i]));
    }
    }
    
}
