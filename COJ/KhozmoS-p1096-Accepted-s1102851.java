import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Coj1 {

    static ArrayList<ArrayList<Integer>> list;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int casos = in.nextInt();
        while (casos-- > 0) {
            int n = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            list = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                ArrayList<Integer> al=new ArrayList<>();
                list.add(al);
            }
            while (b-- > 0) {
                list.get(in.nextInt()-1).add(in.nextInt()-1);
            }
            boolean[] m = new boolean[n];
            int cont = 0;
            while (c-- > 0) {
                int temp = in.nextInt()-1;
                if (!m[temp]) {
                    Queue<Integer> cola = new LinkedList<>();
                    m[temp] = true;
                   
                    cola.offer(temp);
                    while (!cola.isEmpty()) {
                        int t = cola.remove();
                        cont++;
                        for (int i : list.get(t)) {
                            if (!m[i]) {
                                m[i] = true;
                               
                                cola.offer(i);
                            }
                        }
                    }
                }
            }
            System.out.println(cont);
        }
    }

}