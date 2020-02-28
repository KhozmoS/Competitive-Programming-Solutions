import java.util.Scanner;

public class AreaDeUnPoligono {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int a = leer.nextInt(), x;
        for (int i = 0; i < a; i++) {
            x = leer.nextInt();
            System.out.println(3 * (x * x) + 2);
        }
    }

}
