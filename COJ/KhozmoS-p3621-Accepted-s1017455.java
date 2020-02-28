import java.util.Scanner;

public class JavaApplication5 {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int c = leer.nextInt();
        for (int i = 0; i < c; i++) {
            int x1, x2, y1, y2, r1, r2;
            double d;
            x1 = leer.nextInt();
            y1 = leer.nextInt();
            r1 = leer.nextInt();
            x2 = leer.nextInt();
            y2 = leer.nextInt();
            r2 = leer.nextInt();
            d = Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            System.out.println(decision(r1, r2, d));
        }

    }

    public static String decision(double r1, double r2, double d) {
        if (d == 0 && r1 == r2) {
            return "SAME";
        }
        if (d > r1 + r2) {
            return "EXT";
        }
        if (d == r1 + r2) {
            return "TANGENT EXT";
        }
        if (d == Math.abs(r1 - r2)) {
            return "TANGENT INT";
        }

        if (d < Math.abs(r1 - r2)) {
            return "INT";
        }
        return "SEC";
    }
}
