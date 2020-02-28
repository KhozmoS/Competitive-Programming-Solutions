import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.BitSet;


public class _3321 {
public static void main(String[] args) throws NumberFormatException, IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	BigInteger mod = new BigInteger("10000000000");
	int n = 1000000;
	BitSet a = new BitSet(n + 1);
	int i = 2, j = 0;
	for (i = 2; i * i <= n; i = i + 1) {
	if (!a.get(i)) {
	for (j = i + i; j <= n; j = j + i) {
	a.set(j);
	}
	}
	}
	
	BigInteger numeros [] = new BigInteger [n+1];
	numeros[1]=BigInteger.ZERO;
	numeros[2]= new BigInteger("2");
	for (int x = 3; x < numeros.length; x++) {
			if(!a.get(x)){
				numeros[x] = (BigInteger.valueOf(x).multiply(numeros[x-1])).remainder(mod);
			}
			else {
				numeros[x]=numeros[x-1].remainder(mod);
			}
	}
	
	int t = Integer.parseInt(br.readLine());
	while(t-->0){
		int num = Integer.parseInt(br.readLine());
		
		if(num<=30){
			bw.append(numeros[num]+"\n");
		}
		else {
			String aux = numeros[num]+"";
			
			int x = aux.length();
			int hacer = 10-x;
			String aux1 = "";
			while(hacer-->0){
				aux1+="0";
			}
			bw.append(aux1+aux+"\n");
		}
		
	}
	bw.close();
	
}
}