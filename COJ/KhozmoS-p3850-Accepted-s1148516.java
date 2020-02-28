import java.util.Scanner;

public class javaapplication7 {

    static long p;

    static long phi(long m) {
        long res = 1;
        for (p = 2; p * p <= m; ++p) {
            if (m % p == 0) {
                res *= p - 1;
                m /= p;
                while (m % p == 0) {
                    res *= p;
                    m /= p;
                }
            }
        }
        if (m > 1) {
            res *= m - 1;
        }
        return res;
    }

    static long expmod(long b, long e, long m) {
        long res = 1;
        while (e != 0) {
            if ((e & 1) != 0) {
                res = (res * b) % m;
            }
            e /= 2;
            b = (b * b) % m;
        }
        return res;
    }

    static long expo_trunc(long n) {
        return n < 4 ? n < 3 ? n : 9 : 100000;
    }

    static long expo_mod_m(long n, long m) {
        if (m == 1) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        long m2 = phi(m), e = expo_trunc(n - 1);
        if (e == 100000) {
            e = m2 + expo_mod_m(n - 1, m2);
        }
        return expmod(n, e, m);
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int b = s.nextInt();
        System.out.println(expo_mod_m(a, b));

    }

} 