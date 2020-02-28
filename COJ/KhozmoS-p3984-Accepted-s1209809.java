import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/**
 *
 * @author proyecto
 */
public class A {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String s = br.readLine();
        int max = 0 ;
            
                s = 'a'+s;    
         
        int cont  = 0;
        int cont1 = 0 ;
                
          String salida = "";
        
        
        for (int x = 1; x < s.length(); x++) {
            
           
            if(s.charAt(x)=='('){
           
            
            
            if(cont1>max){
            max = cont1;
            salida = s.charAt(x-1)+"";
           
            }
            
            
             cont1=0;
             cont++;
            
            }
            
            else if(s.charAt(x)==')'){
                
                if(cont>max){
                max = cont;
                salida = s.charAt(x-1)+"";
              
                
                }
                
                
            cont1++;
            
                cont = 0;      
            
            
            }
        }
        
        
        if(cont>max){
        bw.append(cont + " (");
        }
        else if(cont1>max){
        bw.append(cont1+" )");
        }
        
        
        else
        bw.append(max+ " " + salida);
        bw.close();
    }
    
}
