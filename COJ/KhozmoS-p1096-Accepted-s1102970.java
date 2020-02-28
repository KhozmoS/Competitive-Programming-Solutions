import java.util.Scanner;


public class COJ {
    static boolean [] [] matriz;
    static int cont=0;
    static boolean  tumbados [];
    
    public static void Tumbar(int pos){
        if(!tumbados[pos]){
            tumbados[pos]=true;
        for(int i=0;i<matriz.length;i++){
            if(matriz[pos][i] && !tumbados[i]){
                cont++;
                matriz [pos][i]=false;
                
                Tumbar(i);
                
            }
        }
        
    }
    
    }


    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        
        for (int i = 0; i < n; i++) {
        int cant=s.nextInt();
        int rel=s.nextInt();
        int tumbarinicial=s.nextInt();
        matriz =new boolean [cant][cant];
        tumbados=new boolean[cant];
        for(int p=0;p<cant;p++){
            tumbados[p]=false;
        }
        for(int j=0;j<rel;j++){
        matriz[s.nextInt()-1][s.nextInt()-1]=true;
        }
        for(int k=0;k<tumbarinicial;k++){
            int u=s.nextInt();
            if(!tumbados[u-1]){
            Tumbar(u-1);
            cont++;
            }
        }
        
            System.out.println(cont);
            cont=0;
        }
        
        }
       
        
    }