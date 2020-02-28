import java.util.Scanner;

public class LemonadeStand {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int cas = leer.nextInt(), pl, ps, d, l, s, resto, copa, pl1, ps1, cantSugar;
        long suma;
        int max = Integer.MAX_VALUE;
        for (int i = 0; i < cas; i++) {
            suma = 0;
            pl = max;
            ps = max;
            d = leer.nextInt();
            l = leer.nextInt();
            s = leer.nextInt();
            resto = 0;
            for (int j = 0; j < d; j++) {
                copa = leer.nextInt();
                pl1 = leer.nextInt();
                ps1 = leer.nextInt();
                pl = Math.min(pl, pl1);
                ps = Math.min(ps, ps1);
                suma += copa * l * pl;
                cantSugar = copa * s;
                if (resto >= cantSugar) {
                    resto -= cantSugar;
                } else {
                    cantSugar -= resto;
                    suma += ps * (cantSugar / 80);
                    resto = (80 - (cantSugar % 80)) % 80;
                    if (resto > 0) {
                        suma += ps;
                    }
                }
            }
            System.out.println(suma);
        }
    }
}
