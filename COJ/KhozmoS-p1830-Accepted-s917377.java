import java.util.Scanner;

public class Guille {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int a = leer.nextInt();
        a++;
        int u = leer.nextInt();
        int q = leer.nextInt();
        long[] array = new long[a];
        for (int i = 0; i < u; i++) {
            int pos = leer.nextInt();
            int val = leer.nextInt();
            if (pos + 1 < a) {
                array[pos + 1] += val;
            }
            if (pos - 1 >= 0) {
                array[pos - 1] += val;
            }
            if (pos >= 0 && pos < a) {
                array[pos] += val + 1;
            }
        }
        for (int i = 1; i < a; i++) {
            array[i] += array[i - 1];

        }
        for (int i = 0; i < q; i++) {
            int x = leer.nextInt();
            int y = leer.nextInt();
            System.out.println((array[y] - array[x - 1])%10000);

        }
    }

}
