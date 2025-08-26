package codeptit;

import java.util.Scanner;

public class J02022_Soxacach {
    static int n;

    static void Try(int i, int[] a, boolean[] vs) {
        if (i == n) {
            for (int j = 0; j < n; j++)
                System.out.print(a[j]);
            System.out.println();
            return;
        }
        for (int j = 1; j <= n; j++) {
            if (!vs[j] && (i == 0 || (i > 0 && Math.abs(j - a[i - 1]) != 1))) {
                vs[j] = true;
                a[i] = j;
                Try(i + 1, a, vs);
                vs[j] = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            n = sc.nextInt();
            int[] a = new int[n];
            boolean[] vs = new boolean[n + 1];
            Try(0, a, vs);
        }
    }
}
