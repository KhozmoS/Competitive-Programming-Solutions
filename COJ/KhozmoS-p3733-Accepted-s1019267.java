import java.util.ArrayDeque;
import java.util.PriorityQueue;
import java.util.Scanner;

public class ConectaLasIslas {

    static char[][] islands = new char[1000][1000];
    static int[] padre = new int[2501];
    static arista[] islas = new arista[2501];
    static PriorityQueue<arista> kruskal = new PriorityQueue<>();
    static int con = 0, xx, yy, r, col, pos;
    static int[] movx = {1, -1, 0, 0};
    static int[] movy = {0, 0, 1, -1};
    static ArrayDeque<Integer> cola = new ArrayDeque<>();

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        int t = leer.nextInt();
        String g;
        for (int i = 0; i < t; i++) {
            pos = 0;
            con = 0;
            r = leer.nextInt();
            col = leer.nextInt();
            for (int j = 0; j < r; j++) {
                g = leer.next();
                for (int k = 0; k < g.length(); k++) {
                    islands[j][k] = g.charAt(k);
                }
            }
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < col; k++) {
                    if (islands[j][k] == 'X') {
                        BFS(j, k);
                        con++;
                    }
                }
            }
            for (int j = 0; j < con; j++) {
                padre[j] = j;
            }
            int dis;
            kruskal.clear();
            for (int j = 0; j < pos; j++) {
                for (int k = j + 1; k < pos; k++) {
                    if (islas[j].c != islas[k].c) {
                        dis = Math.abs(islas[j].x - islas[k].x) + Math.abs(islas[j].y - islas[k].y) - 1;
                        kruskal.add(new arista(islas[j].c, islas[k].c, dis));
                    }
                }
            }
            arista aux;
            int u, v, suma = 0;
            while (con > 1 && !kruskal.isEmpty()) {
                aux = kruskal.poll();
                u = find(aux.x);
                v = find(aux.y);
                if (u != v) {
                    suma += aux.c;
                    padre[u] = v;
                    con--;
                }
            }
            System.out.println(suma);
        }
    }

    public static int find(int val) {
        if (padre[val] != val) {
            padre[val] = find(padre[val]);
        }
        return padre[val];
    }

    public static void BFS(int x, int y) {
        islas[pos++] = new arista(x, y, con);
        islands[x][y] = '.';
        cola.clear();
        int a, b;
        cola.add(x);
        cola.add(y);
        while (!cola.isEmpty()) {
            a = cola.poll();
            b = cola.poll();
            for (int i = 0; i < 4; i++) {
                xx = a + movx[i];
                yy = b + movy[i];
                if (xx >= 0 && yy >= 0 && xx < r && yy < col) {
                    if (islands[xx][yy] == 'X') {
                        cola.add(xx);
                        cola.add(yy);
                        islas[pos++] = new arista(xx, yy, con);
                        islands[xx][yy] = '.';
                    }
                }
            }
        }
    }

    public static class arista implements Comparable<arista> {

        public int x, y, c;

        public arista(int x, int y, int c) {
            this.x = x;
            this.y = y;
            this.c = c;
        }

        @Override
        public int compareTo(arista o) {
            return this.c - o.c;
        }

    }
}
