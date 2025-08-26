package codeptit;

import java.util.Scanner;

public class J02020_Lietketohop1 {
    static int[] result;
    static int cnt = 0;
    static int n, k;

    static void Try(int i, int start) {
        for (int j = start; j <= n - k + i; j++) {
            result[i] = j;
            if (i == k) {
                for (int t = 1; t <= k; t++) {
                    System.out.print(result[t] + " ");
                }
                System.out.println();
                cnt++;
            } else {
                Try(i + 1, j + 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        result = new int[k + 1];
        Try(1, 1);
        System.out.printf("Tong cong co %d to hop", cnt);
    }
}
