
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;



public class a {
   static int cont = 0;
	static boolean visitar [];
	static LinkedList<Integer> list[];
	static int n ;
        
	public static void main (String args [] ) throws IOException {
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		while(true){
			boolean flag = true ;
			String s = br.readLine();
				
		    StringTokenizer token= new StringTokenizer(s);
		     n = Integer.parseInt(token.nextToken());
		    int v = Integer.parseInt(token.nextToken());
		    
		    if(n==0 && v==0)break;
		    
		    list = new LinkedList [n+1];
		    visitar = new boolean [n+1];
		    for (int x = 0; x < list.length; x++) {
				list[x] = new LinkedList<Integer>();
			}
			
		    while(v-->0){
		    	
		    	s = br.readLine();
		    	token = new StringTokenizer(s);
		    	
		    	int x  = Integer.parseInt(token.nextToken());
		    	int y = Integer.parseInt(token.nextToken());
		    	int saber = Integer.parseInt(token.nextToken());
		    	
		    	list[x].add(y);
		    	
		    	if(saber==2){
		    	list[y].add(x);
		    	}
		    	
		    }
		    
		    int nodos [] = new int [n];
		    for (int x = 0; x < nodos.length; x++) {
				nodos[x] = x+1;
			}
		    
		    
		    for (int x = 0; x < nodos.length; x++) {
			cont = 0; 
                        
                        dfs(nodos[x]);
                           
                           Arrays.fill(visitar,false);
			   if(cont!=n){
				   flag  = false;
				   break;
			   }
			 			
                                 
			}
		    
		   		       
		    if(flag)
		    	bw.append("1\n");
		    else
		    	bw.append("0\n");
		   
		}
		bw.close();
	
	}
	  static  void  dfs (int nodo){
		  cont++;		 
		  visitar[nodo] = true;
		  	  for (int x = 0; x < list[nodo].size(); x++) {
				
                              int newnodo = list[nodo].get(x);
                              if(!visitar[newnodo])
                                  dfs(newnodo); 
			    }
			    
			
		  }
		  		
	  
}