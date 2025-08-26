package codeptit;

import java.util.Scanner;

public class J02021_Lietketohop2 {
    static int n, k;
    static int[] result;
    static int cnt = 0;

    static void Try(int i, int start) {
        for (int j = start; j <= n - k + i; j++) {
            result[i] = j;
            if (i == k) {
                for (int t = 1; t <= k; t++) {
                    System.out.print(result[t]);
                }
                System.out.print(" ");
                cnt++;
            } else
                Try(i + 1, j + 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        result = new int[k + 1];
        Try(1, 1);
        System.out.printf("%nTong cong co %d to hop", cnt);
    }
}
