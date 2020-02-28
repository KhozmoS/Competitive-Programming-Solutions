import java.util.Scanner;

public class AreaDeEstrella {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        double R, n, pi = Math.PI, x, Atri1, Atri2, l;
        while ((R = leer.nextDouble()) != 0 && (n = leer.nextDouble()) != 0) {
            l = R * Math.sqrt(2 * (1 - Math.cos(2 * pi / n)));
            x = Math.sqrt((l * l) / (2 * (1 - Math.cos(pi - 2 * pi / n))));
            Atri1 = R * R * Math.sin(pi - 2 * pi / n) / 2.0;
            Atri2 = x * x * Math.sin(pi - 2 * pi / n) / 2.0;
            System.out.printf("%.7f", n * (Atri1 - Atri2));
            System.out.println();
        }
    }
}