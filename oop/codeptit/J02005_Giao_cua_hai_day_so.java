package codeptit;

import java.util.Scanner;

public class J02005_Giao_cua_hai_day_so {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();

        boolean[] inA = new boolean[1000];
        boolean[] inB = new boolean[1000];

        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            inA[x] = true;
        }

        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            inB[x] = true;
        }

        for (int i = 1; i < 1000; i++) {
            if (inA[i] && inB[i]) {
                System.out.print(i + " ");
            }
        }
    }
}