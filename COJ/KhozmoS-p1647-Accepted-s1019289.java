import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Fire {

    public static boolean[][] valid;
    public static Queue<Integer> cola;

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        cola = new LinkedList<Integer>();
        int m = leer.nextInt();
        int n = leer.nextInt();
        valid = new boolean[m][n];

        char[] aux;
        int jx = 0, jy = 0;
        for (int i = 0; i < m; i++) {
            String g = leer.next();
            aux = g.toCharArray();
            for (int j = 0; j < n; j++) {
                if (aux[j] == '.') {
                    valid[i][j] = true;
                }
                if (aux[j] == 'F') {
                    cola.add(i);
                    cola.add(j);
                    cola.add(0);
                    cola.add(0);
                }
                if (aux[j] == 'J') {
                    jx = i;
                    jy = j;
                }
            }

        }
        cola.add(jx);
        cola.add(jy);
        cola.add(0);
        cola.add(1);
        int res = bfs(m, n);
        if (res == -1) {
            System.out.println("IMPOSSIBLE");
        } else {
            System.out.println(res);
        }
    }

    public static int bfs(int m, int n) {
        int[] movx = {1, -1, 0, 0};
        int[] movy = {0, 0, 1, -1};
        while (!cola.isEmpty()) {
            int a = cola.poll();
            int b = cola.poll();
            int c = cola.poll();
            int tipo = cola.poll();
            for (int i = 0; i < 4; i++) {
                int xx = a + movx[i];
                int yy = b + movy[i];
                if (xx >= 0 && yy >= 0 && xx < m && yy < n) {
                    if (valid[xx][yy]) {
                        valid[xx][yy] = false;
                        cola.add(xx);
                        cola.add(yy);
                        cola.add(c + 1);
                        cola.add(tipo);
                    }
                } else {
                    if (tipo == 1) {
                        c++;
                        return c;
                    }
                }

            }
        }
        return -1;
    }
}