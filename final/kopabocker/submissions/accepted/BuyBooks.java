import java.util.*;
import java.io.*;

public class BuyBooks {
    static int [][] store;
    static int [] porto;
    static int min = 2000000;
    static int N, M;

    public static void rek(int shop, LinkedList <Integer> shops) {
        if(shop==M) {
            goGreedy(shops);
            return;
        }
        shops.addLast(shop);
        rek(shop+1, shops);
        shops.removeLast();
        rek(shop+1, shops);
    }

    public static void goGreedy(LinkedList <Integer> shops) {
        int cost = 0;
        for(int shop : shops) cost += porto[shop];
        for(int i = 1; i<=N; i++) {
            int best = 11000;
            for(int shop : shops) {
                if(store[i][shop]!=-1 && store[i][shop]<best) {
                    best = store[i][shop];
                }
            }

            if(best<11000) cost += best;
            else return;
        }
        if(cost<min) min = cost;
    }

    public static void main(String [] klein) throws FileNotFoundException {
        Scanner scan = new Scanner(System.in);
        N = scan.nextInt();
        M = scan.nextInt();
        store = new int [N+1][M];
        for(int i = 0; i<M; i++)
            for(int j = 1; j<=N; j++)
                store[j][i] = -1;
        porto = new int [M];
        for(int i = 0; i<M; i++) {
            int K = scan.nextInt();
            porto[i] = scan.nextInt();
            for(int j = 0; j<K; j++) {
                store[scan.nextInt()][i] = scan.nextInt();
            }
        }

        rek(0, new LinkedList <Integer> ());
        System.out.println(min);
    }
}
