import java.util.Arrays;
import java.util.Scanner;

public class Anti_lenzano {

    public static char[][][] array;

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int a = leer.nextInt();
        int b = leer.nextInt();
        int[] array = new int[a];
        for (int i = 0; i < a; i++) {
            array[i] = leer.nextInt();
        }
        Arrays.sort(array);
        int mayor = 0;
        for (int i = 0; i < a; i++) {
            int cont = 0;
            for (int j = i; j < a; j++) {
                if (array[j] <= array[i] + b) {
                    cont++;
                } else {
                    j = a;
                }
            }
            if (cont > mayor) {
                mayor = cont;
            }
        }
        System.out.println(mayor);
    }

}